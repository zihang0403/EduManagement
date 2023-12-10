// #define NOTE

#ifdef NOTE

#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>

namespace Ui {
class note;
}

class note : public QMainWindow
{
    Q_OBJECT

public:
    explicit note(QWidget *parent = nullptr);
    ~note();

// 创建槽函数
public slots:
    void ButtonClick();

private:
    Ui::note *ui;
};

#endif // NOTE_H

#endif //ifdef NOTE
