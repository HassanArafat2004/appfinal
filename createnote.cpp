<<<<<<< HEAD
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
=======
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
>>>>>>> f29377b6a49b3dc9fa486f0f187a3e82ccd13fde
