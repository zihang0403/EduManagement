#include "courseaddform.h"
#include "Course.h"
#include "mysqlconnector.h"
#include "ui_courseaddform.h"

#include <QMessageBox>

CourseAddForm::CourseAddForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::CourseAddForm)
{
    ui->setupUi(this);

    connect(ui->submit, &QPushButton::clicked, this, [=](){
        submitBtnClick(ui, teacher);
    });
}

CourseAddForm::~CourseAddForm()
{
    delete ui;
}

void CourseAddForm::submitBtnClick(Ui::CourseAddForm *ui, Teacher *teacher)
{
    MySqlConnector *conn = new MySqlConnector;

    if(!conn->DataBaseConnect())
    {
        qDebug() << "数据库连接失败！";
        return;
    }

    QString sql;
    QSqlQuery query;

    if(ui->courseid->text() == QString() || ui->coursename->text() == QString()
        || ui->coursescore->text() == QString() || ui->courseid->text() == QString())
    {
        QMessageBox::information(this, "提示", "数据不能为空！", QMessageBox::Ok);
        return;
    }

    Course *course = new Course(
        ui->courseid->text(),
        ui->coursename->text(),
        ui->coursescore->text().toFloat(),
        ui->courseperoid->text().toInt(),
        teacher->getInstitute()
        );

    sql = "SELECT * FROM courseinfo WHERE courseid = '" + course->getCourseID() + "'";
    if(!conn->DataBaseOut(query, sql))
    {
        qDebug() << "读取失败！";
        conn->DataBaseClose();
        delete conn;
        return;
    }

    if(!query.next())
    {
        QStringList columns;
        QList<QVariantList> dataset;
        QVariantList data;
        columns << "courseid" << "name" << "coursescore" << "courseperiod" << "institute";
        data << course->getCourseID() << course->getName() << course->getCourseScore() << course->getCoursePeriod() << course->getInstitute();
        dataset << data;
        if(!conn->DataBaseIn("courseinfo", columns, dataset))
        {
            qDebug() << "添加失败！";
        }
        else
        {
            QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Ok);
            emit courseAdded();
            close();
        }
    }
    else
    {
        QMessageBox::information(this, "提示", "此课程号已存在！", QMessageBox::Ok);
    }
    conn->DataBaseClose();
    delete conn;
}
