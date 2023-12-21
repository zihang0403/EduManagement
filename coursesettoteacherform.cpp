#include "coursesettoteacherform.h"
#include "ui_coursesettoteacherform.h"

CourseSetToTeacherForm::CourseSetToTeacherForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CourseSetToTeacherForm)
{
    ui->setupUi(this);
}

CourseSetToTeacherForm::~CourseSetToTeacherForm()
{
    delete ui;
}
