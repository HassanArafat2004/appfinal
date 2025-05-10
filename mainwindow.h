<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include "signup.h"
#include "adminwindow.h"
#include "user.h"
#include "dashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<User> users;
    void loadUsersFromFile();

private slots:
    void handleUsernameEnter();
    void on_handleLoginButton_clicked();

private:
    Ui::MainWindow *ui;
    signup *signupWindow;
    AdminWindow *adminWindow;
    dashboard *dashboardWindow;
};
#endif
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include "signup.h"
#include "adminwindow.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<User> users;

private slots:
    void loadUsersFromFile();
    void handleUsernameEnter();
    void on_handleLoginButton_clicked();

private:
    Ui::MainWindow *ui;
    signup *signupWindow;
    AdminWindow *adminWindow;
};
#endif
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
