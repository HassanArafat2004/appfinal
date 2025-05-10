#include "createnote.h"
#include "ui_createnote.h"
#include <QMessageBox>

CreateNote::CreateNote(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateNote)
{
    ui->setupUi(this);
    setWindowTitle("Create Note");
       showMaximized(); // occupy the full screen on any monitor

    // Wire buttons coming from the UI file (object names must match!)
    connect(ui->saveButton,   &QPushButton::clicked, this, &CreateNote::on_saveButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &CreateNote::on_cancelButton_clicked);
}

CreateNote::~CreateNote()
{
    delete ui;
}

void CreateNote::on_saveButton_clicked()
{
    // TODO: retrieve data from your widgets and persist the note.
    // For now we just show a confirmation and bounce back to the dashboard.
    QMessageBox::information(this, "Save", "Note saved!");
    emit backToDashboardRequested();
    close();
}

void CreateNote::on_cancelButton_clicked()
{
    emit backToDashboardRequested();
    close();
}
