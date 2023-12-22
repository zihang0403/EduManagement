#ifndef COURSESET_H
#define COURSESET_H

#include <QString>
#include <QVariant>


class CourseSet
{
public:
    explicit CourseSet();
    explicit CourseSet(const QString &courseID, const QString &studentID, const QString &teacherID, const QString &courseName, const QString &studentName, const QString &teacherName, const QString &courseWeekDay, const QString &startTime, const QString &endTime, const QString &classroom)
        :courseID(courseID), studentID(studentID), teacherID(teacherID), courseName(courseName), studentName(studentName), teacherName(teacherName), courseWeekDay(courseWeekDay), startTime(startTime), endTime(endTime), classroom(classroom){}

    QString getCourseID()
    {
        return courseID;
    }

    void setCourseID(const QString &cID)
    {
        courseID = cID;
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
        return teacherID;
    }

    void setTeacherID(const QString &tID)
    {
        teacherID = tID;
    }

    QString getCourseName()
    {
        return courseName;
    }

    void setCourseName(const QString &cName)
    {
        courseName = cName;
    }

    QString getStudentName()
    {
        return studentName;
    }

    void setStudentName(const QString &sName)
    {
        studentName = sName;
    }

    QString getTeacherName()
    {
        return courseName;
    }

    void setTeacherName(const QString &tName)
    {
        teacherName = tName;
    }

    QString getCourseWeekDay()
    {
        return courseWeekDay;
    }

    QString getStartTime()
    {
        return startTime;
    }

    QString getEndTime()
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

    QString courseName;
    QString studentName;
    QString teacherName;
    QString courseWeekDay;
    QString startTime;
    QString endTime;
    QString classroom;
};

#endif // COURSESET_H
