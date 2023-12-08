#ifndef COURSEINFOWINDOW_H
#define COURSEINFOWINDOW_H

#include <QMainWindow>

namespace Ui {
class CourseInfoWindow;
}

class CourseInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourseInfoWindow(QWidget *parent = nullptr);
    ~CourseInfoWindow();

private:
    Ui::CourseInfoWindow *ui;
};

#endif // COURSEINFOWINDOW_H
