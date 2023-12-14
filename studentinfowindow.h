#ifndef STUDENTINFOWINDOW_H
#define STUDENTINFOWINDOW_H

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
    explicit StudentInfoWindow(QWidget *parent = nullptr);
    ~StudentInfoWindow();
    void closeEvent(QCloseEvent * event) override
    {
        //确认接收关闭事件
        event->accept();

        //退出程序
        QCoreApplication::exit();
    }
    QWidget *createPage1();
    QWidget *createPage2();
    QWidget *createPage3();
    QWidget *createPage4();


private:
    Ui::StudentInfoWindow *ui;
};

#endif // STUDENTINFOWINDOW_H
