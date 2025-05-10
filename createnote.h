// ────────────────────────────────
//  createnote.h
// ────────────────────────────────
#ifndef CREATENOTE_H
#define CREATENOTE_H

#include <QMainWindow>

namespace Ui {
class CreateNote;
}

class CreateNote : public QMainWindow
{
    Q_OBJECT
public:
    explicit CreateNote(QWidget *parent = nullptr);
    ~CreateNote();

signals:
    /**
     * Emitted when the user is finished (Save / Cancel) and wants to return
     * to the Dashboard.  The caller decides whether to keep or discard the
     * CreateNote instance.
     */
    void backToDashboardRequested();

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreateNote *ui;
};
