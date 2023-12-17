#include "studentaddform.h"
#include "ui_studentaddform.h"

StudentAddForm::StudentAddForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentAddForm)
{
    ui->setupUi(this);
}

StudentAddForm::~StudentAddForm()
{
    delete ui;
}
