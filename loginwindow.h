#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

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

public slots:
    void loginBtnClick();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
