<<<<<<< HEAD
#include "signup.h"
#include "ui_signup.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_2_clicked()
{
    QString Username = ui->Username_box->text();
    QString Password = ui->Password_box->text();
    if (Username.isEmpty() || Password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please enter both username and password!");
        return;
    }
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Sign Up", "Could not open user file.");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 2 && parts[0] == Username) {
            QMessageBox::warning(this, "Sign Up", "Username already exists!");
            file.close();
            return;
        }
    }
    file.close();
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Sign Up", "Could not open user file for writing.");
        return;
    }
    QTextStream out(&file);
    out << Username << " " << Password << "\n";
    file.close();
    QMessageBox::information(this, "Sign Up", "Account created successfully!");
    if (parentWidget()) {
        MainWindow* mw = qobject_cast<MainWindow*>(parentWidget());
        if (mw) mw->users.clear(), mw->loadUsersFromFile();
    }
    this->hide();
    parentWidget()->show();
}

void signup::on_goToSignInButton_clicked()
{
    this->hide();
    parentWidget()->show();
}
=======
#include "signup.h"
#include "ui_signup.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_2_clicked()
{
    QString Username = ui->Username_box->text();
    QString Password = ui->Password_box->text();

    if (Username.isEmpty() || Password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please enter both username and password!");
        return;
    }

    QFile file("logindetails.txt");
    file.open(QIODevice::Append | QIODevice::Text);

    QTextStream out(&file);
    out << Username << " " << Password << "\n";

    file.close();

    QMessageBox::information(this, "Sign Up", "Account created successfully!");
    this->hide();
    parentWidget()->show();
}

void signup::on_goToSignInButton_clicked()
{
    this->hide();
    parentWidget()->show();
}
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
