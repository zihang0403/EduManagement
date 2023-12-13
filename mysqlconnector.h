#ifndef MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class MySqlConnector
{
public:
    /**
     * @brief DataBaseConnect 连接数据库
     * @return true 连接成功 false 连接失败
     */
    bool DataBaseConnect()
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setUserName("root");
        db.setPassword("123456");
        db.setDatabaseName("edumagement");

        if(!db.open())
        {
            QSqlError error = db.lastError();
            qDebug() << "Failed to connect to database" << Qt::endl
                     << "Type:" << error.type() << Qt::endl
                     << "Database driver text:" << error.driverText() << Qt::endl
                     << "Text:" << error.text() << Qt::endl;
            return false;
        }
        qDebug() << "连接成功！" << Qt::endl;
        return true;
    }

    /**
     * @brief DataBaseOut 读取表中数据
     * @param tableName 表名
     * @param columns 列名
     * @return 返回包含数据的query 或 空query
     */
    QSqlQuery DataBaseOut(const QString &tableName, const QStringList &columns)
    {
        QSqlQuery query;
        QString sql = QString("SELECT ");
        for(const QString &column : columns)
        {
            sql += column + ",";
        }
        sql.chop(1);

        sql += "FROM" + tableName;

        if(query.exec(sql))
        {
            return query;
        }
        return QSqlQuery();
    }

    /**
     * @brief DataBaseIn 向表中存储数据
     * @param tabelName 表名
     * @param columns 数据库表的行名
     * @param data 任意数据类型列表，待存储的数据
     * @return true 存储成功 false 存储失败
     */
    bool DataBaseIn(const QString &tableName, const QStringList &columns, const QList<QVariantList> &dataSet)
    {
        QSqlQuery query;

        //拼接SQL插入语句
        QString sql = QString("INSERT INTO " + tableName + " (");
        //添加行
        for(const QString &column : columns)
        {
            sql += column + ",";
        }
        sql.chop(1);
        sql += ") VALUES (";

        //添加值参数
        for(const QString &column : columns)
        {
            sql += ":" + column + ",";
        }
        sql.chop(1);
        sql += ") ";

        //准备查询
        if(query.prepare(sql))
        {
            //遍历每组数据集
            for (const QVariantList &data : dataSet) {
                //遍历数据集中的数据
                for (int i = 0; i < data.length(); ++i) {
                    //绑定参数
                    query.bindValue(":" + columns[i], data[i]);
                }

                //开始查询
                if(!query.exec())
                {
                    qDebug() << "插入失败！" << query.lastError().text();
                    return false;
                }
                else
                {
                    qDebug() << "插入成功！" ;
                    return true;
                }
            }
        }
        else
        {
            qDebug() << "准备插入失败！" << query.lastError().text();
        }
        return false;
    }

    /**
     * @brief DataBaseClose 关闭数据库
     */
    void DataBaseClose()
    {
        db.close();
    }

private:
    QSqlDatabase db;
};

#endif // MYSQLCONNECTOR_H
