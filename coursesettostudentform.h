#ifndef COURSESETTOSTUDENTFORM_H
#define COURSESETTOSTUDENTFORM_H

#include <QWidget>

namespace Ui {
class CourseSetToStudentForm;
}

class CourseSetToStudentForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseSetToStudentForm(QWidget *parent = nullptr);
    ~CourseSetToStudentForm();

private:
    Ui::CourseSetToStudentForm *ui;
};

#endif // COURSESETTOSTUDENTFORM_H
