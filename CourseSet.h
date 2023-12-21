#ifndef COURSESET_H
#define COURSESET_H

#include <QString>
#include <QTime>
#include <QVariant>


class CourseSet
{
public:
    explicit CourseSet();
    explicit CourseSet(const QString &courseID, const QString &studentID, const QString &teacherID, const QVariant &courseWeekDay, const QTime &startTime, const QTime &endTime, const QString &classroom)
        :courseID(courseID), studentID(studentID), teacherID(teacherID), courseWeekDay(courseWeekDay), startTime(startTime), endTime(endTime), classroom(classroom){}

    QString getCourseID()
    {
        return courseID;
    }

    QString getStudentID()
    {
        return studentID;
    }

    void setStudentID(const QString &sID)
    {
        studentID = sID;
    }

    QString getTeacherID()
    {
        return courseID;
    }

    QVariant getCourseWeekDay()
    {
        return courseWeekDay;
    }

    QTime getStartTime()
    {
        return startTime;
    }

    QTime getEndTime()
    {
        return endTime;
    }

    QString getClassroom()
    {
        return classroom;
    }

private:
    QString courseID;
    QString studentID;
    QString teacherID;
    QVariant courseWeekDay;
    QTime startTime;
    QTime endTime;
    QString classroom;
};

#endif // COURSESET_H
