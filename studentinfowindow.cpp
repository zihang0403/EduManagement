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
    // QListWidget sidebar;
    ui->sidebar->addItem("个人信息");
    ui->sidebar->addItem("课程安排");
    ui->sidebar->addItem("选课");
    ui->sidebar->addItem("个人成绩");


    //页面
    // QStackedWidget contentStack;

    QWidget *page1 = createPage1();
    QWidget *page2 = createPage2();
    QWidget *page3 = createPage3();
    QWidget *page4 = createPage4();

    ui->contentStack->addWidget(page1);
    ui->contentStack->addWidget(page2);
    ui->contentStack->addWidget(page3);
    ui->contentStack->addWidget(page4);

    connect(ui->sidebar, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        int index = ui->sidebar->row(item);
        ui->contentStack->setCurrentIndex(index);
    });

    setCentralWidget(ui->contentStack);

}

StudentInfoWindow::~StudentInfoWindow()
{
    delete ui;
}

QWidget *StudentInfoWindow::createPage1()
{
    QWidget *page = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(page);
    return page;
}

QWidget *StudentInfoWindow::createPage2()
{
    QWidget *page = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(page);
    return page;
}

QWidget *StudentInfoWindow::createPage3()
{
    QWidget *page = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(page);
    return page;
}

QWidget *StudentInfoWindow::createPage4()
{
    QWidget *page = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(page);
    return page;
}
