#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //进入学生操作界面
    connect(ui->StuButton, &QPushButton::clicked, this, &MainWindow::StuButtonClick);
    //进入教师操作界面
    connect(ui->ManageButton, &QPushButton::clicked, this, &MainWindow::ManageButtonClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StuButtonClick()
{
    LoginWindow *loginWindow = new LoginWindow(this);
    this->hide();
    loginWindow->show();
}

