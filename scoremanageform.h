#ifndef SCOREMANAGEFORM_H
#define SCOREMANAGEFORM_H

#include "Teacher.h"

#include <QWidget>

namespace Ui {
class ScoreManageForm;
}

class ScoreManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreManageForm(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~ScoreManageForm();

public slots:
    void submitBtnClick(Ui::ScoreManageForm *ui, Teacher *teacher);

private:
    Ui::ScoreManageForm *ui;
};

#endif // SCOREMANAGEFORM_H
