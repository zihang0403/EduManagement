#ifndef COURSECHANGEFORM_H
#define COURSECHANGEFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class CourseChangeForm;
}

class CourseChangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseChangeForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~CourseChangeForm();

signals:
    void courseChanged();

public slots:
    void submitBtnClick(Ui::CourseChangeForm *ui, Teacher *teacher);

private:
    Ui::CourseChangeForm *ui;
};

#endif // COURSECHANGEFORM_H
