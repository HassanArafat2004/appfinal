#include "reports.h"
#include "ui_reports.h"
#include <QStandardItemModel>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDebug>
#include "user.h"

// Forward declaration of the getLoginFilePath function from main.cpp
QString getLoginFilePath();

reports::reports(const QString &username, bool isAdmin, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reports)
    , reportModel(new QStandardItemModel(this))
    , m_username(username)
    , m_isAdmin(isAdmin)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    this->setMinimumSize(800, 600);
    setWindowTitle("Reports");

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    mainLayout->addWidget(ui->reportsPageTitleLabel);
    mainLayout->addWidget(ui->widget);
    mainLayout->addWidget(ui->reportTableView);
    mainLayout->addWidget(ui->exportReportButton);
    mainLayout->addWidget(ui->backToDashboardButton);

    setCentralWidget(centralWidget);

    ui->reportTableView->setModel(reportModel);
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
    
    QString filePath = getLoginFilePath();
    qDebug() << "Reports: Loading users from:" << filePath;
    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Reports: Failed to open login details file";
        return;
    }
    
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 2) {
            QString email = parts.size() >= 3 ? parts[2] : "";
            users.append(User(parts[0], parts[1], email));
            qDebug() << "Reports: Loaded user:" << parts[0];
        }
    }
    file.close();
    qDebug() << "Reports: Total users loaded:" << users.size();
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
            generateUserTotalNotes();
        } else {
            currentReportType = "MostAccessedNotes";
            generateMostAccessedNotes();
        }
    }
}

void reports::generateUserTotalNotes() {
    reportModel->clear();
    reportModel->setHorizontalHeaderLabels({"Note Type", "Count"});
    
    QString userDir = QDir::homePath() + "/NotesApp/" + m_username;
    QDir notesDir(userDir);
    if (!notesDir.exists()) {
        notesDir.mkpath(".");
    }
    
    QStringList txtFiles = notesDir.entryList(QStringList() << "*.txt", QDir::Files);
    QStringList jpgFiles = notesDir.entryList(QStringList() << "*.jpg", QDir::Files);
    
    int textNotes = txtFiles.size();
    int doodleNotes = jpgFiles.size();
    int totalNotes = textNotes + doodleNotes;
    
    QList<QStandardItem*> row1;
    row1 << new QStandardItem("Text Notes") << new QStandardItem(QString::number(textNotes));
    reportModel->appendRow(row1);
    
    QList<QStandardItem*> row2;
    row2 << new QStandardItem("Doodle Notes") << new QStandardItem(QString::number(doodleNotes));
    reportModel->appendRow(row2);
    
    QList<QStandardItem*> row3;
    row3 << new QStandardItem("Total") << new QStandardItem(QString::number(totalNotes));
    reportModel->appendRow(row3);
    
    ui->totalNotesLabel->setText("Total Notes: " + QString::number(totalNotes));
}

void reports::generateTotalNotesPerUser() {
    reportModel->clear();
    reportModel->setHorizontalHeaderLabels({"Username", "Text Notes", "Doodle Notes", "Total Notes"});
    
    int grandTotalNotes = 0;
    int grandTotalTextNotes = 0;
    int grandTotalDoodleNotes = 0;
    
    for (const User &user : users) {
        QString userDir = QDir::homePath() + "/NotesApp/" + user.username;
        QDir notesDir(userDir);
        
        int textNotes = 0;
        int doodleNotes = 0;
        
        if (notesDir.exists()) {
            QStringList txtFiles = notesDir.entryList(QStringList() << "*.txt", QDir::Files);
            QStringList jpgFiles = notesDir.entryList(QStringList() << "*.jpg", QDir::Files);
            
            textNotes = txtFiles.size();
            doodleNotes = jpgFiles.size();
        }
        
        int totalNotes = textNotes + doodleNotes;
        grandTotalTextNotes += textNotes;
        grandTotalDoodleNotes += doodleNotes;
        grandTotalNotes += totalNotes;
        
        QList<QStandardItem*> row;
        row << new QStandardItem(user.username)
            << new QStandardItem(QString::number(textNotes))
            << new QStandardItem(QString::number(doodleNotes))
            << new QStandardItem(QString::number(totalNotes));
        reportModel->appendRow(row);
    }
    
    QList<QStandardItem*> totalRow;
    totalRow << new QStandardItem("TOTAL")
             << new QStandardItem(QString::number(grandTotalTextNotes))
             << new QStandardItem(QString::number(grandTotalDoodleNotes))
             << new QStandardItem(QString::number(grandTotalNotes));
    reportModel->appendRow(totalRow);
    
    ui->totalNotesLabel->setText("Total Notes: " + QString::number(grandTotalNotes));
}

void reports::generateMostAccessedNotes() {
    reportModel->clear();
    reportModel->setHorizontalHeaderLabels({"Note Name", "Type", "Last Accessed", "Creation Date"});
    
    QList<QPair<QString, QFileInfo>> allFiles;
    
    if (m_isAdmin) {
        for (const User &user : users) {
            QString userDir = QDir::homePath() + "/NotesApp/" + user.username;
            QDir notesDir(userDir);
            
            if (notesDir.exists()) {
                QFileInfoList files = notesDir.entryInfoList(QStringList() << "*.txt" << "*.jpg", QDir::Files);
                
                for (const QFileInfo &fileInfo : files) {
                    allFiles.append(qMakePair(user.username, fileInfo));
                }
            }
        }
    } else {
        QString userDir = QDir::homePath() + "/NotesApp/" + m_username;
        QDir notesDir(userDir);
        
        if (notesDir.exists()) {
            QFileInfoList files = notesDir.entryInfoList(QStringList() << "*.txt" << "*.jpg", QDir::Files);
            
            for (const QFileInfo &fileInfo : files) {
                allFiles.append(qMakePair(m_username, fileInfo));
    }
        }
    }
    
    std::sort(allFiles.begin(), allFiles.end(), [](const QPair<QString, QFileInfo> &a, const QPair<QString, QFileInfo> &b) {
        return a.second.lastRead() > b.second.lastRead();
    });
    
    for (const auto &pair : allFiles) {
        const QString &username = pair.first;
        const QFileInfo &fileInfo = pair.second;
        
        QString noteType = fileInfo.suffix() == "txt" ? "Text" : "Doodle";
        
        QList<QStandardItem*> row;
        if (m_isAdmin) {
            row << new QStandardItem(username + " - " + fileInfo.baseName())
                << new QStandardItem(noteType)
                << new QStandardItem(fileInfo.lastRead().toString("yyyy-MM-dd hh:mm:ss"))
                << new QStandardItem(fileInfo.birthTime().toString("yyyy-MM-dd hh:mm:ss"));
        } else {
            row << new QStandardItem(fileInfo.baseName())
                << new QStandardItem(noteType)
                << new QStandardItem(fileInfo.lastRead().toString("yyyy-MM-dd hh:mm:ss"))
                << new QStandardItem(fileInfo.birthTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
        reportModel->appendRow(row);
    }
    
    ui->totalNotesLabel->setText("Total Notes: " + QString::number(allFiles.size()));
}

void reports::on_exportReportButton_clicked() {
    static bool isExporting = false;
    
    if (isExporting) {
        qDebug() << "Reports: Export already in progress, ignoring additional click";
        return;
    }
    
    isExporting = true;
    
    QString filter = "CSV Files (*.csv);;Text Files (*.txt)";
    QString defaultName = "report_" + currentReportType + "_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    QString filePath = QFileDialog::getSaveFileName(this, "Export Report", defaultName, filter);
    
    isExporting = false;
    
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
    
    out << "Report Type: " << currentReportType << "\n";
    out << "Generated: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";
    out << "User: " << m_username << "\n\n";
    
    for (int col = 0; col < reportModel->columnCount(); ++col) {
        out << reportModel->headerData(col, Qt::Horizontal).toString();
        if (col < reportModel->columnCount() - 1) out << sep;
    }
    out << "\n";
    
    for (int row = 0; row < reportModel->rowCount(); ++row) {
        for (int col = 0; col < reportModel->columnCount(); ++col) {
            // Ensure we handle CSV format correctly (quote values with commas if needed)
            QString cellText = reportModel->item(row, col)->text();
            if (csv && cellText.contains(",")) {
                out << "\"" << cellText << "\"";
            } else {
                out << cellText;
            }
            
            if (col < reportModel->columnCount() - 1) out << sep;
        }
        out << "\n";
    }
    
    file.close();
    QMessageBox::information(this, "Export Success", "Report exported successfully to:\n" + filePath);
}

void reports::on_backToDashboardButton_clicked() {
    this->hide();
    
    emit backToDashboardRequested();
}
