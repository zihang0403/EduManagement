#ifndef SCOREINFOWINDOW_H
#define SCOREINFOWINDOW_H

#include <QMainWindow>

namespace Ui {
class ScoreInfoWindow;
}

class ScoreInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScoreInfoWindow(QWidget *parent = nullptr);
    ~ScoreInfoWindow();

private:
    Ui::ScoreInfoWindow *ui;
};

#endif // SCOREINFOWINDOW_H
