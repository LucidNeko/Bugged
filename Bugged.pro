#-------------------------------------------------
#
# Project created by QtCreator 2016-08-27T12:53:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bugged
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewidget.cpp \
    shaderprogram.cpp \
    player.cpp \
    input.cpp

HEADERS  += mainwindow.h \
    gamewidget.h \
    time.h \
    shaderprogram.h \
    player.h \
    input.h

FORMS    += mainwindow.ui
