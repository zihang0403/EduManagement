#include "Student.h"
#include "mysqlconnector.h"
#include "studentchangeform.h"
#include "ui_studentchangeform.h"

#include <QMessageBox>

StudentChangeForm::StudentChangeForm(QWidget *parent, Teacher *teacher) :
    QWidget(parent, Qt::Window),
    ui(new Ui::StudentChangeForm)
{
    ui->setupUi(this);

    QStringList sex;
    sex << "男" << "女";
    ui->sex->addItems(sex);

    connect(ui->submit, &QPushButton::clicked, this, [=](){
        submitBtnClick(ui, teacher);
    });
}

StudentChangeForm::~StudentChangeForm()
{
    delete ui;
}

void StudentChangeForm::submitBtnClick(Ui::StudentChangeForm *ui, Teacher *taecher)
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
                    ui->name->setDisabled(false);
                    ui->sex->setDisabled(false);
                    ui->bornday->setDisabled(false);

                    ui->submit->setText("提交");
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
        else //按钮为 提交 时
        {
            QString sql = "UPDATE studentinfo SET name = '" + ui->name->text()
                          + "', sex = '" + ui->sex->currentText()
                         + "', bornday = '" + ui->bornday->date().toString("yyyy-MM-dd")
                          + "' WHERE studentid = '" + ui->studentid->text() + "'";

            if(conn->DataBaseOut(query,sql))
            {
                QMessageBox::information(this, "提示", "修改成功！", QMessageBox::Ok);
                emit studentChanged();
                close();
            }
            else
            {
                QMessageBox::information(this, "提示", "修改失败！", QMessageBox::Ok);
            }
        }
    }
    else
    {
        qDebug() << "连接数据库失败！";
    }
    delete conn;
}


