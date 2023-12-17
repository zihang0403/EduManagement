#include "courseaddform.h"
#include "ui_courseaddform.h"

CourseAddForm::CourseAddForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CourseAddForm)
{
    ui->setupUi(this);
}

CourseAddForm::~CourseAddForm()
{
    delete ui;
}
