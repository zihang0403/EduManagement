#include "studentinfowindow.h"
#include "ui_studentinfowindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QVBoxLayout>

StudentInfoWindow::StudentInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentInfoWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("教务管理系统—学生登录");

    //侧边栏
    QListWidget sidebar;
    sidebar.addItem("个人信息");
    sidebar.addItem("课程安排");
    sidebar.addItem("选课");
    sidebar.addItem("个人成绩");

    //页面
    QStackedWidget contentStack;

    QLabel *page1 = new QLabel("个人信息");
    QLabel *page2 = new QLabel("课程安排");
    QLabel *page3 = new QLabel("选课");
    QLabel *page4 = new QLabel("个人成绩");

    contentStack.addWidget(page1);
    contentStack.addWidget(page2);
    contentStack.addWidget(page3);
    contentStack.addWidget(page4);

    connect(&sidebar, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        int index = sidebar.row(item);
        contentStack.setCurrentIndex(index);
    });

    sidebar.setParent(this);
    contentStack.setParent(this);
}

StudentInfoWindow::~StudentInfoWindow()
{
    delete ui;
}
