#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QSettings>
#include <QStringConverter>

QString getLoginFilePath() {
    QString currentDirPath = QDir::currentPath() + "/logindetails.txt";
    
    if (QFile::exists(currentDirPath)) {
        return currentDirPath;
    }
    
    QString appDirPath = QCoreApplication::applicationDirPath() + "/logindetails.txt";
    
    if (QFile::exists(appDirPath)) {
        return appDirPath;
    }
    
    return appDirPath;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QString notesAppDir = QDir::homePath() + "/NotesApp";
    QDir().mkpath(notesAppDir);
    QDir().mkpath(notesAppDir + "/admin");
    
    QString loginFilePath = getLoginFilePath();
    QFile loginFile(loginFilePath);
    
    if (!loginFile.exists()) {
        if (loginFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&loginFile);
            out.setEncoding(QStringConverter::Utf8);
            out << "admin admin admin@notesapp.com\n";
            out << "omarshawky1 omarshawky1 omarshawky1@gmail.com\n";
            out << "mohamed123 mohamed123 mohamed123@gmail.com\n";
            loginFile.close();
        }
    } else {
        bool hasAdmin = false;
        if (loginFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&loginFile);
            while (!in.atEnd()) {
                if (in.readLine().startsWith("admin ")) {
                    hasAdmin = true;
                    break;
                }
            }
            loginFile.close();
            
            if (!hasAdmin) {
                QStringList allLines;
                if (loginFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream readStream(&loginFile);
                    while (!readStream.atEnd()) {
                        allLines.append(readStream.readLine());
                    }
                    loginFile.close();
                }
                
                if (loginFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&loginFile);
                    out.setEncoding(QStringConverter::Utf8);
                    out << "admin admin admin@notesapp.com\n";
                    for (const QString &line : allLines) {
                        out << line << "\n";
                    }
                    loginFile.close();
                }
            }
        }
    }
    
    QSettings settings("NotesApp", "Paths");
    settings.setValue("LoginFilePath", loginFilePath);
    
    MainWindow w;
    w.show();
    return a.exec();
}
