#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "adminwindow.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QInputDialog>
#include <QSettings>

QString getLoginFilePath();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Login");
    showMaximized();

    signupWindow = nullptr;
    adminWindow = nullptr;
    dashboardWindow = nullptr;
    loadUsersFromFile();

    ui->goToSignupButton->setVisible(true);
    
    connect(ui->adminLoginLink, &QLabel::linkActivated, this, [=]() {
        bool ok;
        QString adminCode = QInputDialog::getText(this, "Admin Access", 
                                              "Enter admin credentials:", 
                                              QLineEdit::Password, "", &ok);
        if (ok && adminCode == "admin") {
            ui->Username_box->setText("admin");
            ui->Password_box->setFocus();
            QMessageBox::information(this, "Admin Access", "Admin login activated. Please enter admin password to proceed.");
        }
    });

    connect(ui->goToSignupButton, &QPushButton::clicked, this, [=]() {
        if (!signupWindow) {
            signupWindow = new signup(this);
        }
        signupWindow->show();
        signupWindow->raise();
        signupWindow->activateWindow();
        this->hide();
    });

    connect(ui->Username_box, &QLineEdit::returnPressed, this, &MainWindow::handleUsernameEnter);
    connect(ui->Password_box, &QLineEdit::returnPressed, this, &MainWindow::on_handleLoginButton_clicked);
    connect(ui->handleLoginButton, &QPushButton::clicked, this, &MainWindow::on_handleLoginButton_clicked);

    ui->Username_box->setFocus();
}

void MainWindow::loadUsersFromFile()
{
    QSettings settings("NotesApp", "Paths");
    QString filePath = settings.value("LoginFilePath").toString();
    
    if (filePath.isEmpty()) {
        filePath = getLoginFilePath();
    }
    
    QFile file(filePath);
    
    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Could not create login details file.");
            return;
        }
        QTextStream out(&file);
        out << "admin admin admin@notesapp.com\n";
        out << "omarshawky1 omarshawky1 omarshawky1@gmail.com\n";
        out << "mohamed123 mohamed123 mohamed123@gmail.com\n";
        file.close();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open login details file.");
        return;
    }

    users.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        QString email = "";
        if (parts.size() >= 3) {
            email = parts[2];
        }
        if (parts.size() >= 2) {
            users.append(User(parts[0], parts[1], email));
        }
    }

    file.close();
}

MainWindow::~MainWindow()
{
    if (dashboardWindow) {
        dashboardWindow->deleteLater();
    }
    if (signupWindow) {
        signupWindow->deleteLater();
    }
    if (adminWindow) {
        adminWindow->deleteLater();
    }
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
    QString username = ui->Username_box->text().trimmed();
    QString password = ui->Password_box->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please enter both username and password!");
        return;
    }

    bool found = false;
    
    for (const User &user : users) {
        if (user.username == username && user.password == password) {
            found = true;
            break;
        }
    }
    
    if (!found) {
        QString filePath = getLoginFilePath();
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList parts = line.split(' ');
                if (parts.size() >= 2 && parts[0] == username && parts[1] == password) {
                    found = true;
                    break;
                }
            }
            file.close();
        }
    }

    if (found) {
        if (username == "admin") {
            if (!adminWindow) {
                adminWindow = new AdminWindow(nullptr);
                connect(adminWindow, &QMainWindow::destroyed, this, [this]() {
                    adminWindow = nullptr;
                });
            }
            adminWindow->loadUsersFromFile();
            adminWindow->show();
            adminWindow->raise();
            adminWindow->activateWindow();
            this->hide();
        } else {
            if (dashboardWindow) {
                dashboardWindow->disconnect();
                dashboardWindow->deleteLater();
                dashboardWindow = nullptr;
            }
            
            dashboardWindow = new dashboard(nullptr);
            dashboardWindow->setUsername(username);
            
            dashboardWindow->showDashboard();
            
            this->hide();
        }
    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password!");
        ui->Password_box->clear();
        ui->Password_box->setFocus();
    }
}

void MainWindow::clearLoginFields()
{
    ui->Username_box->clear();
    ui->Password_box->clear();
    ui->Username_box->setFocus();
    ui->goToSignupButton->setVisible(true);
}

