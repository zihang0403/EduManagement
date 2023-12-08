#ifndef SCOREMANAGEWINDOW_H
#define SCOREMANAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ScoreManageWindow;
}

class ScoreManageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScoreManageWindow(QWidget *parent = nullptr);
    ~ScoreManageWindow();

private:
    Ui::ScoreManageWindow *ui;
};

#endif // SCOREMANAGEWINDOW_H
