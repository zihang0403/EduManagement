#include "Course.h"
#include "coursedeleteform.h"
#include "mysqlconnector.h"
#include "ui_coursedeleteform.h"

#include <QMessageBox>

CourseDeleteForm::CourseDeleteForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::CourseDeleteForm)
{
    ui->setupUi(this);

    connect(ui->submit, &QPushButton::clicked, this, [=](){
        submitBtnClick(ui, teacher);
    });
}

CourseDeleteForm::~CourseDeleteForm()
{
    delete ui;
}

void CourseDeleteForm::submitBtnClick(Ui::CourseDeleteForm *ui, Teacher *teacher)
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
        QString sql = "SELECT * FROM courseinfo WHERE courseid = '" + ui->courseid->text() + "' AND institute ='"
                      + teacher->getInstitute() + "'";

        if(conn->DataBaseOut(query, sql))
        {
            if(query.next())
            {
                ui->courseid->setDisabled(true);
                ui->submit->setText("确认删除");
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
        QString sql = "DELETE FROM courseinfo WHERE courseid = '" + ui->courseid->text() + "' AND institute ='"
                      + teacher->getInstitute() + "'";
        if(conn->DataBaseOut(query, sql))
        {
            QMessageBox::information(this, "提示", "删除成功！", QMessageBox::Ok);
            emit courseDeleted();
            close();
        }
        else
        {
            QMessageBox::information(this, "提示", "删除失败！", QMessageBox::Ok);
        }
    }
    delete conn;
}
