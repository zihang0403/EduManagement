#ifndef COURSE_H
#define COURSE_H

#include <QString>


class Course
{
public:
    explicit Course()
        :courseID(QString()), name(QString()), courseScore(0), coursePeriod(0), institute(QString()) {}
    explicit Course(const QString &courseID, const QString &name, const float &courseScore, const int &coursePeroid, const QString &institute)
        :courseID(courseID), name(name), courseScore(courseScore), coursePeriod(coursePeroid), institute(institute) {}

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

    QString getInstitute()
    {
        return institute;
    }

private:
    QString courseID;
    QString name;
    float courseScore;
    int coursePeriod;
    QString institute;
};

#endif // COURSE_H
