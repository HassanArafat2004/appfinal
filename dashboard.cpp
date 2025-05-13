#include "dashboard.h"
#include "ui_dashboard.h"
#include "mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
#include <QLabel>
#include <QVBoxLayout>
#include "reports.h"
#include <QApplication>
#include <QFile>

dashboard::dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dashboard),
    clockTimer(new QTimer(this)),
    m_username(""),
    totalNotesLabel(nullptr),
    recentNotesLabel(nullptr),
    reportsLabel(nullptr),
    createNoteWindow(nullptr),
    reportsWindow(nullptr),
    noteListWindow(nullptr)
{
    ui->setupUi(this);
    
    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | 
                       Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | 
                       Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_DeleteOnClose, false);
    
    this->setMinimumSize(800, 600);
    setWindowTitle("Dashboard");

    setupGroupBoxes();

    connect(clockTimer, &QTimer::timeout, this, &dashboard::updateClock);
    clockTimer->start(1000);
    updateClock();
    updateDashboardStats();

    connect(ui->notesButton, &QPushButton::clicked, this, &dashboard::on_notesButton_clicked);
    connect(ui->newNoteButton, &QPushButton::clicked, this, &dashboard::on_newNoteButton_clicked);
    connect(ui->reportsButton, &QPushButton::clicked, this, &dashboard::on_reportsButton_clicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &dashboard::on_logoutButton_clicked);
}

void dashboard::setupGroupBoxes()
{
    QVBoxLayout *totalNotesLayout = new QVBoxLayout(ui->totalNotesGroupBox);
    totalNotesLabel = new QLabel(ui->totalNotesGroupBox);
    totalNotesLabel->setWordWrap(true);
    totalNotesLayout->addWidget(totalNotesLabel);
    ui->totalNotesGroupBox->setLayout(totalNotesLayout);

    QVBoxLayout *recentNotesLayout = new QVBoxLayout(ui->recentNotesGroupBox);
    recentNotesLabel = new QLabel(ui->recentNotesGroupBox);
    recentNotesLabel->setWordWrap(true);
    recentNotesLayout->addWidget(recentNotesLabel);
    ui->recentNotesGroupBox->setLayout(recentNotesLayout);

    QVBoxLayout *reportsLayout = new QVBoxLayout(ui->reportsGroupBox);
    reportsLabel = new QLabel(ui->reportsGroupBox);
    reportsLabel->setWordWrap(true);
    reportsLayout->addWidget(reportsLabel);
    ui->reportsGroupBox->setLayout(reportsLayout);
}

dashboard::~dashboard()
{
    delete ui;
    if (createNoteWindow) {
        createNoteWindow->deleteLater();
    }
    if (reportsWindow) {
        reportsWindow->deleteLater();
    }
    if (noteListWindow) {
        noteListWindow->deleteLater();
    }
}

void dashboard::setUsername(const QString &username) {
    m_username = username;
    ui->welcomeLabel->setText("Welcome, " + m_username);
    
    QString userDir = QDir::homePath() + "/NotesApp/" + m_username;
    QDir notesDir(userDir);
    
    if (!notesDir.exists()) {
        if (!notesDir.mkpath(".")) {
            QMessageBox::critical(this, "Error", "Could not create user directory. Please check permissions.");
            return;
        }
    }
    
    QFile::setPermissions(userDir, 
        QFile::ReadOwner | QFile::WriteOwner | QFile::ExeOwner |
        QFile::ReadUser | QFile::WriteUser | QFile::ExeUser);
    
    updateDashboardStats();
}

void dashboard::updateClock() {
    QString currentTime = QDateTime::currentDateTime().toString("hh:mm:ss AP");
    ui->clockLabel->setText(currentTime);
}

void dashboard::updateDashboardStats() {
    QString userDir = QDir::homePath() + "/NotesApp/" + m_username;
    QDir notesDir(userDir);
    
    if (!notesDir.exists()) {
        notesDir.mkpath(".");
    }
    
    QStringList filters;
    filters << "*.txt" << "*.jpg";
    QFileInfoList files = notesDir.entryInfoList(filters, QDir::Files, QDir::Time);

    int textNotes = 0;
    int doodleNotes = 0;
    for (const QFileInfo &fileInfo : files) {
        if (fileInfo.suffix() == "txt") {
            textNotes++;
        } else if (fileInfo.suffix() == "jpg") {
            doodleNotes++;
        }
    }

    int totalNotes = files.size();
    ui->totalNotesGroupBox->setTitle("Total Notes");
    totalNotesLabel->setText(QString("<div style='text-align: center; font-size: 48px; font-weight: bold; color: #2563eb;'>%1</div>"
                                   "<div style='text-align: center; color: #4a5568;'>notes in total</div>")
                            .arg(totalNotes));

    QString recentNotesText;
    int recentCount = 0;
    for (const QFileInfo &fileInfo : files) {
        if (recentCount >= 5) break;
        QString noteType = fileInfo.suffix() == "txt" ? "Text" : "Doodle";
        QString typeColor = noteType == "Text" ? "#2563eb" : "#059669";
        recentNotesText += QString("<div style='margin-bottom: 8px;'>"
                                 "<span style='font-weight: bold;'>%1</span> "
                                 "<span style='color: %2; font-size: 12px; background: %3; padding: 2px 6px; border-radius: 4px;'>%4</span><br>"
                                 "<span style='color: #4a5568; font-size: 12px;'>%5</span>"
                                 "</div>")
            .arg(fileInfo.baseName())
            .arg(typeColor)
            .arg(typeColor == "#2563eb" ? "#ebf5ff" : "#ecfdf5")
            .arg(noteType)
            .arg(fileInfo.lastModified().toString("MMM dd, yyyy hh:mm AP"));
        recentCount++;
    }
    if (recentCount == 0) {
        recentNotesText = "<div style='text-align: center; color: #4a5568;'>No recent notes</div>";
    }
    ui->recentNotesGroupBox->setTitle("Recent Notes");
    recentNotesLabel->setText(recentNotesText);

    QString systemStats = QString("<div style='display: flex; flex-direction: column; gap: 12px;'>"
                                "<div style='display: flex; justify-content: space-between; align-items: center;'>"
                                "<span style='color: #4a5568;'>Total Notes</span>"
                                "<span style='font-weight: bold; color: #2563eb;'>%1</span>"
                                "</div>"
                                "<div style='display: flex; justify-content: space-between; align-items: center;'>"
                                "<span style='color: #4a5568;'>Text Notes</span>"
                                "<span style='font-weight: bold; color: #2563eb;'>%2</span>"
                                "</div>"
                                "<div style='display: flex; justify-content: space-between; align-items: center;'>"
                                "<span style='color: #4a5568;'>Doodle Notes</span>"
                                "<span style='font-weight: bold; color: #059669;'>%3</span>"
                                "</div>"
                                "</div>")
        .arg(totalNotes)
        .arg(textNotes)
        .arg(doodleNotes);
    ui->reportsGroupBox->setTitle("System Stats");
    reportsLabel->setText(systemStats);
}

void dashboard::showDashboard() {
    this->setVisible(true);
    
    this->show();
    this->raise();
    this->activateWindow();
    
    this->showMaximized();
    
    updateDashboardStats();
}

void dashboard::on_notesButton_clicked() {
    if (createNoteWindow) {
        createNoteWindow->hide();
    }
    if (reportsWindow) {
        reportsWindow->hide();
    }

    if (this->noteListWindow) {
        this->noteListWindow->show();
        this->noteListWindow->raise();
        this->noteListWindow->activateWindow();
    } else {
        this->noteListWindow = new NoteList(m_username);
        connect(this->noteListWindow, &NoteList::backToDashboardRequested, this, &dashboard::showDashboard);
        this->noteListWindow->show();
    }
    this->hide();
}

void dashboard::on_newNoteButton_clicked() {
    if (noteListWindow) {
        noteListWindow->hide();
    }
    if (reportsWindow) {
        reportsWindow->hide();
    }

    if (this->createNoteWindow) {
        this->createNoteWindow->show();
        this->createNoteWindow->raise();
        this->createNoteWindow->activateWindow();
    } else {
        this->createNoteWindow = new CreateNote(m_username);
        connect(this->createNoteWindow, &CreateNote::backToDashboardRequested, this, &dashboard::showDashboard);
        this->createNoteWindow->show();
    }
    this->hide();
}

void dashboard::on_reportsButton_clicked() {
    if (noteListWindow) {
        noteListWindow->hide();
    }
    if (createNoteWindow) {
        createNoteWindow->hide();
    }

    bool isAdmin = (m_username == "admin");
    if (this->reportsWindow) {
        this->reportsWindow->show();
        this->reportsWindow->raise();
        this->reportsWindow->activateWindow();
    } else {
        this->reportsWindow = new reports(m_username, isAdmin);
        connect(this->reportsWindow, &reports::backToDashboardRequested, this, &dashboard::showDashboard);
        this->reportsWindow->show();
    }
    this->hide();
}

void dashboard::on_logoutButton_clicked()
{
    if (createNoteWindow) {
        createNoteWindow->hide();
        createNoteWindow->deleteLater();
        createNoteWindow = nullptr;
    }
    if (reportsWindow) {
        reportsWindow->hide();
        reportsWindow->deleteLater();
        reportsWindow = nullptr;
    }
    if (noteListWindow) {
        noteListWindow->hide();
        noteListWindow->deleteLater();
        noteListWindow = nullptr;
    }
    
    MainWindow* mainWindow = nullptr;
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
        mainWindow = qobject_cast<MainWindow*>(widget);
        if (mainWindow) {
            break;
        }
    }
    
    if (mainWindow) {
        mainWindow->clearLoginFields();
        mainWindow->show();
        mainWindow->raise();
        mainWindow->activateWindow();
    } else {
        mainWindow = new MainWindow();
        mainWindow->show();
    }
    
    this->hide();
    this->deleteLater();
}
