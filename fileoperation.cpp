#include "fileoperation.h"
#include <QFile>
#include <QDebug>

FileOperation::FileOperation()
{

}

QString FileRead(const QString &Filename)
{
    QFile file(Filename);

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream out(&file);
    }
    else
    {
        qDebug() << "文件打开失败！请检查！";
        return QString();
    }
}

void FileWrite(const QString &Filename, const QString &Content)
{

}
