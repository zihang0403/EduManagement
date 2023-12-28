#include "CourseSet.h"
#include "mysqlconnector.h"
#include "scoremanageform.h"
#include "ui_scoremanageform.h"

#include <QMessageBox>

ScoreManageForm::ScoreManageForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::ScoreManageForm)
{
    ui->setupUi(this);

    ui->scoremanagetable->setColumnCount(4);

    QStringList headers;
    headers << "课程" << "学生" << "教师" << "成绩";
    ui->scoremanagetable->setHorizontalHeaderLabels(headers);

    MySqlConnector *conn = new MySqlConnector;
    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        QString sql = "SELECT * FROM courseset WHERE teacherid = '" + teacher->getTeacherID() + "' AND studentid IS NOT NULL";
        if(conn->DataBaseOut(query, sql))
        {
            ui->scoremanagetable->setRowCount(query.size());
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
                    sName->setFlags(sName->flags() & ~Qt::ItemIsEditable);
                    tName->setFlags(tName->flags() & ~Qt::ItemIsEditable);
                    score->setFlags(score->flags() | Qt::ItemIsEditable);

                    ui->scoremanagetable->setItem(row, 0, cName);
                    ui->scoremanagetable->setItem(row, 1, sName);
                    ui->scoremanagetable->setItem(row, 2, tName);
                    ui->scoremanagetable->setItem(row, 3, score);

                    delete courseSet;

                }//for (int row = 0; row < query.size(); ++row)

        }//if(conn->DataBaseOut(query, sql))
        else
        {
            qDebug() << "查询选课表失败！";
        }
    }
    else
    {
        qDebug() << "数据库连接失败！";
    }
    delete conn;

    connect(ui->submit, &QPushButton::clicked, this, [=](){
        submitBtnClick(ui, teacher);
    });
}

ScoreManageForm::~ScoreManageForm()
{
    delete ui;
}

void ScoreManageForm::submitBtnClick(Ui::ScoreManageForm *ui, Teacher *teacher)
{
    QStringList courseNames;
    QStringList studentNames;
    QStringList scores;

    for (int row = 0; row < ui->scoremanagetable->rowCount(); ++row)
    {
        QTableWidgetItem *courseName = ui->scoremanagetable->item(0, 0);
        QTableWidgetItem *studentName = ui->scoremanagetable->item(0, 1);
        QTableWidgetItem *score = ui->scoremanagetable->item(0, 3);

        courseNames << courseName->text();
        studentNames << studentName->text();
        scores << score->text();
    }

    MySqlConnector *conn = new MySqlConnector;
    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        for (int var = 0; var < ui->scoremanagetable->rowCount(); ++var) {
            QString sql = "UPDATE courseset SET score = '" + scores[var] +
                          "' WHERE courseName = '" + courseNames[var] +
                          "' AND studentName = '" + studentNames[var] +
                          "' ";
            if(!conn->DataBaseOut(query, sql))
            {
                qDebug() << "更新courseset表失败！";
                delete conn;
                return;
            }
        }
        QMessageBox::information(this, "提示", "成绩提交成功！", QMessageBox::Ok);
    }
    else
    {
        qDebug() << "连接数据库失败！" ;
    }
    delete conn;
    close();
}
