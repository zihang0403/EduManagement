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
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::loginBtnClick()
{
    qDebug()<<"whatf";
}
