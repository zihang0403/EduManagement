#include "studentinfowindow.h"
#include "ui_studentinfowindow.h"

StudentInfoWindow::StudentInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentInfoWindow)
{
    ui->setupUi(this);
}

StudentInfoWindow::~StudentInfoWindow()
{
    delete ui;
}
