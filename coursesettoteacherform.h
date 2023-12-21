#ifndef COURSESETTOTEACHERFORM_H
#define COURSESETTOTEACHERFORM_H

#include <QWidget>

namespace Ui {
class CourseSetToTeacherForm;
}

class CourseSetToTeacherForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseSetToTeacherForm(QWidget *parent = nullptr);
    ~CourseSetToTeacherForm();

private:
    Ui::CourseSetToTeacherForm *ui;
};

#endif // COURSESETTOTEACHERFORM_H
