#ifndef TEACHER_H
#define TEACHER_H

#include <QDate>
#include <QString>


class Teacher
{
public:
    explicit Teacher()
        : teacherID(QString()), password(QString()), name(QString()), sex(QString()), position(QString()), institute(QString()), bornDay(QDate()), teachCourse(QString()), status(false){}
    //使用&引用传递字符串避免复制对象产生的性能开销
    explicit Teacher(const QString &teacherID ,const QString &password, const QString &name, const QString &sex,const QString &position, const QString institute, const QDate &bornDay, const QString &teachCourse)
        : teacherID(teacherID), password(password), name(name), sex(sex), position(position), institute(institute), bornDay(bornDay), teachCourse(teachCourse), status(true) {}

    QString getTeacherID()
    {
        return teacherID;
    }

    QString getPassword()
    {
        return password;
    }

    void setPassword(const QString &pwd)
    {
        password = pwd;
    }

    QString getName()
    {
        return name;
    }

    QString getSex()
    {
        return sex;
    }

    QString getPosition()
    {
        return position;
    }

    QString getInstitute()
    {
        return institute;
    }

    QDate getbornDay()
    {
        return bornDay;
    }

    QString getTeachCourse()
    {
        return teachCourse;
    }

    void setTeachCourse(const QString &tCourse)
    {
        teachCourse = tCourse;
    }

    bool getStatus()
    {
        return status;
    }

private:
    QString teacherID;
    QString password;
    QString name;
    QString sex;
    QString position;
    QString institute;
    QDate bornDay;
    QString teachCourse;
    bool status = false;
};

#endif // TEACHER_H
