#ifndef COURSEDELETEFORM_H
#define COURSEDELETEFORM_H

#include <QWidget>

namespace Ui {
class CourseDeleteForm;
}

class CourseDeleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseDeleteForm(QWidget *parent = nullptr);
    ~CourseDeleteForm();

private:
    Ui::CourseDeleteForm *ui;
};

#endif // COURSEDELETEFORM_H
