#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QApplication>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum LoginBy{
        stu,
        teacher
    };

    explicit LoginWindow(QWidget *parent = nullptr, enum LoginBy loginBy = stu);
    ~LoginWindow();

    void closeEvent(QCloseEvent * event) override
    {
        //确认接收关闭事件
        event->accept();

        //退出程序
        QCoreApplication::exit();
    }

public slots:
    void loginBtnClick();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
