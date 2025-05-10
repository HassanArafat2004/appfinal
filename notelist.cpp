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
