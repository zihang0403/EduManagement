#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QList>

class Student
{
public:
    Student();
    Student(QList<QString> &student)
        : studentID(student){}
    //使用&引用传递字符串避免复制对象产生的性能开销
    Student(const QString &studentID,const QString &password, const QString &name, const QString &sex, const QString &bornDay, bool status = true)
        : studentID(studentID), password(password), name(name), sex(sex), bornDay(bornDay), status(status) {}

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

    QString getbornDay()
    {
        return bornDay;
    }

    QList<QString> getStudentCourse()
    {
        return studentCourse;
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
    QString bornDay;
    bool status = false;
    QList<QString> studentCourse;
};

#endif // STUDENT_H
