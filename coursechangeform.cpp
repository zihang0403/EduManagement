#include "coursechangeform.h"
#include "ui_coursechangeform.h"

CourseChangeForm::CourseChangeForm(QWidget *parent)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::CourseChangeForm)
{
    ui->setupUi(this);

    setParent(nullptr);
}

CourseChangeForm::~CourseChangeForm()
{
    delete ui;
}
