#include "courseaddform.h"
#include "Course.h"
#include "mysqlconnector.h"
#include "ui_courseaddform.h"

#include <QMessageBox>

CourseAddForm::CourseAddForm(QWidget *parent)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::CourseAddForm)
{
    ui->setupUi(this);

    connect(ui->submit, &QPushButton::clicked, this, [&](){
        submitBtnClick(ui);
    });
}

CourseAddForm::~CourseAddForm()
{
    delete ui;
}

void CourseAddForm::submitBtnClick(Ui::CourseAddForm *ui)
{
    MySqlConnector *conn = new MySqlConnector;

    if(!conn->DataBaseConnect())
    {
        qDebug() << "数据库连接失败！";
        return;
    }

    QString sql;
    QSqlQuery query;

    Course *course = new Course(ui->courseid->toPlainText(),
                                ui->coursename->toPlainText(),
                                ui->coursescore->toPlainText().toFloat(),
                                ui->courseperiod->toPlainText().toInt());

    sql = "SELECT * FROM courseinfo WHERE courseid = '" + course->getCourseID() + "'";
    if(!conn->DataBaseOut(query, sql))
    {
        qDebug() << "读取失败！";
        return;
    }

    if(query.next())
    {
        QStringList columns;
        QList<QVariantList> dataset;
        QVariantList data;
        columns << "courseid" << "name" << "coursescore" << "courseperiod";
        data << course->getCourseID() << course->getName() << course->getCourseScore() << course->getCoursePeriod();
        dataset << data;
        if(!conn->DataBaseIn("courseinfo", columns, dataset))
        {
            qDebug() << "存储失败！";
            return;
        }
        else
        {
            QMessageBox::information(this, "提示", "存储成功！", QMessageBox::Ok);
        }
    }
    else
    {
        QMessageBox::information(this, "提示", "此课程号已存在！", QMessageBox::Ok);
    }
}
