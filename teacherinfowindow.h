#ifndef TEACHERINFOWINDOW_H
#define TEACHERINFOWINDOW_H

#include "Teacher.h"

#include <QCloseEvent>
#include <QCoreApplication>
#include <QMainWindow>

namespace Ui {
class TeacherInfoWindow;
}

class TeacherInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherInfoWindow(QWidget *parent = nullptr, Teacher *teacher = new Teacher);
    ~TeacherInfoWindow();
    void closeEvent(QCloseEvent * event) override
    {
        //确认接收关闭事件
        event->accept();

        //发出回到登录窗口的信号
        emit returnToMainWindow();
    }
    void createPage1(QWidget *page, Teacher *teacher);
    void createPage2(QWidget *page, Teacher *teacher);
    void createPage3(QWidget *page, Teacher *teacher);
    void createPage4(QWidget *page, Teacher *teacher);

signals:
    void returnToMainWindow();

private:
    Ui::TeacherInfoWindow *ui;
};

#endif // TEACHERINFOWINDOW_H
