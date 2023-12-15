#include "studentinfowindow.h"
#include "ui_studentinfowindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

StudentInfoWindow::StudentInfoWindow(QWidget *parent, QString userName) :
    QMainWindow(parent),
    ui(new Ui::StudentInfoWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("教务管理系统—学生登录");

    //侧边栏
    // QListWidget sidebar;
    ui->sidebar->setGeometry(10,10,120,1000);
    ui->sidebar->addItem("个人信息");
    ui->sidebar->addItem("课程安排");
    ui->sidebar->addItem("选课");
    ui->sidebar->addItem("个人成绩");
    QFont font = ui->sidebar->font();
    font.setPointSize(14);
    ui->sidebar->setFont(font);

    //页面
    // QStackedWidget contentStack;

    QWidget *page1 = createPage1(userName);
    QWidget *page2 = createPage2(userName);
    QWidget *page3 = createPage3(userName);
    QWidget *page4 = createPage4(userName);

    ui->contentStack->removeWidget(ui->page);
    ui->contentStack->removeWidget(ui->page_2);
    ui->contentStack->addWidget(page1);
    ui->contentStack->addWidget(page2);
    ui->contentStack->addWidget(page3);
    ui->contentStack->addWidget(page4);

    connect(ui->sidebar, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        int index = ui->sidebar->row(item);
        ui->contentStack->setCurrentIndex(index);
    });

    setCentralWidget(ui->contentStack);

    ui->sidebar->setParent(this);
    ui->contentStack->setParent(this);
}

StudentInfoWindow::~StudentInfoWindow()
{
    delete ui;
}

QWidget *StudentInfoWindow::createPage1(QString &userName)
{
    QWidget *page = new QWidget;
    page->resize(500, 400);
    QGridLayout *layout = new QGridLayout(page);
    QLabel *nameL = new QLabel("姓名");
    QLabel *name = new QLabel(userName);
    QPushButton *exit = new QPushButton("退出登录");
    QFont font("Arial", 20);
    nameL->setFont(font);
    name->setFont(font);
    nameL->setFixedSize(150, 100);
    name->setFixedSize(150, 100);
    QSpacerItem *horizontalSpacer = new QSpacerItem(10, 0);
    layout->addItem(horizontalSpacer, 0, 0);
    layout->addItem(horizontalSpacer, 0, 1);
    layout->addItem(horizontalSpacer, 0, 2);
    layout->addWidget(nameL, 0, 4);
    layout->addWidget(name, 0, 5);
    layout->addItem(horizontalSpacer, 1, 0);
    layout->addItem(horizontalSpacer, 1, 1);
    layout->addItem(horizontalSpacer, 1, 2);
    layout->addItem(horizontalSpacer, 1, 3);
    layout->addWidget(exit, 1, 4);
    layout->setRowStretch(0,1);
    return page;
}

QWidget *StudentInfoWindow::createPage2(QString &userName)
{
    QWidget *page = new QWidget;
    page->resize(500, 400);
    QVBoxLayout *layout = new QVBoxLayout(page);
    QHBoxLayout *layout2 = new QHBoxLayout(page);

    layout2->addLayout(layout);

    QLabel *nameL = new QLabel("姓名");
    QLabel *name = new QLabel(userName);
    QPushButton *exit = new QPushButton("退出登录");
    QFont font("Arial", 20);
    nameL->setFont(font);
    name->setFont(font);
    nameL->setFixedSize(150, 100);
    name->setFixedSize(150, 100);

    layout->addWidget(nameL);
    layout->addWidget(name);
    layout2->addWidget(exit);

    layout2->setAlignment(layout, Qt::AlignHCenter);
    return page;
}

QWidget *StudentInfoWindow::createPage3(QString &userName)
{
    QWidget *page = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(page);
    return page;
}

QWidget *StudentInfoWindow::createPage4(QString &userName)
{
    QWidget *page = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(page);
    return page;
}
