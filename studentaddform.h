#ifndef STUDENTADDFORM_H
#define STUDENTADDFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class StudentAddForm;
}

class StudentAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentAddForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~StudentAddForm();

signals:
    void StudentAdded();
public slots:
    void submitBtnClick(Ui::StudentAddForm *ui, Teacher *teacher);

private:
    Ui::StudentAddForm *ui;
};

#endif // STUDENTADDFORM_H
