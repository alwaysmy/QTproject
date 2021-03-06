#-------------------------------------------------
#
# Project created by QtCreator 2018-05-02T08:32:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpp_class_design
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    versiondialog.cpp \
    authordialog.cpp \
    userswidget.cpp \
    list_data.cpp \
    showresult.cpp

HEADERS += \
        mainwindow.h \
    versiondialog.h \
    authordialog.h \
    userswidget.h \
    base.h \
    list_data.h \
    showresult.h

FORMS += \
        mainwindow.ui \
    versiondialog.ui \
    authordialog.ui \
    userswidget.ui \
    showresult.ui

RESOURCES += \
    image.qrc
#RC_FILE=icon.rc
