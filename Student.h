#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QList>
#include <QDate>

class Student
{
public:
    Student()
        : studentID(QString()), password(QString()), name(QString()), sex(QString()), bornDay(QDate()), institute(QString()), status(false){}
    //使用&引用传递字符串避免复制对象产生的性能开销
    Student(const QString &studentID ,const QString &password, const QString &name, const QString &sex, const QDate &bornDay, const QString &institute)
        : studentID(studentID), password(password), name(name), sex(sex), bornDay(bornDay), institute(institute), status(true) {}

    QString getStudentID()
    {
        return studentID;
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

    QDate getbornDay()
    {
        return bornDay;
    }

    QString getInstitute()
    {
        return institute;
    }

    QList<QString> getStudentCourse()
    {
        return studentCourse;
    }

    bool getStatus()
    {
        return status;
    }

    void addCourse(const QString &course)
    {
        this->studentCourse << course;
    }

    bool deleteCourse(const QString &course)
    {
        if(this->studentCourse.contains(course))
        {
            this->studentCourse.removeAll(course);
            return true;
        }
        return false;
    }

private:
    QString studentID;
    QString password;
    QString name;
    QString sex;
    QDate bornDay;
    QString institute;
    bool status = false;
    QList<QString> studentCourse;
};

#endif // STUDENT_H
