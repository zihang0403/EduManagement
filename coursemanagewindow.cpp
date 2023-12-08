#include "coursemanagewindow.h"
#include "ui_coursemanagewindow.h"

CourseManageWindow::CourseManageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourseManageWindow)
{
    ui->setupUi(this);
}

CourseManageWindow::~CourseManageWindow()
{
    delete ui;
}
