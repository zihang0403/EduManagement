#include "coursechangeform.h"
#include "ui_coursechangeform.h"

CourseChangeForm::CourseChangeForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CourseChangeForm)
{
    ui->setupUi(this);
}

CourseChangeForm::~CourseChangeForm()
{
    delete ui;
}
