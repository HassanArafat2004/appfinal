#include "notelist.h"
#include "ui_notelist.h"
#include <QDir>
#include <QFileInfo>
#include <QDateTime>
#include <QMessageBox>
#include "createnote.h"
#include <QFile>
#include <QDesktopServices>
#include <QUrl>

NoteList::NoteList(const QString &username, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteList)
    , createNoteWindow(nullptr)
    , m_username(username)
{
    ui->setupUi(this);
    setWindowTitle("Notes List");
    showMaximized();

    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &NoteList::on_searchTextChanged);
    connect(ui->typeFilterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &NoteList::on_typeFilterChanged);
    connect(ui->notesTableWidget, &QTableWidget::cellDoubleClicked, this, &NoteList::on_noteDoubleClicked);

    ui->notesTableWidget->setColumnCount(3);
    ui->notesTableWidget->setHorizontalHeaderLabels({"Name", "Type", "Date Created"});
    ui->notesTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->notesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->notesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->notesTableWidget->setAlternatingRowColors(true);

    loadNotes();
}

NoteList::~NoteList()
{
    delete ui;
    if (createNoteWindow) {
        delete createNoteWindow;
    }
}

void NoteList::on_createNoteButton_clicked()
{
    if (createNoteWindow) {
        createNoteWindow->show();
        createNoteWindow->raise();
        createNoteWindow->activateWindow();
    } else {
        createNoteWindow = new CreateNote(m_username);
        connect(createNoteWindow, &CreateNote::backToDashboardRequested, this, [this]() {
            this->show();
            this->raise();
            this->activateWindow();
            loadNotes();
        });
        createNoteWindow->show();
    }
    this->hide();
}

void NoteList::loadNotes() {
    ui->notesTableWidget->setRowCount(0);

    QString notesPath = QDir::homePath() + "/NotesApp/" + m_username;
    QDir notesDir(notesPath);
    
    if (!notesDir.exists()) {
        notesDir.mkpath(".");
    }

    QFile::setPermissions(notesPath, 
        QFile::ReadOwner | QFile::WriteOwner | QFile::ExeOwner |
        QFile::ReadUser | QFile::WriteUser | QFile::ExeUser);
    
    QStringList filters;
    filters << "*.txt" << "*.jpg";
    QFileInfoList files = notesDir.entryInfoList(filters, QDir::Files, QDir::Time | QDir::Reversed);

    for (const QFileInfo &fileInfo : files) {
        QFile::setPermissions(fileInfo.absoluteFilePath(), 
            QFile::ReadOwner | QFile::WriteOwner |
            QFile::ReadUser | QFile::WriteUser);

        QString noteType = fileInfo.suffix() == "txt" ? "Text" : "Doodle";
        QString searchText = ui->searchLineEdit->text().toLower();
        QString typeFilter = ui->typeFilterComboBox->currentText();

        if (!searchText.isEmpty() && !fileInfo.baseName().toLower().contains(searchText)) {
            continue;
        }
        if (typeFilter != "All" && noteType != typeFilter) {
            continue;
        }

        int row = ui->notesTableWidget->rowCount();
        ui->notesTableWidget->insertRow(row);
        ui->notesTableWidget->setItem(row, 0, new QTableWidgetItem(fileInfo.baseName()));
        ui->notesTableWidget->setItem(row, 1, new QTableWidgetItem(noteType));
        ui->notesTableWidget->setItem(row, 2, new QTableWidgetItem(
            fileInfo.lastModified().toString("MM/dd/yyyy hh:mm")));
    }

    ui->notesTableWidget->resizeColumnsToContents();
}

void NoteList::on_deleteNoteButton_clicked()
{
    int currentRow = ui->notesTableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Delete Note", "Please select a note to delete.");
        return;
    }

    QString noteName = ui->notesTableWidget->item(currentRow, 0)->text();
    QString noteType = ui->notesTableWidget->item(currentRow, 1)->text();
    QString filePath = QDir::homePath() + "/NotesApp/" + m_username + "/" + noteName +
                      (noteType == "Text" ? ".txt" : ".jpg");

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Note",
                                 "Are you sure you want to delete the note '" + noteName + "'?",
                                 QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) {
        return;
    }

    if (!isFileAccessible(filePath)) {
        QMessageBox::warning(this, "Delete Note", "Cannot delete note. File access denied.");
        return;
    }

    QFile file(filePath);
    if (file.remove()) {
        QMessageBox::information(this, "Delete Note", "Note deleted successfully.");
        loadNotes();
    } else {
        QMessageBox::warning(this, "Delete Note",
                            "Failed to delete note: " + file.errorString());
    }
}

void NoteList::on_searchTextChanged(const QString &text)
{
    Q_UNUSED(text);
    loadNotes();
}

void NoteList::on_typeFilterChanged(int index)
{
    Q_UNUSED(index);
    loadNotes();
}

void NoteList::on_noteDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    QString noteName = ui->notesTableWidget->item(row, 0)->text();
    QString noteType = ui->notesTableWidget->item(row, 1)->text();
    QString filePath = QDir::homePath() + "/NotesApp/" + m_username + "/" + noteName + 
                      (noteType == "Text" ? ".txt" : ".jpg");

    if (!isFileAccessible(filePath)) {
        QMessageBox::warning(this, "Access Denied", "You don't have permission to access this note.");
        return;
    }

    if (noteType == "Text") {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString content = in.readAll();
            file.close();
            
            if (createNoteWindow) {
                createNoteWindow->loadNote(noteName, content);
                createNoteWindow->show();
                createNoteWindow->raise();
                createNoteWindow->activateWindow();
            } else {
                createNoteWindow = new CreateNote(m_username);
                createNoteWindow->loadNote(noteName, content);
                connect(createNoteWindow, &CreateNote::backToDashboardRequested, this, [this]() {
                    this->show();
                    this->raise();
                    this->activateWindow();
                    loadNotes();
                });
                createNoteWindow->show();
            }
            this->hide();
        }
    } else {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

bool NoteList::isFileAccessible(const QString &filePath)
{
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists()) {
        return false;
    }

    QString userDir = QDir::homePath() + "/NotesApp/" + m_username;
    if (!filePath.startsWith(userDir)) {
        return false;
    }

    QFile::Permissions permissions = fileInfo.permissions();
    if (!(permissions & QFile::ReadOwner)) {
        return false;
    }

    return true;
}

void NoteList::on_backToDashboardButton_clicked()
{
    this->hide();

    if (createNoteWindow) {
        createNoteWindow->hide();
    }

    emit backToDashboardRequested();
}
