<<<<<<< HEAD
#include "notelist.h"
#include "ui_notelist.h"

NoteList::NoteList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteList)
{
    ui->setupUi(this);
}

NoteList::~NoteList()
{
    delete ui;
}
=======
#include "notelist.h"
#include "ui_notelist.h"

NoteList::NoteList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteList)
{
    ui->setupUi(this);
}

NoteList::~NoteList()
{
    delete ui;
}
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
