#include "dashboard.h"
#include "ui_dashboard.h"
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include "reports.h"

dashboard::dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dashboard),
    clockTimer(new QTimer(this)),
    reportsWindow(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Dashboard");
    connect(clockTimer, &QTimer::timeout, this, &dashboard::updateClock);
    clockTimer->start(1000);
    updateClock();
    updateDashboardStats();
    connect(ui->notesButton, &QPushButton::clicked, this, &dashboard::on_notesButton_clicked);
    connect(ui->newNoteButton, &QPushButton::clicked, this, &dashboard::on_newNoteButton_clicked);
    connect(ui->reportsButton, &QPushButton::clicked, this, &dashboard::on_reportsButton_clicked);
}

dashboard::~dashboard()
{
    delete ui;
}

void dashboard::setUsername(const QString &username) {
    m_username = username;
    ui->welcomeLabel->setText("Welcome, " + m_username);
}

void dashboard::updateClock() {
    QString currentTime = QDateTime::currentDateTime().toString("hh:mm:ss AP");
    ui->clockLabel->setText(currentTime);
}

void dashboard::updateDashboardStats() {
    ui->totalNotesGroupBox->setTitle("Total Notes: 0");
    ui->recentNotesGroupBox->setTitle("Recent Notes: None");
    ui->reportsGroupBox->setTitle("Reports: None");
}

void dashboard::on_notesButton_clicked() {
    QMessageBox::information(this, "Notes", "Notes page not implemented yet.");
}

void dashboard::on_newNoteButton_clicked() {
    QMessageBox::information(this, "New Note", "New Note page not implemented yet.");
}

void dashboard::on_reportsButton_clicked() {
    bool isAdmin = (m_username == "admin");
    if (this->reportsWindow) {
        this->reportsWindow->show();
        this->reportsWindow->raise();
        this->reportsWindow->activateWindow();
    } else {
        this->reportsWindow = new reports(m_username, isAdmin);
        connect(this->reportsWindow, &reports::backToDashboardRequested, this, [this]() {
            this->show();
        });
        this->reportsWindow->show();
    }
    this->close();
}
