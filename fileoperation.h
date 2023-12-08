#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <QFile>

//文件读写类
class FileOperation
{
public:
    FileOperation();
    QString FileRead(const QString &Filename);
    void FileWrite(const QString &Filename, const QString &Content);
};

#endif // FILEOPERATION_H
