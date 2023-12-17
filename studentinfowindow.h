#ifndef STUDENTINFOWINDOW_H
#define STUDENTINFOWINDOW_H

#include "Student.h"
#include "mainwindow.h"

#include <QCoreApplication>
#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class StudentInfoWindow;
}

class StudentInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentInfoWindow(QWidget *parent = nullptr, Student *student = new Student());
    ~StudentInfoWindow();
    void closeEvent(QCloseEvent * event) override
    {
        //确认接收关闭事件
        event->accept();

        //退出当前界面回到登录窗口
        MainWindow *main = new MainWindow;
        main->show();
    }
    void createPage1(QWidget *page, Student *student);
    void createPage2(QWidget *page, Student *student);
    void createPage3(QWidget *page, Student *student);
    void createPage4(QWidget *page, Student *student);


private:
    Ui::StudentInfoWindow *ui;
};

#endif // STUDENTINFOWINDOW_H
