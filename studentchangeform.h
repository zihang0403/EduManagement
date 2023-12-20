#ifndef STUDENTCHANGEFORM_H
#define STUDENTCHANGEFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class StudentChangeForm;
}

class StudentChangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentChangeForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~StudentChangeForm();

signals:
    void studentChanged();

public slots:
    void submitBtnClick(Ui::StudentChangeForm *ui, Teacher *taecher);

private:
    Ui::StudentChangeForm *ui;
};

#endif // STUDENTCHANGEFORM_H
