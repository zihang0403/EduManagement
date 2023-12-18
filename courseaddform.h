#ifndef COURSEADDFORM_H
#define COURSEADDFORM_H

#include <QWidget>

namespace Ui {
class CourseAddForm;
}

class CourseAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit CourseAddForm(QWidget *parent = nullptr);
    ~CourseAddForm();

public slots:
    void submitBtnClick(Ui::CourseAddForm *ui);

private:
    Ui::CourseAddForm *ui;
};

#endif // COURSEADDFORM_H
