#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T15:27:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    ball.cpp \
    stick.cpp

HEADERS  += gamewindow.h \
    ball.h \
    stick.h

FORMS    += gamewindow.ui
