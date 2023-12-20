#ifndef STUDENTDELETEFORM_H
#define STUDENTDELETEFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class StudentDeleteForm;
}

class StudentDeleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDeleteForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~StudentDeleteForm();

signals:
    void studentDeleted();

public slots:
    void submitBtnClick(Ui::StudentDeleteForm *ui, Teacher *teacher);

private:
    Ui::StudentDeleteForm *ui;
};

#endif // STUDENTDELETEFORM_H
