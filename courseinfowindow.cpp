#include "courseinfowindow.h"
#include "ui_courseinfowindow.h"

CourseInfoWindow::CourseInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourseInfoWindow)
{
    ui->setupUi(this);
}

CourseInfoWindow::~CourseInfoWindow()
{
    delete ui;
}
