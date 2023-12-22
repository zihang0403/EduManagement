#ifndef COURSESETTOTEACHERFORM_H
#define COURSESETTOTEACHERFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class CourseSetToTeacherForm;
}

class CourseSetToTeacherForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseSetToTeacherForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~CourseSetToTeacherForm();

signals:
    void courseSetUpdated();

public slots:
    void submitBtnClick(Ui::CourseSetToTeacherForm *ui, Teacher *teacher);

private:
    Ui::CourseSetToTeacherForm *ui;
};

#endif // COURSESETTOTEACHERFORM_H
