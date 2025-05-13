#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include <QMessageBox>
#include <QLabel>
#include "reports.h"
#include "createnote.h"
#include "notelist.h"
#include "mainwindow.h"

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
    void showDashboard();

private slots:
    void updateClock();
    void on_notesButton_clicked();
    void on_newNoteButton_clicked();
    void on_reportsButton_clicked();
    void on_logoutButton_clicked();
    void updateDashboardStats();

private:
    Ui::dashboard *ui;
    QTimer *clockTimer;
    QString m_username;
    QLabel *totalNotesLabel = nullptr;
    QLabel *recentNotesLabel = nullptr;
    QLabel *reportsLabel = nullptr;
    CreateNote *createNoteWindow = nullptr;
    reports *reportsWindow = nullptr;
    NoteList *noteListWindow = nullptr;
    void setupGroupBoxes();
};

#endif
