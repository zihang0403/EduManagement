#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString("教务管理系统"));

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("edumanagement");

    if(!db.open())
    {
        QSqlError error = db.lastError();
        qDebug() << "Failed to connect to database:";
        qDebug() << "Type:" << error.type();
        qDebug() << "Database driver text:" << error.databaseText();
        qDebug() << "Driver text:" << error.driverText();
        qDebug() << "Text:" << error.text();
        return -1;
    }
    qDebug() << "连接成功！" ;
    QSqlQuery query;
    if(query.exec("select * from student"))
    {
        while(query.next())
        {
            QString id = query.value("id").toString();
            QString name = query.value("name").toString();
            qDebug() << "id:" << id << " name:" << name << Qt::endl;
        }
    }

//    db.close();

    w.show();
    return a.exec();
}
