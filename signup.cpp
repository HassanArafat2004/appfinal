#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QRegularExpression>
#include <QStringConverter>

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    setWindowTitle("Sign Up");
    mainWindow = qobject_cast<MainWindow*>(parent);
    showMaximized();
}

signup::~signup()
{
    delete ui;
}

bool signup::validatePassword(const QString &password)
{
    if (password.length() < 8) {
        return false;
    }
    
    QRegularExpression containsNumber("\\d");
    return containsNumber.match(password).hasMatch();
}

bool signup::validateEmail(const QString &email)
{
    if (email.isEmpty()) {
        return true;
    }
    
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return emailRegex.match(email).hasMatch();
}

void signup::on_createAccountButton_clicked()
{
    qDebug() << "Signup: Create Account button clicked";
    
    QString username = ui->Username_box->text().trimmed();
    QString password = ui->Password_box->text();
    QString email = ui->Email_box->text().trimmed();
    
    qDebug() << "Signup: Username:" << username;
    qDebug() << "Signup: Password length:" << password.length();
    qDebug() << "Signup: Email:" << email;

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please fill in all required fields!");
        return;
    }

    if (!validatePassword(password)) {
        QMessageBox::warning(this, "Sign Up", "Password must be at least 8 characters long and contain at least one number.");
        return;
    }

    if (!validateEmail(email)) {
        QMessageBox::warning(this, "Sign Up", "Please enter a valid email address.");
        return;
    }

    QString filePath = getLoginFilePath();
    qDebug() << "Signup: Using login file at:" << filePath;
    
    QStringList existingUsers;
    bool userExists = false;
    
    QFile readFile(filePath);
    if (readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&readFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
            existingUsers.append(line);
        QStringList parts = line.split(' ');
        if (parts.size() >= 1 && parts[0] == username) {
                userExists = true;
                qDebug() << "Signup: Username already exists in file:" << username;
        }
    }
        readFile.close();
    } else {
        qDebug() << "Signup: Could not read logindetails.txt:" << readFile.errorString();
        QMessageBox::warning(this, "Error", "Could not check existing usernames!");
        return;
    }
    
    if (userExists) {
        QMessageBox::warning(this, "Sign Up", "Username already exists!");
        return;
    }

    QString newUserLine = username + " " + password;
    if (!email.isEmpty()) {
        newUserLine += " " + email;
    }
    existingUsers.append(newUserLine);
    
    QFile writeFile(filePath);
    if (writeFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&writeFile);
        out.setEncoding(QStringConverter::Utf8);
        
        for (const QString &line : existingUsers) {
            out << line << "\n";
        }
        
        out.flush();
        writeFile.close();
        
        qDebug() << "Signup: Successfully wrote user to file:" << username;
        
        bool verificationSuccess = false;
        if (writeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream verifyStream(&writeFile);
            while (!verifyStream.atEnd()) {
                QString line = verifyStream.readLine();
                QStringList parts = line.split(' ');
                if (parts.size() >= 2 && parts[0] == username && parts[1] == password) {
                    verificationSuccess = true;
                    qDebug() << "Signup: User verification successful for:" << username;
                    break;
                }
            }
            writeFile.close();
        }
        
        if (!verificationSuccess) {
            qDebug() << "Signup: WARNING - User verification failed for:" << username;
            QMessageBox::warning(this, "Warning", "Account created but verification failed. Please contact support.");
            return;
        }
        
        QString userDir = QDir::homePath() + "/NotesApp/" + username;
        QDir().mkpath(userDir);
        qDebug() << "Signup: Created directory for user:" << userDir;

    QMessageBox::information(this, "Success", "Account created successfully!");
        
    if (mainWindow) {
        mainWindow->loadUsersFromFile();
        mainWindow->show();
    }
    this->hide();
    } else {
        qDebug() << "Signup: Failed to write to file:" << writeFile.errorString();
        QMessageBox::warning(this, "Error", "Could not create account: " + writeFile.errorString());
    }
}

void signup::on_cancelButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->hide();
}
