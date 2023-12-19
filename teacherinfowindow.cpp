#include "Course.h"
#include "Student.h"
#include "courseaddform.h"
#include "coursechangeform.h"
#include "mysqlconnector.h"
#include "teacherinfowindow.h"
#include "ui_teacherinfowindow.h"

#include <QMessageBox>


TeacherInfoWindow::TeacherInfoWindow(QWidget *parent, Teacher *teacher)
    : QMainWindow(parent)
    , ui(new Ui::TeacherInfoWindow)
{
    ui->setupUi(this);

    ui->sidebar->addItem("个人信息");
    ui->sidebar->addItem("查看学生信息");
    ui->sidebar->addItem("查看课程信息");

    createPage1(ui->contentStack->widget(0), teacher);
    createPage2(ui->contentStack->widget(1), teacher);
    createPage3(ui->contentStack->widget(2), teacher);

    connect(ui->sidebar, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        int index = ui->sidebar->row(item);
        ui->contentStack->setCurrentIndex(index);
    });

    connect(ui->exit, &QPushButton::clicked, this, [&](){
        this->close();
    });

    // 菜单栏按钮绑定打开窗口
    connect(ui->actionaddstu, &QAction::triggered, this, [&](){

    });

    //使用=正常，使用&捕获的teacher为nullptr
    connect(ui->actionaddcourse, &QAction::triggered, this, [=](){
        CourseAddForm *cAddForm = new CourseAddForm(this, teacher);
        connect(cAddForm, &CourseAddForm::courseAdded, this, [=](){
            createPage3(ui->contentStack->widget(2), teacher);
        });
        cAddForm->show();
    });

    connect(ui->actionchangecourseinfo, &QAction::triggered, this, [=](){
        CourseChangeForm *cChangeForm = new CourseChangeForm(this, teacher);
        connect(cChangeForm, &CourseChangeForm::courseChanged, this, [=](){
            createPage3(ui->contentStack->widget(2), teacher);
        });
        cChangeForm->show();
    });

}

TeacherInfoWindow::~TeacherInfoWindow()
{
    delete ui;
}

// 个人信息
void TeacherInfoWindow::createPage1(QWidget *page, Teacher *teacher)
{
    QLabel *name = page->findChild<QLabel*>("name");
    QLabel *teacherID = page->findChild<QLabel*>("teacherid");
    QLabel *position = page->findChild<QLabel*>("position");
    QLabel *institute = page->findChild<QLabel*>("institute");

    if(teacher->getStatus())
    {
        name->setText(teacher->getName());
        teacherID->setText(teacher->getTeacherID());
        position->setText(teacher->getPosition());
        institute->setText(teacher->getInstitute());
    }
}

// 查看学生信息
void TeacherInfoWindow::createPage2(QWidget *page, Teacher *teacher)
{
    // 获取页面中表格的对象
    QTableWidget *studentInfoTable = page->findChild<QTableWidget*>("studentinfotable");

    MySqlConnector *conn = new MySqlConnector;
    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败！" << Qt::endl;
        return;
    }

    QSqlQuery query;
    QString sql = "SELECT * FROM studentinfo WHERE institute = '" + teacher->getInstitute() + "'";

    if(!conn->DataBaseOut(query, sql))
    {
        qDebug() << "查询失败！" << Qt::endl;
        conn->DataBaseClose();
        return;
    }

    if(query.size() != 0)
    {
        // 设置表格的行列数
        studentInfoTable->setRowCount(query.size());
        studentInfoTable->setColumnCount(5);

        // 给表格写入列标签
        QStringList headers;
        headers << "学号" << "姓名" << "性别" << "出生日期" << "学院" ;
        studentInfoTable->setHorizontalHeaderLabels(headers);

        // 数据按行写入列标签
        for(int row = 0; row < query.size(); ++row)
        {
            query.next();//首次query为空
            Student *stu = new Student(
                query.value("studentid").toString(),
                query.value("password").toString(),
                query.value("name").toString(),
                query.value("sex").toString(),
                query.value("bornday").toDate(),
                query.value("institute").toString()
                );

            // 依次写入单个数据
            studentInfoTable->setItem(row, 0, new QTableWidgetItem(stu->getStudentID()));
            studentInfoTable->setItem(row, 1, new QTableWidgetItem(stu->getName()));
            studentInfoTable->setItem(row, 2, new QTableWidgetItem(stu->getSex()));
            studentInfoTable->setItem(row, 3, new QTableWidgetItem(stu->getbornDay().toString()));
            studentInfoTable->setItem(row, 4, new QTableWidgetItem(stu->getInstitute()));
            delete stu;
        }

        //添加数据后自动调整表格大小
        studentInfoTable->resizeRowsToContents();
        studentInfoTable->resizeColumnsToContents();
    }

    conn->DataBaseClose();
    delete conn;
}

//查看课程信息
void TeacherInfoWindow::createPage3(QWidget *page, Teacher *teacher)
{
    // 获取页面中表格的对象
    QTableWidget *courseInfoTable = page->findChild<QTableWidget*>("courseinfotable");

    MySqlConnector *conn = new MySqlConnector;
    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败！" << Qt::endl;
            return;
    }

    QSqlQuery query;
    QString sql = "SELECT * FROM courseinfo WHERE institute = '" + teacher->getInstitute() + "'";
//    QString sql = "SELECT * FROM courseinfo";
    if(!conn->DataBaseOut(query, sql))
    {
        qDebug() << "查询失败！" << Qt::endl;
        conn->DataBaseClose();
        return;
    }

    if(query.size() != 0)
    {
        // 设置表格的行列数
        courseInfoTable->setRowCount(query.size());
        courseInfoTable->setColumnCount(5);

        // 给表格写入列标签
        QStringList headers;
        headers << "课程编号" << "课程名" << "学分" << "课时" << "所属学院" ;
            courseInfoTable->setHorizontalHeaderLabels(headers);

        // 数据按行写入列标签,若无数据则跳过
        for(int row = 0; row < query.size(); ++row)
        {
            query.next();//首次query为空
            Course *course = new Course(
                query.value("courseid").toString(),
                query.value("name").toString(),
                query.value("coursescore").toFloat(),
                query.value("courseperiod").toInt(),
                query.value("institute").toString()
                );

            // 依次写入单个数据
            courseInfoTable->setItem(row, 0, new QTableWidgetItem(course->getCourseID()));
            courseInfoTable->setItem(row, 1, new QTableWidgetItem(course->getName()));
            courseInfoTable->setItem(row, 2, new QTableWidgetItem(QString::number(course->getCourseScore())));
            courseInfoTable->setItem(row, 3, new QTableWidgetItem(QString::number(course->getCoursePeriod())));
            courseInfoTable->setItem(row, 4, new QTableWidgetItem(course->getInstitute()));
            delete course;
        }

        //添加数据后自动调整表格大小
        courseInfoTable->resizeRowsToContents();
        courseInfoTable->resizeColumnsToContents();
    }
    conn->DataBaseClose();
    delete conn;
}
