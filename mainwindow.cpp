#include "mainwindow.h"
#include "ui_mainwindow.h"

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

//学生登录，打开登录窗口
void MainWindow::StuButtonClick()
{
    showLoginWindow(LoginWindow::stu);
}

//教师登录，打开相同的登录窗口，通过LoginBy的值执行不同操作
void MainWindow::ManageButtonClick()
{
    showLoginWindow(LoginWindow::teacher);
}

//打开登录窗口，并隐藏主窗口
void MainWindow::showLoginWindow(enum LoginWindow::LoginBy loginby)
{
    LoginWindow *loginWindow = new LoginWindow(this, loginby);
    this->hide();
    loginWindow->setWindowTitle(QString("教务管理系统-登录"));
    loginWindow->show();
}

//重新打开主窗口
void MainWindow::reShowMainWindow()
{
    this->show();
}

//获取当前主窗口对象并返回，用于重新打开主窗口
MainWindow *MainWindow::getInstance()
{
    static MainWindow *instance;
    return instance;
}
