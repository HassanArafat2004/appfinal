<<<<<<< HEAD
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
=======
#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>

namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = nullptr);
    ~reports();

private:
    Ui::reports *ui;
};

#endif // REPORTS_H
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
