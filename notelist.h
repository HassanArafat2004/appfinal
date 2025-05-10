<<<<<<< HEAD
#ifndef NOTELIST_H
#define NOTELIST_H

#include <QWidget>

namespace Ui {
class NoteList;
}

class NoteList : public QWidget
{
    Q_OBJECT

public:
    explicit NoteList(QWidget *parent = nullptr);
    ~NoteList();

private:
    Ui::NoteList *ui;
};

#endif // NOTELIST_H
=======
#ifndef NOTELIST_H
#define NOTELIST_H

#include <QWidget>

namespace Ui {
class NoteList;
}

class NoteList : public QWidget
{
    Q_OBJECT

public:
    explicit NoteList(QWidget *parent = nullptr);
    ~NoteList();

private:
    Ui::NoteList *ui;
};

#endif // NOTELIST_H
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
