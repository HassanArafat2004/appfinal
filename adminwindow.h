<<<<<<< HEAD
#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QList>
#include "user.h"
#include "reports.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_loadUsersButton_clicked();
    void on_saveChangesButton_clicked();
    void on_deleteUserButton_clicked();
    void on_backButton_clicked();
    void on_reportsButton_clicked();

private:
    Ui::AdminWindow *ui;
    QList<User> users;
    reports *adminReportsWindow;
    void loadUsersFromFile();
    void saveUsersToFile();
};

#endif
=======
#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QList>
#include "user.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_loadUsersButton_clicked();
    void on_saveChangesButton_clicked();
    void on_deleteUserButton_clicked();
    void on_backButton_clicked();

private:
    Ui::AdminWindow *ui;
    QList<User> users;
    void loadUsersFromFile();
    void saveUsersToFile();
};

#endif
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
