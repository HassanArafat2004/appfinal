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
