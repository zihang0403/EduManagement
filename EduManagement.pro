QT       += core gui
QT       += widgets
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    courseaddform.cpp \
    coursechangeform.cpp \
    coursedeleteform.cpp \
    dataoperation.cpp \
    main.cpp \
    mainwindow.cpp \
    note.cpp \
    scoremanageform.cpp \
    studentaddform.cpp \
    studentinfowindow.cpp \
    teacherinfowindow.cpp

HEADERS += \
    Course.h \
    Student.h \
    Teacher.h \
    courseaddform.h \
    coursechangeform.h \
    coursedeleteform.h \
    dataoperation.h \
    mainwindow.h \
    mysqlconnector.h \
    note.h \
    scoremanageform.h \
    studentaddform.h \
    studentinfowindow.h \
    teacherinfowindow.h

FORMS += \
    courseaddform.ui \
    coursechangeform.ui \
    coursedeleteform.ui \
    mainwindow.ui \
    note.ui \
    scoremanageform.ui \
    studentaddform.ui \
    studentinfowindow.ui \
    teacherinfowindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    QSS/OIP.jfif \
    QSS/mainStyle.qss
