#include "Course.h"
#include "coursechangeform.h"
#include "mysqlconnector.h"
#include "ui_coursechangeform.h"

#include <QMessageBox>

CourseChangeForm::CourseChangeForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::CourseChangeForm)
{
    ui->setupUi(this);

    connect(ui->submit, &QPushButton::clicked, this, [=](){
        submitBtnClick(ui, teacher);
    });
}

CourseChangeForm::~CourseChangeForm()
{
    delete ui;
}

void CourseChangeForm::submitBtnClick(Ui::CourseChangeForm *ui, Teacher *teacher)
{
    MySqlConnector *conn = new MySqlConnector;
    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败";
        return;
    }

    QSqlQuery query;

    //开始查询
    if(ui->submit->text() == "查询")
    {


        QString sql = "SELECT * FROM courseinfo WHERE courseid = '" + ui->courseid->text() + "'";

        if(conn->DataBaseOut(query, sql))
        {
            if(query.next())
            {
                ui->courseid->setDisabled(true);
                ui->coursename->setDisabled(false);
                ui->coursescore->setDisabled(false);
                ui->courseperiod->setDisabled(false);
                ui->submit->setText("确认修改");
                ui->coursename->setText(query.value("name").toString());
                ui->coursescore->setText(query.value("coursescore").toString());
                ui->courseperiod->setText(query.value("courseperiod").toString());
            }
            else
            {
                QMessageBox::information(this, "提示", "未查找到课程", QMessageBox::Ok);
            }
        }
    }
    else    //查询后修改数据
    {
        Course *course = new Course(
            ui->courseid->text(),
            ui->coursename->text(),
            ui->coursescore->text().toFloat(),
            ui->courseperiod->text().toInt(),
            teacher->getInstitute()
            );
        QString sql = "UPDATE courseinfo SET name = '" + course->getName()
                    + "', coursescore = " + QString::number(course->getCourseScore())
                    + ", courseperiod = " + QString::number(course->getCoursePeriod())
                    + " WHERE courseid = '" + course->getCourseID() + "'";
        if(conn->DataBaseOut(query, sql))
        {
            QMessageBox::information(this, "提示", "修改成功！", QMessageBox::Ok);
            emit courseChanged();
            close();
        }
        else
        {
            QMessageBox::information(this, "提示", "修改失败！", QMessageBox::Ok);
        }

        delete course;
    }
    delete conn;
}
