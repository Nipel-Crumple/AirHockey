#-------------------------------------------------
#
# Project created by QtCreator 2014-04-09T00:21:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirHockey
TEMPLATE = app


SOURCES += main.cpp\
        hockey.cpp \
    ball.cpp \
    stick.cpp

HEADERS  += hockey.h \
    my_ui.h \
    ball.h \
    stick.h

#FORMS    += hockey.ui

RESOURCES += \
    files.qrc
