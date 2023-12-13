#ifdef NEEDFILE

#include "dataoperation.h"
#include <QFile>
#include <QDebug>

/**
 *  FileRead 从文件中读取数据
 *  文件读取格式 内容1 内容2 内容3...... 内容n \n
 *  存储格式 QList<String>
 */
QList<QString> DataRead(const QString &Filename)
{
    QFile file(Filename);
    QList<QString> data;//存储一组数据的list

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))//读 文本
    {
        QTextStream in(&file);//文件使用文本流
        QString dataText = in.readLine();//读一行
        QString pendingData = dataText;//待处理数据
        int separatorIdx = pendingData.indexOf(' ');//搜索 ':' 位置
        while(separatorIdx != -1)//查找不到 ' ' 时停止
        {
            // 取 ' ' 前数据 去除空格换行
            QString content = pendingData.left(separatorIdx).trimmed();

            // 标签内容依次存储进list
            data << content;
            // 从待处理数据中移除已存储数据
            pendingData.remove(content+' ');
            // 下一个 ' ' 位置
            separatorIdx = pendingData.indexOf(' ');
        }
        return data;
    }
    else
    {
        qDebug() << "文件打开失败！请检查！" << file.errorString();
            return QList<QString>();
    }
}

/**
 * @brief FileWrite 向文件中添加数据
 * @param Filename 文件路径
 * @param Data 数据
 * @return
 * 存储格式 数据1 数据2 数据3......
 */
bool DataAppend(const QString &Filename, QList<QString> &Data)
{
    QFile file(Filename);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream out(&file);

        for(QList<QString>::iterator it = Data.begin(); it != Data.end(); it++)
        {
            out << *it;
        }
    }
    else
    {
        qDebug() << "文件打开失败！请检查！" << file.errorString();
        return -1;
    }
    return false;
}

#endif
