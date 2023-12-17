#ifndef TEACHERINFOWINDOW_H
#define TEACHERINFOWINDOW_H

#include "Teacher.h"
#include "mainwindow.h"

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

        //退出当前界面回到登录窗口
        MainWindow *main = new MainWindow;
        main->show();
    }
    void createPage1(QWidget *page, Teacher *teacher);
    void createPage2(QWidget *page, Teacher *teacher);
    void createPage3(QWidget *page, Teacher *teacher);

private:
    Ui::TeacherInfoWindow *ui;
};

#endif // TEACHERINFOWINDOW_H
