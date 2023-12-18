#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QApplication>
#include "Student.h"
#include "Teacher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // 登录属性：学生/教师
    bool loginProperty = false;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // void reShowMainWindow();
    // static MainWindow *getInstance();
    //    void closeEvent(QCloseEvent * event) override
    //    {
    //        //确认接收关闭事件
    //        event->accept();

    //        //退出程序
    //        QCoreApplication::exit();
    //    }
    void showStudentInfoWindow(Student *student);
    void showTeacherInfoWindow(Teacher *teacher);

//定义槽函数后一定要在CPP中实现！！！不然报错！！！
public slots:
    void LoginButtonClick(const QString &userName, const QString &password);
    void setLoginProperty(bool prop);
    void showMainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
