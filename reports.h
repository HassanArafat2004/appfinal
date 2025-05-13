#ifndef REPORTS_H
#define REPORTS_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QString>
#include <QList>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class reports;
}

class reports : public QMainWindow
{
    Q_OBJECT

public:
    explicit reports(const QString &username, bool isAdmin, QWidget *parent = nullptr);
    ~reports();

signals:
    void backToDashboardRequested();

private slots:
    void on_generateReportButton_clicked();
    void on_exportReportButton_clicked();
    void on_backToDashboardButton_clicked();

private:
    Ui::reports *ui;
    QStandardItemModel *reportModel;
    QString m_username;
    bool m_isAdmin;
    QList<User> users;
    QString currentReportType;

    void loadUsers();
    void generateUserTotalNotes();
    void generateTotalNotesPerUser();
    void generateMostAccessedNotes();
    void exportReportToFile(const QString &filePath, bool csv);
};

#endif // REPORTS_H
