#ifndef MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class MySqlConnector
{
public:
    MySqlConnector()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
    }

};

#endif // MYSQLCONNECTOR_H
