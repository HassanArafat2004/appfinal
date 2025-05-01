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
