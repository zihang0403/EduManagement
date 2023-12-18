#ifndef COURSE_H
#define COURSE_H

#include <QString>


class Course
{
public:
    explicit Course()
        :courseID(QString()), name(QString()), courseScore(0), coursePeriod(0) {}
    explicit Course(const QString &courseID, const QString &name, const float &courseScore, const int &coursePeroid)
        :courseID(courseID), name(name), courseScore(courseScore), coursePeriod(coursePeroid) {}

    QString getCourseID()
    {
        return courseID;
    }

    QString getName()
    {
        return name;
    }

    float getCourseScore()
    {
        return courseScore;
    }

    int getCoursePeriod()
    {
        return coursePeriod;
    }
private:
    QString courseID;
    QString name;
    float courseScore;
    int coursePeriod;
};

#endif // COURSE_H
