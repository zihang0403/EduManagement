#include "coursesettostudentform.h"
#include "ui_coursesettostudentform.h"

CourseSetToStudentForm::CourseSetToStudentForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CourseSetToStudentForm)
{
    ui->setupUi(this);
}

CourseSetToStudentForm::~CourseSetToStudentForm()
{
    delete ui;
}
