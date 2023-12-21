#ifndef SCOREINFOFORM_H
#define SCOREINFOFORM_H

#include <QWidget>

namespace Ui {
class ScoreInfoForm;
}

class ScoreInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreInfoForm(QWidget *parent = nullptr);
    ~ScoreInfoForm();

private:
    Ui::ScoreInfoForm *ui;
};

#endif // SCOREINFOFORM_H
