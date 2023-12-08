#ifndef COURSEMANAGEWINDOW_H
#define COURSEMANAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class CourseManageWindow;
}

class CourseManageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourseManageWindow(QWidget *parent = nullptr);
    ~CourseManageWindow();

private:
    Ui::CourseManageWindow *ui;
};

#endif // COURSEMANAGEWINDOW_H
