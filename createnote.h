#ifndef CREATENOTE_H
#define CREATENOTE_H

#include <QWidget>

namespace Ui {
class CreateNote;
}

class CreateNote : public QWidget
{
    Q_OBJECT

public:
    explicit CreateNote(QWidget *parent = nullptr);
    ~CreateNote();

private:
    Ui::CreateNote *ui;
};

#endif // CREATENOTE_H
