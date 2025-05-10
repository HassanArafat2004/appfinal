#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "user.h"

namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(const QString &username = "", bool isAdmin = false, QWidget *parent = nullptr);
    ~reports();

public slots:
    void on_generateReportButton_clicked();
    void on_exportReportButton_clicked();
    void on_backToDashboardButton_clicked();

signals:
    void backToDashboardRequested();

private:
    Ui::reports *ui;
    QStandardItemModel *reportModel;
    QString currentReportType;
    QList<User> users;
    QString m_username;
    bool m_isAdmin;
    void loadUsers();
    void generateTotalNotesPerUser();
    void generateMostAccessedNotes();
    void exportReportToFile(const QString &filePath, bool csv);
};

#endif // REPORTS_H
