#include "Course.h"
#include "CourseSet.h"
#include "Student.h"
#include "courseaddform.h"
#include "coursechangeform.h"
#include "coursedeleteform.h"
#include "coursesettoteacherform.h"
#include "mysqlconnector.h"
#include "scoremanageform.h"
#include "studentaddform.h"
#include "studentchangeform.h"
#include "studentdeleteform.h"
#include "teacherinfowindow.h"
#include "ui_teacherinfowindow.h"

#include <QMessageBox>


TeacherInfoWindow::TeacherInfoWindow(QWidget *parent, Teacher *teacher)
    : QMainWindow(parent)
    , ui(new Ui::TeacherInfoWindow)
{
    ui->setupUi(this);

    ui->sidebar->addItem("个人信息");
    ui->sidebar->addItem("学生信息");
    ui->sidebar->addItem("课程信息");
    ui->sidebar->addItem("课程安排");

    createPage1(ui->contentStack->widget(0), teacher);
    createPage2(ui->contentStack->widget(1), teacher);
    createPage3(ui->contentStack->widget(2), teacher);
    createPage4(ui->contentStack->widget(3), teacher);

    connect(ui->sidebar, &QListWidget::itemClicked, this, [&](QListWidgetItem *item){
        int index = ui->sidebar->row(item);
        ui->contentStack->setCurrentIndex(index);
    });

    connect(ui->exit, &QPushButton::clicked, this, [=](){
        this->close();
    });

    // 菜单栏按钮绑定打开窗口
    // 使用=捕获的对象正常，使用&捕获的teacher为nullptr

    // 添加学生
    connect(ui->actionaddstu, &QAction::triggered, this, [=](){
        StudentAddForm *sAddForm = new StudentAddForm(this, teacher);
        connect(sAddForm, &StudentAddForm::StudentAdded, this, [=](){
            createPage2(ui->contentStack->widget(1), teacher);
        });
        sAddForm->show();
    });

    // 修改学生信息
    connect(ui->actionchangestuinfo, &QAction::triggered, this, [=](){
        StudentChangeForm *sChangeForm = new StudentChangeForm(this, teacher);
        connect(sChangeForm, &StudentChangeForm::studentChanged, this, [=](){
            createPage2(ui->contentStack->widget(1), teacher);
        });
        sChangeForm->show();
    });

    // 删除学生
    connect(ui->actiondeletestu, &QAction::triggered, this, [=](){
        StudentDeleteForm *sDeleteForm = new StudentDeleteForm(this, teacher);
        connect(sDeleteForm, &StudentDeleteForm::studentDeleted, this, [=](){
            createPage2(ui->contentStack->widget(1), teacher);
        });
        sDeleteForm->show();
    });


    // 添加课程
    connect(ui->actionaddcourse, &QAction::triggered, this, [=](){
        CourseAddForm *cAddForm = new CourseAddForm(this, teacher);
        connect(cAddForm, &CourseAddForm::courseAdded, this, [=](){
            createPage3(ui->contentStack->widget(2), teacher);
        });
        cAddForm->show();
    });

    // 修改课程信息
    connect(ui->actionchangecourseinfo, &QAction::triggered, this, [=](){
        CourseChangeForm *cChangeForm = new CourseChangeForm(this, teacher);
        connect(cChangeForm, &CourseChangeForm::courseChanged, this, [=](){
            createPage3(ui->contentStack->widget(2), teacher);
        });
        cChangeForm->show();
    });

    // 删除课程
    connect(ui->actiondeletecourse, &QAction::triggered, this, [=](){
        CourseDeleteForm *cDeleteForm = new CourseDeleteForm(this, teacher);
        connect(cDeleteForm, &CourseDeleteForm::courseDeleted, this, [=](){
            createPage3(ui->contentStack->widget(2), teacher);
        });
        cDeleteForm->show();
    });

    // 添加选课
    connect(ui->actioncourseset, &QAction::triggered, this, [=](){
        CourseSetToTeacherForm *cSetToTea = new CourseSetToTeacherForm(this, teacher);
        connect(cSetToTea, &CourseSetToTeacherForm::courseSetUpdated, this, [=](){
            createPage4(ui->contentStack->widget(3), teacher);
        });
        cSetToTea->show();
    });

    // 成绩管理
    connect(ui->actionscoreset, &QAction::triggered, this, [=](){
        ScoreManageForm *sManageForm = new ScoreManageForm(this, teacher);
        sManageForm->show();
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

//查看课程表
void TeacherInfoWindow::createPage4(QWidget *page, Teacher *teacher)
{
    // 获取页面中表格的对象
    QTableWidget *courseTimeTable = page->findChild<QTableWidget*>("coursetimetable");

    // 设置表格行列数
    courseTimeTable->setColumnCount(5);
    courseTimeTable->setRowCount(7);

    // 设置表格行列标
    QStringList columnHeaders;
    QStringList rowHeaders;
    columnHeaders << "Monday"
                  << "Tuesday"
                  << "Wednesday"
                  << "Thursday"
                  << "Friday"
                  << "Saturday"
                  << "Sunday";
    rowHeaders << "08:00" << "10:00" << "午休" << "14:00" << "16:00";
    courseTimeTable->setHorizontalHeaderLabels(rowHeaders);
    courseTimeTable->setVerticalHeaderLabels(columnHeaders);

    MySqlConnector *conn = new MySqlConnector;
    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败！" << Qt::endl;
            return;
    }

    QSqlQuery query;
    QString sql = "SELECT * FROM courseset WHERE teacherid = '" + teacher->getTeacherID() + "'";

    // 查教师的授课信息
    if(conn->DataBaseOut(query, sql))
    {
        while(query.next())
        {
            //存放选课相关的信息
            CourseSet *courseSet = new CourseSet(
                query.value("courseid").toString(),
                QString(),
                query.value("teacherid").toString(),
                QString(),
                QString(),
                teacher->getName(),
                query.value("courseweekday").toString(),
                query.value("starttime").toTime().toString("hh:mm"),
                query.value("endtime").toTime().toString("hh:mm"),
                query.value("classroom").toString());

            // 通过课程号查询课程名
            QSqlQuery querytmp ;
            sql = "SELECT name FROM courseinfo WHERE courseid = '" + query.value("courseid").toString() + "'";

            if(conn->DataBaseOut(querytmp, sql))
            {
                if(querytmp.next())
                {
                    // 添加到courseSet 对象中
                    courseSet->setCourseName(querytmp.value("name").toString());
                }
            }
            else
            {
                qDebug() << "查询课程名失败！";
            }

            // 查行标中与选课开始时间相同的行
            int row;
            for (row = 0; row < courseTimeTable->rowCount(); ++row) {
                QTableWidgetItem *rowHeader = courseTimeTable->verticalHeaderItem(row);
                if(rowHeader->text() == courseSet->getCourseWeekDay())
                {
                    break;
                }
            }

            // 查列标中与上课周相同的列
            int column;
            for (column = 0; column < courseTimeTable->columnCount(); ++column) {
                QTableWidgetItem *columnHeader = courseTimeTable->horizontalHeaderItem(column);
                if(columnHeader->text() == courseSet->getStartTime())
                {
                    break;
                }
            }

            // 将课程名放入对应的行列的位置
            QTableWidgetItem *courseTableWidgetItem = new QTableWidgetItem;
            courseTableWidgetItem->setText("课程：" + courseSet->getCourseName() + "\n教室：" + courseSet->getClassroom());
            courseTimeTable->setItem(row, column, courseTableWidgetItem);

            delete courseSet;
        }
    }
    else
    {
        qDebug() << "查询课程表失败！";
    }

    // 自动调整大小
    courseTimeTable->resizeRowsToContents();
    courseTimeTable->resizeColumnsToContents();

    conn->DataBaseClose();
    delete conn;
}

