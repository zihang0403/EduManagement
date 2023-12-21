#include "CourseSet.h"
#include "coursesettoteacherform.h"
#include "mysqlconnector.h"
#include "ui_coursesettoteacherform.h"

#include <QMessageBox>

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
                ui->teachername->addItem(query.value("name").toString());
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

        QStringList endTime;
        endTime << "9:40"
                << "11:40"
                << "15:40"
                << "17:40";
        ui->endtime->addItems(endTime);

        connect(ui->starttime, &QComboBox::currentIndexChanged, this, [=](int currentIndex){
            ui->endtime->setCurrentIndex(currentIndex);
        });

        QStringList classroom;
        classroom << "A101" << "A102" << "A103" << "A104" << "A201" << "A202" << "B301" << "C106" << "D417";
        ui->classroom->addItems(classroom);

        connect(ui->submit, &QPushButton::clicked, this, [=](){
            submitBtnClick(ui, teacher);
        });

    }
    else
    {
        qDebug() << "数据库连接失败！";
    }
    delete conn;
}

CourseSetToTeacherForm::~CourseSetToTeacherForm()
{
    delete ui;
}

void CourseSetToTeacherForm::submitBtnClick(Ui::CourseSetToTeacherForm *ui, Teacher *teacher)
{
    CourseSet *course = new CourseSet(
        ui->coursename->currentText(),
        QString(),
        ui->teachername->currentText(),
        ui->courseweekday->currentText(),
        ui->starttime->currentText(),
        ui->endtime->currentText(),
        ui->classroom->currentText());

    course->setTeacherID(teacher->getTeacherID());

    MySqlConnector *conn = new MySqlConnector;
    if(conn->DataBaseConnect())
    {
        QSqlQuery query ;
        QString sql = "SELECT courseid FROM courseinfo WHERE name = '" + course->getCourseName() + "'";
        if(conn->DataBaseOut(query, sql))
        {
            if(query.next())
            {
                course->setCourseID(query.value("courseid").toString());
            }
        }
        else
        {
            qDebug() << "查询课程号失败！";
        }

        // sql = "SELECT teacherid FROM teacherinfo WHERE name = '" + course->getTeacherName() + "'";
        // if(conn->DataBaseOut(query, sql))
        // {
        //     if(query.next())
        //     {
        //         course->setTeacherID(query.value("teacherid").toString());
        //     }
        // }
        // else
        // {
        //     qDebug() << "查询教师工号失败！";
        // }

        QString tableName = "courseset";
        QStringList columns;
        columns << "courseid" << "studentid" << "teacherid"
                << "courseweekday" << "starttime" << "endtime" << "classroom";
        QList<QVariantList> dataset;
        QVariantList data;
        data << course->getCourseID()
             << course->getStudentName()
             << course->getTeacherID()
             << course->getCourseWeekDay()
             << course->getStartTime()
             << course->getEndTime()
             << course->getClassroom();
        dataset << data;

        if(conn->DataBaseIn(tableName, columns, dataset))
        {
            QMessageBox::information(this, "提示", "添加选课成功！", QMessageBox::Ok);
            close();
        }
        else
        {
            qDebug() << "添加选课失败！";
        }
    }
    else
    {
        qDebug() << "连接数据库失败！";
    }

    delete conn;
    delete course;
}
