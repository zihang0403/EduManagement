#ifndef STUDENTADDFORM_H
#define STUDENTADDFORM_H

#include <QWidget>

namespace Ui {
class StudentAddForm;
}

class StudentAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentAddForm(QWidget *parent = nullptr);
    ~StudentAddForm();

private:
    Ui::StudentAddForm *ui;
};

#endif // STUDENTADDFORM_H
