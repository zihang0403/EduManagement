#include "CourseSet.h"
#include "mysqlconnector.h"
#include "studentinfowindow.h"
#include "ui_studentinfowindow.h"

#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

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

    connect(ui->coursesettable, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem *item){
        QTableWidgetItem *notes = ui->coursesettable->item(item->row(), 5);
        QTableWidgetItem *courseName = ui->coursesettable->item(item->row(), 0);
        QTableWidgetItem *teacherName = ui->coursesettable->item(item->row(), 1);

        if(notes->text() != "已选")
        {
            CourseSelect(courseName, teacherName, student);
            createPage2(ui->contentStack->widget(1), student);
            createPage3(ui->contentStack->widget(2), student);
        }

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

//课程安排
void StudentInfoWindow::createPage2(QWidget *page, Student *student)
{
    // 获取页面中表格的对象
    QTableWidget *courseTimeTable = page->findChild<QTableWidget*>("coursetimetable");

    // 设置表格行列数
    courseTimeTable->setColumnCount(5);
    courseTimeTable->setRowCount(7);

    // 设置表格行列标
    QStringList columnHeaders;
    QStringList rowHeaders;
    rowHeaders << "Monday"
                  << "Tuesday"
                  << "Wednesday"
                  << "Thursday"
                  << "Friday"
                  << "Saturday"
                  << "Sunday";
    columnHeaders << "8:00" << "10:00" << "午休" << "14:00" << "16:00";
    courseTimeTable->setHorizontalHeaderLabels(columnHeaders);
    courseTimeTable->setVerticalHeaderLabels(rowHeaders);

    MySqlConnector *conn = new MySqlConnector;
    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败！" << Qt::endl;
            return;
    }

    QSqlQuery query;
    QString sql = "SELECT * FROM courseset WHERE studentid = '" + student->getStudentID() + "'";

    // 查学生的课程安排
    if(conn->DataBaseOut(query, sql))
    {
        while(query.next())
        {
            //存放选课相关的信息
            CourseSet *courseSet = new CourseSet(
                query.value("courseid").toString(),
                query.value("studentid").toString(),
                query.value("teacherid").toString(),
                query.value("coursename").toString(),
                query.value("studentname").toString(),
                query.value("teachername").toString(),
                query.value("courseweekday").toString(),
                query.value("starttime").toTime().toString("hh:mm"),
                query.value("endtime").toTime().toString("hh:mm"),
                query.value("classroom").toString());

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
            courseTableWidgetItem->setText("课程：" + courseSet->getCourseName() +
                                           "\n教室：" + courseSet->getClassroom() +
                                           "\n授课教师：" + courseSet->getTeacherName());
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

//选课
void StudentInfoWindow::createPage3(QWidget *page, Student *student)
{
    // 获取页面中表格的对象
    QTableWidget *courseTimeTable = page->findChild<QTableWidget*>("coursesettable");

    courseTimeTable->setColumnCount(6);

    QStringList headers;
    headers << "课程"
            << "授课教师"
            << "上课日期"
            << "起止时间"
            << "教室"
            << "备注";

    courseTimeTable->setHorizontalHeaderLabels(headers);

    MySqlConnector *conn = new MySqlConnector;

    if(conn->DataBaseConnect())
    {
        int offset = 0;
        bool courseSetFlag = true;
        QSqlQuery query;
        QString sql = "SELECT * FROM courseset WHERE studentid IS NULL OR studentid = '" + student->getStudentID() + "'";
        if(conn->DataBaseOut(query, sql))
        {
            courseTimeTable->setRowCount(query.size());
            for(int row = 0; row < query.size(); ++row)
            {
                query.next();
                QSqlQuery querytmp;
                sql = "SELECT * FROM courseset WHERE studentid = '" + student->getStudentID() + "'";
                if(conn->DataBaseOut(querytmp, sql))
                {
                    while(querytmp.next())
                    {
                        courseSetFlag = true;
                        if(query.value("courseid").toString() == querytmp.value("courseid").toString())
                        {
                            if(query.value("studentid").toString().isEmpty())
                            {
                                --offset;
                            }
                            courseSetFlag = false;
                            break;
                        }
                    }
                    if(courseSetFlag || !query.value("studentid").toString().isEmpty())
                    {
                        CourseSet *courseSet = new CourseSet(
                            query.value("courseid").toString(),
                            query.value("studentid").toString(),
                            query.value("teacherid").toString(),
                            query.value("coursename").toString(),
                            query.value("studentname").toString(),
                            query.value("teachername").toString(),
                            query.value("courseweekday").toString(),
                            query.value("starttime").toTime().toString("hh:mm"),
                            query.value("endtime").toTime().toString("hh:mm"),
                            query.value("classroom").toString());

                        QTableWidgetItem *courseName = new QTableWidgetItem;
                        QTableWidgetItem *teacherName = new QTableWidgetItem;
                        QTableWidgetItem *courseWeekday = new QTableWidgetItem;
                        QTableWidgetItem *courseTime = new QTableWidgetItem;
                        QTableWidgetItem *classroom = new QTableWidgetItem;
                        QTableWidgetItem *notes = new QTableWidgetItem;

                        courseName->setText(courseSet->getCourseName());
                        teacherName->setText(courseSet->getTeacherName());
                        courseWeekday->setText(courseSet->getCourseWeekDay());
                        courseTime->setText(courseSet->getStartTime() + "-" + courseSet->getEndTime());
                        classroom->setText(courseSet->getClassroom());

                        if(courseSet->getStudentID() == student->getStudentID())
                        {
                            notes->setText("已选");
                        }

                        courseTimeTable->setItem(row + offset, 0, courseName);
                        courseTimeTable->setItem(row + offset, 1, teacherName);
                        courseTimeTable->setItem(row + offset, 2, courseWeekday);
                        courseTimeTable->setItem(row + offset, 3, courseTime);
                        courseTimeTable->setItem(row + offset, 4, classroom);
                        courseTimeTable->setItem(row + offset, 5, notes);

                        delete courseSet;
                    }
                }
            }

            courseTimeTable->resizeColumnsToContents();
            courseTimeTable->resizeRowsToContents();
        }
        else
        {
            qDebug() << "查询选课信息失败！";
        }
    }
    else
    {
        qDebug() << "数据库连接失败！";
    }

    delete conn;

}

void StudentInfoWindow::createPage4(QWidget *page, Student *student)
{
    // 获取页面中表格的对象
    QTableWidget *scoreInfoTable = page->findChild<QTableWidget*>("scoreinfotable");

    scoreInfoTable->setColumnCount(4);

    QStringList headers;
    headers << "课程" << "学生" << "教师" << "成绩";
    scoreInfoTable->setHorizontalHeaderLabels(headers);

    MySqlConnector *conn = new MySqlConnector;
    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        QString sql = "SELECT * FROM courseset WHERE studentid = '" + student->getStudentID() + "'";
        if(conn->DataBaseOut(query, sql))
        {
            scoreInfoTable->setRowCount(query.size());

            for (int row = 0; row < query.size(); ++row)
            {
                query.next();
                CourseSet *courseSet = new CourseSet(
                    query.value("courseid").toString(),
                    query.value("studentid").toString(),
                    query.value("teacherid").toString(),
                    query.value("coursename").toString(),
                    query.value("studentname").toString(),
                    query.value("teachername").toString(),
                    query.value("courseweekday").toString(),
                    query.value("starttime").toTime().toString("hh:mm"),
                    query.value("starttime").toTime().toString("hh:mm"),
                    query.value("classroom").toString());

                QTableWidgetItem *cName = new QTableWidgetItem;
                QTableWidgetItem *sName = new QTableWidgetItem;
                QTableWidgetItem *tName = new QTableWidgetItem;
                QTableWidgetItem *score = new QTableWidgetItem;

                cName->setText(courseSet->getCourseName());
                sName->setText(courseSet->getStudentName());
                tName->setText(courseSet->getTeacherName());
                score->setText(query.value("score").toString());

                cName->setFlags(cName->flags() & ~Qt::ItemIsEditable);
                score->setFlags(score->flags() | Qt::ItemIsEditable);

                scoreInfoTable->setItem(row, 0, cName);
                scoreInfoTable->setItem(row, 1, sName);
                scoreInfoTable->setItem(row, 2, tName);
                scoreInfoTable->setItem(row, 3, score);

                delete courseSet;

            }//for (int row = 0; row < query.size(); ++row)

        }//if(conn->DataBaseOut(query, sql))
        else
        {
            qDebug() << "查询成绩失败！";
        }
    }
    else
    {
        qDebug() << "数据库连接失败！";
    }
    delete conn;

}

void StudentInfoWindow::CourseSelect(QTableWidgetItem *courseName, QTableWidgetItem *teacherName, Student *student)
{
    MySqlConnector *conn = new MySqlConnector;

    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        QString sql = "SELECT * FROM courseset WHERE coursename = '" +
                      courseName->text() + "' AND teachername = '" +
                      teacherName->text() + "' AND studentid IS NULL";
        if(conn->DataBaseOut(query, sql))
        {
            if(query.next())
            {
                CourseSet *courseSet = new CourseSet(
                    query.value("courseid").toString(),
                    query.value("studentid").toString(),
                    query.value("teacherid").toString(),
                    query.value("coursename").toString(),
                    query.value("studentname").toString(),
                    query.value("teachername").toString(),
                    query.value("courseweekday").toString(),
                    query.value("starttime").toTime().toString("hh:mm"),
                    query.value("endtime").toTime().toString("hh:mm"),
                    query.value("classroom").toString());

                QString tableName = "courseSet";
                QStringList columns;
                columns << "courseid"
                        << "coursename"
                        << "studentid"
                        << "studentname"
                        << "teacherid"
                        << "teachername"
                        << "courseweekday"
                        << "starttime"
                        << "endtime"
                        << "classroom";
                QList<QVariantList> dataset;
                QVariantList data;
                data << courseSet->getCourseID()
                     << courseSet->getCourseName()
                     << student->getStudentID()
                     << student->getName()
                     << courseSet->getTeacherID()
                     << courseSet->getTeacherName()
                     << courseSet->getCourseWeekDay()
                     << courseSet->getStartTime()
                     << courseSet->getEndTime()
                     << courseSet->getClassroom();
                dataset << data;

                if(conn->DataBaseIn(tableName, columns, dataset))
                {
                    QMessageBox::information(this, "提示", "选课成功！");
                }
                else
                {
                    qDebug() << "选课失败！";
                }
                delete courseSet;
            }
        }
        else
        {
            qDebug() << "查询选课信息失败！";
        }
    }
    else
    {
        qDebug() << "数据库连接失败！";
    }
    delete conn;
}
