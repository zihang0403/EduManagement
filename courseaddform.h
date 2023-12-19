#ifndef COURSEADDFORM_H
#define COURSEADDFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class CourseAddForm;
}

class CourseAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseAddForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~CourseAddForm();

public slots:
    void submitBtnClick(Ui::CourseAddForm *ui, Teacher *teacher);

private:
    Ui::CourseAddForm *ui;
};

#endif // COURSEADDFORM_H
