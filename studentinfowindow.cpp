#include "studentinfowindow.h"
#include "ui_studentinfowindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

StudentInfoWindow::StudentInfoWindow(QWidget *parent, Student *student) :
    QMainWindow(parent),
    ui(new Ui::StudentInfoWindow)
{
    ui->setupUi(this);

    //侧边栏添加标签
    ui->sidebar->addItem("个人信息");
    ui->sidebar->addItem("课程安排");
    ui->sidebar->addItem("选课");
    ui->sidebar->addItem("个人成绩");

    // 给分页的每一页分别添加内容
    createPage1(ui->contentStack->widget(0), student);
    createPage2(ui->contentStack->widget(1), student);
    createPage3(ui->contentStack->widget(2), student);
    createPage4(ui->contentStack->widget(3), student);


    // 绑定侧边栏的标签索引号和分页的页数使得点击侧边栏标签后分页页面随之跳转
    connect(ui->sidebar, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        int index = ui->sidebar->row(item);
        ui->contentStack->setCurrentIndex(index);
    });

    // 退出按钮绑定关闭窗口
    connect(ui->exit, &QPushButton::clicked, this, [&](){
        this->close();
    });

}

StudentInfoWindow::~StudentInfoWindow()
{
    delete ui;
}

// 个人信息
void StudentInfoWindow::createPage1(QWidget *page, Student *student)
{
    // 获取页面中的标签
    QLabel *name = page->findChild<QLabel*>("name");
    QLabel *studentID = page->findChild<QLabel*>("studentid");
    QLabel *institute = page->findChild<QLabel*>("institute");

    if(student->getStatus())
    {
        // 给标签写入数据
        name->setText(student->getName());
        studentID->setText(student->getStudentID());
        institute->setText(student->getInstitute());
    }
}

void StudentInfoWindow::createPage2(QWidget *page, Student *student)
{

}

void StudentInfoWindow::createPage3(QWidget *page, Student *student)
{
    QVBoxLayout *layout = new QVBoxLayout(page);

}

void StudentInfoWindow::createPage4(QWidget *page, Student *student)
{
    QVBoxLayout *layout = new QVBoxLayout(page);
}
