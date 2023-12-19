#ifndef COURSEDELETEFORM_H
#define COURSEDELETEFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class CourseDeleteForm;
}

class CourseDeleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseDeleteForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~CourseDeleteForm();

signals:
    void courseDeleted();

public slots:
    void submitBtnClick(Ui::CourseDeleteForm *ui, Teacher *teacher);

private:
    Ui::CourseDeleteForm *ui;
};

#endif // COURSEDELETEFORM_H
