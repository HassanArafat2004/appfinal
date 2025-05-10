<<<<<<< HEAD
#include "reports.h"
#include "ui_reports.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QDateTime>
#include "user.h"

reports::reports(const QString &username, bool isAdmin, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reports)
    , reportModel(new QStandardItemModel(this))
    , m_username(username)
    , m_isAdmin(isAdmin)
{
    ui->setupUi(this);
    setWindowTitle("Reports");
    ui->reportTableView->setModel(reportModel);
    connect(ui->generateReportButton, &QPushButton::clicked, this, &reports::on_generateReportButton_clicked);
    connect(ui->exportReportButton, &QPushButton::clicked, this, &reports::on_exportReportButton_clicked);
    connect(ui->backToDashboardButton, &QPushButton::clicked, this, &reports::on_backToDashboardButton_clicked);
    loadUsers();
    if (!m_isAdmin) {
        ui->reportTypeComboBox->clear();
        ui->reportTypeComboBox->addItem("Total Notes");
        ui->reportTypeComboBox->addItem("Most Accessed Notes");
    }
}

reports::~reports()
{
    delete ui;
}

void reports::loadUsers() {
    users.clear();
    QFile file("logindetails.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 2) {
            users.append(User(parts[0], parts[1]));
        }
    }
    file.close();
}

void reports::on_generateReportButton_clicked() {
    int idx = ui->reportTypeComboBox->currentIndex();
    if (m_isAdmin) {
        if (idx == 0) {
            currentReportType = "TotalNotesPerUser";
            generateTotalNotesPerUser();
        } else {
            currentReportType = "MostAccessedNotes";
            generateMostAccessedNotes();
        }
    } else {
        if (idx == 0) {
            currentReportType = "TotalNotes";
            reportModel->clear();
            reportModel->setHorizontalHeaderLabels({"Username", "Total Notes"});
            QDir notesDir("notes");
            if (!notesDir.exists()) notesDir.mkpath(".");
            int noteCount = 0;
            QString userPrefix = m_username + "_";
            QStringList noteFiles = notesDir.entryList(QStringList() << userPrefix + "*.txt", QDir::Files);
            noteCount = noteFiles.size();
            QList<QStandardItem*> row;
            row << new QStandardItem(m_username) << new QStandardItem(QString::number(noteCount));
            reportModel->appendRow(row);
        } else {
            currentReportType = "MostAccessedNotes";
            generateMostAccessedNotes();
        }
    }
}

void reports::generateTotalNotesPerUser() {
    reportModel->clear();
    reportModel->setHorizontalHeaderLabels({"Username", "Total Notes"});
    QDir notesDir("notes");
    if (!notesDir.exists()) notesDir.mkpath(".");
    for (const User &user : users) {
        int noteCount = 0;
        QString userPrefix = user.username + "_";
        QStringList noteFiles = notesDir.entryList(QStringList() << userPrefix + "*.txt", QDir::Files);
        noteCount = noteFiles.size();
        QList<QStandardItem*> row;
        row << new QStandardItem(user.username) << new QStandardItem(QString::number(noteCount));
        reportModel->appendRow(row);
    }
}

void reports::generateMostAccessedNotes() {
    reportModel->clear();
    reportModel->setHorizontalHeaderLabels({"Note File", "Last Accessed"});
    QDir notesDir("notes");
    if (!notesDir.exists()) notesDir.mkpath(".");
    QFileInfoList files;
    if (m_isAdmin) {
        files = notesDir.entryInfoList(QStringList() << "*.txt", QDir::Files, QDir::Time);
    } else {
        QString userPrefix = m_username + "_";
        files = notesDir.entryInfoList(QStringList() << userPrefix + "*.txt", QDir::Files, QDir::Time);
    }
    for (const QFileInfo &fileInfo : files) {
        QList<QStandardItem*> row;
        row << new QStandardItem(fileInfo.fileName())
            << new QStandardItem(fileInfo.lastRead().toString("yyyy-MM-dd hh:mm:ss"));
        reportModel->appendRow(row);
    }
}

void reports::on_exportReportButton_clicked() {
    QString filter = "CSV Files (*.csv);;Text Files (*.txt)";
    QString filePath = QFileDialog::getSaveFileName(this, "Export Report", "report", filter);
    if (filePath.isEmpty()) return;
    bool csv = filePath.endsWith(".csv");
    exportReportToFile(filePath, csv);
}

void reports::exportReportToFile(const QString &filePath, bool csv) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Export Failed", "Could not open file for writing.");
        return;
    }
    QTextStream out(&file);
    QString sep = csv ? "," : "\t";
    for (int col = 0; col < reportModel->columnCount(); ++col) {
        out << reportModel->headerData(col, Qt::Horizontal).toString();
        if (col < reportModel->columnCount() - 1) out << sep;
    }
    out << "\n";
    for (int row = 0; row < reportModel->rowCount(); ++row) {
        for (int col = 0; col < reportModel->columnCount(); ++col) {
            out << reportModel->item(row, col)->text();
            if (col < reportModel->columnCount() - 1) out << sep;
        }
        out << "\n";
    }
    file.close();
    QMessageBox::information(this, "Export Success", "Report exported successfully.");
}

void reports::on_backToDashboardButton_clicked() {
    emit backToDashboardRequested();
    this->close();
}
=======
#include "reports.h"
#include "ui_reports.h"

reports::reports(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reports)
{
    ui->setupUi(this);
}

reports::~reports()
{
    delete ui;
}
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
