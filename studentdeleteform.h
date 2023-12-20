#ifndef STUDENTDELETEFORM_H
#define STUDENTDELETEFORM_H

#include <QWidget>

namespace Ui {
class StudentDeleteForm;
}

class StudentDeleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentDeleteForm(QWidget *parent = nullptr);
    ~StudentDeleteForm();

private:
    Ui::StudentDeleteForm *ui;
};

#endif // STUDENTDELETEFORM_H
