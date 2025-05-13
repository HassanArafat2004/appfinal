#ifndef NOTELIST_H
#define NOTELIST_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QComboBox>
#include "createnote.h"

namespace Ui {
class NoteList;
}

class NoteList : public QWidget
{
    Q_OBJECT

public:
    explicit NoteList(const QString &username = QString(), QWidget *parent = nullptr);
    ~NoteList();

signals:
    void backToDashboardRequested();

private slots:
    void on_createNoteButton_clicked();
    void on_deleteNoteButton_clicked();
    void on_searchTextChanged(const QString &text);
    void on_typeFilterChanged(int index);
    void on_noteDoubleClicked(int row, int column);
    void on_backToDashboardButton_clicked();

private:
    Ui::NoteList *ui;
    CreateNote *createNoteWindow;
    QString m_username;
    void loadNotes();
    bool isFileAccessible(const QString &filePath);
};

#endif // NOTELIST_H
