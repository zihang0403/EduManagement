#include "scoreinfowindow.h"
#include "ui_scoreinfowindow.h"

ScoreInfoWindow::ScoreInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreInfoWindow)
{
    ui->setupUi(this);
}

ScoreInfoWindow::~ScoreInfoWindow()
{
    delete ui;
}
