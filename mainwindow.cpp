#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    signupWindow = new signup(this);
    adminWindow = new AdminWindow(this);
    dashboardWindow = nullptr;
    loadUsersFromFile();

    connect(ui->goToSignupButton, &QPushButton::clicked, this, [=]() {
        signupWindow->show();
        this->hide();
    });

    connect(ui->Username_box, &QLineEdit::returnPressed, this, &MainWindow::handleUsernameEnter);
    connect(ui->Password_box, &QLineEdit::returnPressed, this, &MainWindow::on_handleLoginButton_clicked);
}

void MainWindow::loadUsersFromFile()
{
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Could not open login details file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 2) {
            users.append(User(parts[0], parts[1]));
        }
    }

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleUsernameEnter()
{
    QString username = ui->Username_box->text();
    if (!username.isEmpty()) {
        ui->Password_box->setFocus();
    }
}

void MainWindow::on_handleLoginButton_clicked()
{
    QString Username = ui->Username_box->text();
    QString Password = ui->Password_box->text();
    bool found = false;
    for (const User &user : users) {
        if (user.username == Username && user.password == Password) {
            found = true;
            break;
        }
    }
    if (found) {
        if (Username == "admin") {
            adminWindow->show();
            this->hide();
        } else {
            if (dashboardWindow) delete dashboardWindow;
            dashboardWindow = new dashboard();
            dashboardWindow->setUsername(Username);
            dashboardWindow->show();
            this->hide();
        }
    } else {
        QMessageBox::warning(this, "Login", "Username and Password are not correct!");
    }
}

