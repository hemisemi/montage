#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T18:28:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

LIBS = -lhsm-montage -lavformat -lavcodec -lavutil -lz -lm

SOURCES += main.cpp\
        mainwindow.cpp \
    widgets/viewcontainer.cpp \
    widgets/splitter.cpp \
    widgets/view.cpp \
    widgets/viewcontainertoolbar.cpp \
    views/videostreamview.cpp \
    views/defaultview.cpp

HEADERS  += mainwindow.h \
    widgets/viewcontainer.h \
    widgets/splitter.h \
    widgets/view.h \
    widgets/viewcontainertoolbar.h \
    views/videostreamview.h \
    views/defaultview.h
