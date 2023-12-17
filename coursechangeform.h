#ifndef COURSECHANGEFORM_H
#define COURSECHANGEFORM_H

#include <QWidget>

namespace Ui {
class CourseChangeForm;
}

class CourseChangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseChangeForm(QWidget *parent = nullptr);
    ~CourseChangeForm();

private:
    Ui::CourseChangeForm *ui;
};

#endif // COURSECHANGEFORM_H
