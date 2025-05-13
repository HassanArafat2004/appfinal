#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QList>
#include "user.h"

// Forward declarations
class signup;
class AdminWindow;
class dashboard;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadUsersFromFile();
    void clearLoginFields();
    QList<User> users;

private slots:
    void on_handleLoginButton_clicked();
    void handleUsernameEnter();

private:
    Ui::MainWindow *ui;
    signup *signupWindow;
    AdminWindow *adminWindow;
    dashboard *dashboardWindow;
};

#endif
