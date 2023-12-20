#include "Student.h"
#include "mysqlconnector.h"
#include "studentdeleteform.h"
#include "ui_studentdeleteform.h"

#include <QMessageBox>

StudentDeleteForm::StudentDeleteForm(QWidget *parent, Teacher *teacher) :
    QWidget(parent, Qt::Window),
    ui(new Ui::StudentDeleteForm)
{
    ui->setupUi(this);

    connect(ui->submit, &QPushButton::clicked, this, [=](){
        submitBtnClick(ui, teacher);
    });
}

StudentDeleteForm::~StudentDeleteForm()
{
    delete ui;
}

void StudentDeleteForm::submitBtnClick(Ui::StudentDeleteForm *ui, Teacher *teacher)
{
    MySqlConnector *conn = new MySqlConnector;

    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        if(ui->submit->text() == "查询")
        {
            QString sql = "SELECT * FROM studentinfo WHERE studentid = '" + ui->studentid->text() + "'";

            if(conn->DataBaseOut(query, sql))
            {
                if(query.next())
                {
                    Student *student = new Student(
                        query.value("studentid").toString(),
                        query.value("password").toString(),
                        query.value("name").toString(),
                        query.value("sex").toString(),
                        query.value("bornday").toDate(),
                        query.value("institute").toString());

                    ui->studentid->setText(student->getStudentID());
                    ui->name->setText(student->getName());
                    ui->sex->setCurrentText(student->getSex());
                    ui->bornday->setDate(student->getbornDay());

                    ui->studentid->setDisabled(true);

                    ui->submit->setText("确认删除");
                    delete student;
                }
                else
                {
                    QMessageBox::information(this, "提示", "未查询到学生信息！", QMessageBox::Ok);
                }
            }
            else
            {
                QMessageBox::information(this, "提示", "查询失败！", QMessageBox::Ok);
            }
        }
        else //按钮为 确认删除 时
        {
            QString sql = "DELETE FROM studentinfo WHERE studentid = '" + ui->studentid->text() + "'";
            if(conn->DataBaseOut(query,sql))
            {
                QMessageBox::information(this, "提示", "删除成功！", QMessageBox::Ok);
                emit studentDeleted();
                close();
            }
            else
            {
                QMessageBox::information(this, "提示", "删除失败！", QMessageBox::Ok);
            }
        }
    }
    else
    {
        qDebug() << "连接数据库失败！";
    }
    delete conn;
}
