#include "scoremanagewindow.h"
#include "ui_scoremanagewindow.h"

ScoreManageWindow::ScoreManageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreManageWindow)
{
    ui->setupUi(this);
}

ScoreManageWindow::~ScoreManageWindow()
{
    delete ui;
}
