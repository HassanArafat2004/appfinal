#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QRegularExpression>
#include "user.h"
#include "reports.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();
    void loadUsersFromFile();

private slots:
    void on_loadUsersButton_clicked();
    void on_saveChangesButton_clicked();
    void on_deleteUserButton_clicked();
    void on_backButton_clicked();
    void on_reportsButton_clicked();
    void on_addUserButton_clicked();

private:
    Ui::AdminWindow *ui;
    QList<User> users;
    reports *adminReportsWindow;
    void saveUsersToFile();
    bool validatePassword(const QString &password);
    bool validateEmail(const QString &email);
};

#endif
