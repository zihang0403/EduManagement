#include "coursedeleteform.h"
#include "ui_coursedeleteform.h"

CourseDeleteForm::CourseDeleteForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CourseDeleteForm)
{
    ui->setupUi(this);
}

CourseDeleteForm::~CourseDeleteForm()
{
    delete ui;
}
