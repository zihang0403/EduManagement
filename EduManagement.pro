QT       += core gui
QT       += widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    courseinfowindow.cpp \
    coursemanagewindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    scoreinfowindow.cpp \
    scoremanagewindow.cpp

HEADERS += \
    courseinfowindow.h \
    coursemanagewindow.h \
    loginwindow.h \
    mainwindow.h \
    scoreinfowindow.h \
    scoremanagewindow.h

FORMS += \
    courseinfowindow.ui \
    coursemanagewindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    scoreinfowindow.ui \
    scoremanagewindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
