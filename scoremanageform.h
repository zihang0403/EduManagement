#ifndef SCOREMANAGEFORM_H
#define SCOREMANAGEFORM_H

#include <QWidget>

namespace Ui {
class ScoreManageForm;
}

class ScoreManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreManageForm(QWidget *parent = nullptr);
    ~ScoreManageForm();

private:
    Ui::ScoreManageForm *ui;
};

#endif // SCOREMANAGEFORM_H
