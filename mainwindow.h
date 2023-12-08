#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showLoginWindow(enum LoginWindow::LoginBy);
    void reShowMainWindow();
    static MainWindow *getInstance();

//定义槽函数后一定要在CPP中实现！！！不然报错！！！
public slots:
    void StuButtonClick();
    void ManageButtonClick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
