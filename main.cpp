#include "mainwindow.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString("教务管理系统"));
    w.show();
    return a.exec();
}
