#-------------------------------------------------
#
# Project created by QtCreator 2021-05-25T11:35:25
#
#-------------------------------------------------

QT       += core gui network
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = X256_PROJECT
TEMPLATE = app

DESTDIR = $$PWD/bin/
CONFIG += c++11
RC_FILE = app.rc

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp \
    public/appinit.cpp \
    public/myhelper.cpp \
    LogOpreate/LogOperate.cpp \
    LogOpreate/LogOperateTableMode.cpp \
    LogOpreate/LogOperateWidget.cpp \
    public/cqssfile.cpp \
    public/cwaitobject.cpp \
    controlservice/cexperimentfileoperat.cpp \
    controlservice/devicecontroller.cpp \
    network/netcontroller.cpp \
    public/iconhelper.cpp \
    gui/cwavewidget.cpp \
    gui/chartview.cpp \
    gui/imagewidget.cpp

HEADERS  += mainwindow.h \
    public/appinit.h \
    public/myhelper.h \
    LogOpreate/LogOperate.h \
    LogOpreate/LogOperateTableMode.h \
    LogOpreate/LogOperateWidget.h \
    public/cqssfile.h \
    public/cwaitobject.h \
    gloabl.h \
    controlservice/cexperimentfileoperat.h \
    controlservice/devicecontroller.h \
    network/netcontroller.h \
    public/iconhelper.h \
    gui/cwavewidget.h \
    gui/chartview.h \
    gui/imagewidget.h

FORMS    += mainwindow.ui \
    LogOpreate/LogOperateWidget.ui \
    gui/cwavewidget.ui \
    gui/imagewidget.ui

RESOURCES += \
    main.qrc \
    qss.qrc

DISTFILES +=
