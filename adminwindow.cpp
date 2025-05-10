<<<<<<< HEAD
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "reports.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminWindow)
    , adminReportsWindow(nullptr)
{
    ui->setupUi(this);
    loadUsersFromFile();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::loadUsersFromFile()
{
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open login details file.");
        return;
    }
    users.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 2) {
            users.append(User(parts[0], parts[1]));
        }
    }
    file.close();
    ui->usersTable->setRowCount(users.size());
    for (int i = 0; i < users.size(); ++i) {
        ui->usersTable->setItem(i, 0, new QTableWidgetItem(users[i].username));
        ui->usersTable->setItem(i, 1, new QTableWidgetItem(users[i].password));
    }
}

void AdminWindow::saveUsersToFile()
{
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open login details file for writing.");
        return;
    }
    QTextStream out(&file);
    for (const User &user : users) {
        out << user.username << " " << user.password << "\n";
    }
    file.close();
}

void AdminWindow::on_loadUsersButton_clicked()
{
    loadUsersFromFile();
    QMessageBox::information(this, "Success", "Users loaded successfully.");
}

void AdminWindow::on_saveChangesButton_clicked()
{
    users.clear();
    for (int i = 0; i < ui->usersTable->rowCount(); ++i) {
        QString username = ui->usersTable->item(i, 0)->text();
        QString password = ui->usersTable->item(i, 1)->text();
        if (!username.isEmpty() && !password.isEmpty()) {
            users.append(User(username, password));
        }
    }
    saveUsersToFile();
    QMessageBox::information(this, "Success", "Changes saved successfully.");
}

void AdminWindow::on_deleteUserButton_clicked()
{
    int currentRow = ui->usersTable->currentRow();
    if (currentRow >= 0) {
        QString username = ui->usersTable->item(currentRow, 0)->text();
        if (username == "admin") {
            QMessageBox::warning(this, "Error", "You cannot delete the admin account.");
            return;
        }
        for (int i = 0; i < users.size(); ++i) {
            if (users[i].username == username) {
                users.removeAt(i);
                break;
            }
        }
        ui->usersTable->removeRow(currentRow);
        saveUsersToFile();
        QMessageBox::information(this, "Success", "User deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Please select a user to delete.");
    }
}

void AdminWindow::on_backButton_clicked()
{
    this->hide();
    parentWidget()->show();
}

void AdminWindow::on_reportsButton_clicked()
{
    if (this->adminReportsWindow) {
        this->adminReportsWindow->show();
        this->adminReportsWindow->raise();
        this->adminReportsWindow->activateWindow();
    } else {
        this->adminReportsWindow = new reports("admin", true);
        connect(this->adminReportsWindow, &reports::backToDashboardRequested, this, [this]() {
            this->show();
        });
        this->adminReportsWindow->show();
    }
    this->hide();
}

reports *adminReportsWindow = nullptr; 
=======
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidgetItem>

AdminWindow::AdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    loadUsersFromFile();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::loadUsersFromFile()
{
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open login details file.");
        return;
    }

    users.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 2) {
            users.append(User(parts[0], parts[1]));
        }
    }
    file.close();

    ui->usersTable->setRowCount(users.size());
    for (int i = 0; i < users.size(); ++i) {
        ui->usersTable->setItem(i, 0, new QTableWidgetItem(users[i].username));
        ui->usersTable->setItem(i, 1, new QTableWidgetItem(users[i].password));
    }
}

void AdminWindow::saveUsersToFile()
{
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open login details file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const User &user : users) {
        out << user.username << " " << user.password << "\n";
    }
    file.close();
}

void AdminWindow::on_loadUsersButton_clicked()
{
    loadUsersFromFile();
    QMessageBox::information(this, "Success", "Users loaded successfully.");
}

void AdminWindow::on_saveChangesButton_clicked()
{
    users.clear();
    for (int i = 0; i < ui->usersTable->rowCount(); ++i) {
        QString username = ui->usersTable->item(i, 0)->text();
        QString password = ui->usersTable->item(i, 1)->text();
        if (!username.isEmpty() && !password.isEmpty()) {
            users.append(User(username, password));
        }
    }

    saveUsersToFile();
    QMessageBox::information(this, "Success", "Changes saved successfully.");
}

void AdminWindow::on_deleteUserButton_clicked()
{
    int currentRow = ui->usersTable->currentRow();
    if (currentRow >= 0) {
        ui->usersTable->removeRow(currentRow);
        QMessageBox::information(this, "Success", "User deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Please select a user to delete.");
    }
}

void AdminWindow::on_backButton_clicked()
{
    this->hide();
    parentWidget()->show();
} 
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
