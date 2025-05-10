<<<<<<< HEAD
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
=======
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
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
