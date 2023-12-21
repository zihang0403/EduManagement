#include "coursesettoteacherform.h"
#include "mysqlconnector.h"
#include "ui_coursesettoteacherform.h"

CourseSetToTeacherForm::CourseSetToTeacherForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::CourseSetToTeacherForm)
{
    ui->setupUi(this);

    MySqlConnector *conn = new MySqlConnector;

    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        QString sql = "SELECT * FROM courseinfo";
        if(conn->DataBaseOut(query, sql))
        {
            while(query.next())
            {
                ui->coursename->addItem(query.value("name").toString());
            }
        }
        else
        {
            qDebug() << "读取课程列表失败！";
        }

        sql = "SELECT * FROM teacherinfo";
        if(conn->DataBaseOut(query, sql))
        {
            while(query.next())
            {
                ui->teacherid->addItem(query.value("name").toString());
            }
        }
        else
        {
            qDebug() << "读取教师列表失败！";
        }

        QStringList weekDay;
        weekDay << "Monday"
                << "Tuesday"
                << "Wednesday"
                << "Thursday"
                << "Friday"
                << "Saturday"
                << "Sunday";
        ui->courseweekday->addItems(weekDay);

        QStringList startTime;
        startTime << "8:00"
                  << "10:00"
                  << "14:00"
                  << "16:00";
        ui->starttime->addItems(startTime);

    }
    else
    {
        qDebug() << "数据库连接失败！";
    }
}

CourseSetToTeacherForm::~CourseSetToTeacherForm()
{
    delete ui;
}
