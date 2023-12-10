#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <QFile>

//文件读写类
class FileOperation
{
public:
    QList<QString> DataRead(const QString &Filename);
    int DataAppend(const QString &Filename, const QList<QString> &Data);
};

#endif // DATAOPERATION_H
