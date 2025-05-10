<<<<<<< HEAD
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include <QMessageBox>
#include "reports.h"

namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
    void setUsername(const QString &username);

private slots:
    void updateClock();
    void on_notesButton_clicked();
    void on_newNoteButton_clicked();
    void on_reportsButton_clicked();
    void updateDashboardStats();

private:
    Ui::dashboard *ui;
    QString m_username;
    QTimer *clockTimer;
    reports *reportsWindow;
};

#endif
=======
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private:
    Ui::dashboard *ui;
};

#endif
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
