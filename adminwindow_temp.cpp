#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "reports.h"
#include <QCoreApplication>
#include <QApplication>
#include "mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QCryptographicHash>
#include <QDir>
#include <QDebug>
#include <QStringConverter>

// Forward declaration of the getLoginFilePath function from main.cpp
QString getLoginFilePath();

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
    , adminReportsWindow(nullptr)
{
    ui->setupUi(this);
    
    // Set proper window behavior
    setWindowTitle("Admin Panel");
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    resize(1280, 720);
    setWindowState(Qt::WindowMaximized);
    
    // Remove all manual connections - Qt will automatically connect them based on naming convention
    // The on_buttonName_clicked() methods will be called automatically
    
    qDebug() << "AdminWindow: Constructor complete, loading users";
    loadUsersFromFile();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::loadUsersFromFile()
{
    // Get the login file path
    QString filePath = getLoginFilePath();
    qDebug() << "AdminWindow: Loading users from:" << filePath;
    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open login details file.");
        return;
    }
    
    users.clear();
    QTextStream in(&file);
    qDebug() << "AdminWindow: Loading users from file:";
    
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        QString email = "";
        if (parts.size() >= 3) {
            email = parts[2];
        }
        if (parts.size() >= 2) {
            users.append(User(parts[0], parts[1], email));
            qDebug() << "AdminWindow: Loaded user:" << parts[0] << "Password:" << parts[1] << "Email:" << email;
        }
    }
    file.close();
    
    // Update the table
    ui->usersTable->setRowCount(users.size());
    for (int i = 0; i < users.size(); ++i) {
        ui->usersTable->setItem(i, 0, new QTableWidgetItem(users[i].username));
        ui->usersTable->setItem(i, 1, new QTableWidgetItem(users[i].password));
        ui->usersTable->setItem(i, 2, new QTableWidgetItem(users[i].email));
    }
    
    qDebug() << "AdminWindow: Total users loaded:" << users.size();
}

void AdminWindow::saveUsersToFile()
{
    // Get the login file path
    QString filePath = getLoginFilePath();
    qDebug() << "AdminWindow: Saving users to:" << filePath;
    
    // First verify we can open the file for writing
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", QString("Could not open login details file for writing: %1").arg(file.errorString()));
        return;
    }
    
    qDebug() << "AdminWindow: Saving" << users.size() << "users to file:";
    QTextStream out(&file);
    // Set UTF-8 encoding for the output stream
    out.setEncoding(QStringConverter::Utf8);
    
    for (const User &user : users) {
        out << user.username << " " << user.password;
        if (!user.email.isEmpty()) {
            out << " " << user.email;
        }
        out << "\n";
        qDebug() << "AdminWindow: Saved user:" << user.username << "Password:" << user.password << "Email:" << user.email;
    }
    
    out.flush(); // Ensure all data is written
    file.close();
    qDebug() << "AdminWindow: File closed after saving" << users.size() << "users";
    
    // Verify that the file was written correctly
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        int count = 0;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (!line.trimmed().isEmpty()) {
                count++;
            }
        }
        file.close();
        
        qDebug() << "AdminWindow: Verification - Found" << count << "users in file";
        if (count != users.size()) {
            qDebug() << "AdminWindow: WARNING - User count mismatch after saving!";
            QMessageBox::warning(this, "Warning", 
                "There may be an issue with saving users. Expected " + 
                QString::number(users.size()) + " users but found " + 
                QString::number(count) + " in file.");
        }
    }
    
    // Try to find and notify the MainWindow to reload users
    MainWindow *mainWindow = nullptr;
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        mainWindow = qobject_cast<MainWindow*>(widget);
        if (mainWindow) {
            mainWindow->loadUsersFromFile();
            qDebug() << "AdminWindow: Notified MainWindow to reload users";
            break;
        }
    }
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
        QString email = (ui->usersTable->item(i, 2)) ? ui->usersTable->item(i, 2)->text() : "";
        
        if (!username.isEmpty() && !password.isEmpty()) {
            users.append(User(username, password, email));
        }
    }
    saveUsersToFile();
    QMessageBox::information(this, "Success", "Changes saved successfully.");
}

void AdminWindow::on_deleteUserButton_clicked()
{
    static bool isDeleting = false;
    
    // Prevent multiple calls
    if (isDeleting) {
        qDebug() << "AdminWindow: Delete operation already in progress";
        return;
    }
    
    isDeleting = true;
    
    int currentRow = ui->usersTable->currentRow();
    if (currentRow >= 0) {
        QString username = ui->usersTable->item(currentRow, 0)->text();
        if (username == "admin") {
            QMessageBox::warning(this, "Error", "You cannot delete the admin account.");
            isDeleting = false;
            return;
        }
        
        // Find the user in the users list
        for (int i = 0; i < users.size(); ++i) {
            if (users[i].username == username) {
                users.removeAt(i);
                break;
            }
        }
        
        // Remove from UI
        ui->usersTable->removeRow(currentRow);
        
        // Save changes to file
        saveUsersToFile();
        
        QMessageBox::information(this, "Success", "User deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Please select a user to delete.");
    }
    
    isDeleting = false;
}

void AdminWindow::on_backButton_clicked()
{
    // Since we're now using a null parent, find the MainWindow
    MainWindow *mainWindow = nullptr;
    
    // Try to find the main window
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        mainWindow = qobject_cast<MainWindow*>(widget);
        if (mainWindow) {
            break;
        }
    }
    
    if (mainWindow) {
        mainWindow->clearLoginFields();  // Clear login fields
        mainWindow->show();
        mainWindow->raise();
        mainWindow->activateWindow();
    }
    
    // Instead of hide, we now close this window
    this->close();
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
            this->raise();
            this->activateWindow();
        });
        this->adminReportsWindow->show();
    }
    this->hide();
}

bool AdminWindow::validatePassword(const QString &password)
{
    // Check if password is at least 8 characters and contains at least one number
    if (password.length() < 8) {
        return false;
    }
    
    QRegularExpression containsNumber("\\d");
    return containsNumber.match(password).hasMatch();
}

bool AdminWindow::validateEmail(const QString &email)
{
    if (email.isEmpty()) {
        return true; // Email is optional
    }
    
    // Simple email validation regex
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return emailRegex.match(email).hasMatch();
}

void AdminWindow::on_addUserButton_clicked()
{
    static bool isProcessing = false;
    
    // Prevent multiple calls
    if (isProcessing) {
        qDebug() << "AdminWindow: Add User operation already in progress";
        return;
    }
    
    isProcessing = true;
    
    QString username = ui->usernameInput->text().trimmed();
    QString password = ui->passwordInput->text();
    QString email = ui->emailInput->text().trimmed();
    
    qDebug() << "AdminWindow: Add User button clicked";
    qDebug() << "AdminWindow: Username:" << username;
    qDebug() << "AdminWindow: Password length:" << password.length();
    qDebug() << "AdminWindow: Email:" << email;
    
    // Check if fields are empty
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Error", "Username cannot be empty.");
        isProcessing = false;
        return;
    }
    
    // Check if username already exists
    for (const User &user : users) {
        if (user.username == username) {
            QMessageBox::warning(this, "Error", "Username already exists.");
            isProcessing = false;
            return;
        }
    }
    
    // Validate password
    if (!validatePassword(password)) {
        QMessageBox::warning(this, "Error", "Password must be at least 8 characters long and contain at least one number.");
        isProcessing = false;
        return;
    }
    
    // Validate email if provided
    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Error", "Please enter a valid email address.");
        isProcessing = false;
        return;
    }
    
    // Add the new user
    users.append(User(username, password, email));
    qDebug() << "AdminWindow: User added to memory:" << username;
    
    // Add to table
    int row = ui->usersTable->rowCount();
    ui->usersTable->insertRow(row);
    ui->usersTable->setItem(row, 0, new QTableWidgetItem(username));
    ui->usersTable->setItem(row, 1, new QTableWidgetItem(password));
    ui->usersTable->setItem(row, 2, new QTableWidgetItem(email));
    
    // Save to file
    saveUsersToFile();
    qDebug() << "AdminWindow: User saved to file";
    
    // Create user directory
    QString userDir = QDir::homePath() + "/NotesApp/" + username;
    QDir().mkpath(userDir);
    qDebug() << "AdminWindow: Created directory for user:" << userDir;
    
    // Clear inputs
    ui->usernameInput->clear();
    ui->passwordInput->clear();
    ui->emailInput->clear();
    
    QMessageBox::information(this, "Success", "User added successfully.");
    
    // Debug current users
    qDebug() << "AdminWindow: Current users after adding:";
    for (const User &user : users) {
        qDebug() << "  User:" << user.username << ", Email:" << user.email;
    }
    
    // Try to find and notify the MainWindow to reload users
    MainWindow *mainWindow = nullptr;
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        mainWindow = qobject_cast<MainWindow*>(widget);
        if (mainWindow) {
            mainWindow->loadUsersFromFile();
            qDebug() << "AdminWindow: Notified MainWindow to reload users";
            break;
        }
    }
    
    isProcessing = false;
}

reports *adminReportsWindow = nullptr; 
