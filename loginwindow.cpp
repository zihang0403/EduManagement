#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QPushButton>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent, enum LoginBy loginBy) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::loginBtnClick);

    ui->loginWindowLable->setText(
        (loginBy== LoginWindow::stu) ?
        "同学你好！请登录！如无账户请联系教师添加" :
        "教师你好！请登录！如无账户请联系管理员"
        );

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::loginBtnClick()
{
    qDebug()<<"whatf";
}

