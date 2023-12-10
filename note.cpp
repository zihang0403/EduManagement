#include "note.h"

#ifdef NOTE

#include "ui_note.h"
note::note(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::note)
{
    ui->setupUi(this);
}

note::~note()
{
    delete ui;
}

#endif
