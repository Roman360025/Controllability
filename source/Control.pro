#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T15:45:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Control
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
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
    table7_1.cpp \
    ost4_83.cpp \
    ost83_ready.cpp \
    ost83_choice.cpp \
    ost83_whole.cpp \
    ost83_zip.cpp \
    ost45.cpp \
    ost45_choice.cpp

HEADERS += \
        mainwindow.h \
    table7_1.h \
    ost4_83.h \
    ost83_ready.h \
    ost83_choice.h \
    ost83_whole.h \
    ost83_zip.h \
    ost45.h \
    ost45_choice.h

FORMS += \
        mainwindow.ui \
    table7_1.ui \
    ost4_83.ui \
    ost83_ready.ui \
    ost83_choice.ui \
    ost83_whole.ui \
    ost83_zip.ui \
    ost45.ui \
    ost45_choice.ui

RESOURCES += \
    img.qrc
