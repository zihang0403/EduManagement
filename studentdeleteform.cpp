#include "studentdeleteform.h"
#include "ui_studentdeleteform.h"

StudentDeleteForm::StudentDeleteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentDeleteForm)
{
    ui->setupUi(this);
}

StudentDeleteForm::~StudentDeleteForm()
{
    delete ui;
}
