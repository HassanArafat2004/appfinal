#include "createnote.h"
#include "ui_createnote.h"

CreateNote::CreateNote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateNote)
{
    ui->setupUi(this);
    ui->errorLabel->hide();
}

CreateNote::~CreateNote()
{
    delete ui;
}
