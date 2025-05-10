#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include <QMessageBox>
#include "reports.h"
#include "createnote.h"

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
    CreateNote *createNoteWindow { nullptr };
};

#endif
