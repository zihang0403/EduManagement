#include "mysqlconnector.h"
#include "scoremanageform.h"
#include "ui_scoremanageform.h"

ScoreManageForm::ScoreManageForm(QWidget *parent, Teacher *teacher)
    : QWidget(parent, Qt::Window)
    , ui(new Ui::ScoreManageForm)
{
    ui->setupUi(this);
}

ScoreManageForm::~ScoreManageForm()
{
    delete ui;
}

void ScoreManageForm::submitBtnClick(Ui::ScoreManageForm *ui, Teacher *teacher)
{
    ui->scoremanagetable->setColumnCount(4);

    QStringList headers;
    headers << "课程" << "学生" << "教师" << "成绩";
    ui->scoremanagetable->setHorizontalHeaderLabels(headers);

    MySqlConnector *conn = new MySqlConnector;
    if(conn->DataBaseConnect())
    {
        QSqlQuery query;
        QString sql = "SELECT * FROM courseset WHERE teacherid = '" + teacher->getTeacherID() + "'";

    }
    else
    {
        qDebug() << "数据库连接失败！";
    }
    delete conn;
}
