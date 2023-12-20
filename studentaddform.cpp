#include "Student.h"
#include "mysqlconnector.h"
#include "studentaddform.h"
#include "ui_studentaddform.h"

#include <QDate>
#include <QMessageBox>

StudentAddForm::StudentAddForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::StudentAddForm)
{
    ui->setupUi(this);

    QStringList sex;
    sex << "男" << "女";
    ui->sex->addItems(sex);

    connect(ui->submit, &QPushButton::clicked, this, [=]{
        submitBtnClick(ui, teacher);
    });
}

StudentAddForm::~StudentAddForm()
{
    delete ui;
}

void StudentAddForm::submitBtnClick(Ui::StudentAddForm *ui, Teacher *teacher)
{
    Student *student = new Student(
        ui->studentid->text(),
        ui->studentid->text(),
        ui->name->text(),
        ui->sex->currentText(),
        ui->bornday->date(),
        teacher->getInstitute());
    MySqlConnector *conn = new MySqlConnector;

    if(!conn->DataBaseConnect())
    {
        qDebug() << "连接失败！";
        delete student;
        delete conn;
        return;
    }
    QSqlQuery query;
    QString sql = "SELECT * FROM studentinfo WHERE studentid = '" + student->getStudentID() + "'";
    if(conn->DataBaseOut(query, sql))
    {
        if(!query.next())
        {
            QStringList columns;
            QVariantList data;
            QList<QVariantList> dataset;
            columns << "studentid" << "password" << "name" << "sex" << "bornday" << "institute";
            data << student->getStudentID()
                 << student->getPassword()
                 << student->getName()
                 << student->getSex()
                 << student->getbornDay()
                 << student->getInstitute();
            dataset << data;
            if(conn->DataBaseIn("studentinfo", columns, dataset))
            {
                QMessageBox::information(this, "提示", "添加成功！", QMessageBox::Ok);
                emit StudentAdded();
                close();
            }
            else
            {
                QMessageBox::information(this, "提示", "未添加成功！", QMessageBox::Ok);
            }
        }
        else
        {
            QMessageBox::information(this, "提示", "学号已存在！", QMessageBox::Ok);
        }
    }

    delete student;
    delete conn;
}
