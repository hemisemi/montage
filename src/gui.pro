#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T18:28:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

LIBS = -lhsm-montage-debug -lavformat -lavcodec -lavutil -lz -lm -lswscale -lhsm-paint -lcairo -lhsm -ljpeg -lpng

SOURCES += main.cpp\
        mainwindow.cpp \
    widgets/viewcontainer.cpp \
    widgets/splitter.cpp \
    widgets/view.cpp \
    widgets/viewcontainertoolbar.cpp \
    views/videostreamview.cpp \
    views/defaultview.cpp \
    player/renderer/renderer.cpp \
    player/player.cpp \
    player/renderer/softwarerenderer.cpp

HEADERS  += mainwindow.h \
    widgets/viewcontainer.h \
    widgets/splitter.h \
    widgets/view.h \
    widgets/viewcontainertoolbar.h \
    views/videostreamview.h \
    views/defaultview.h \
    player/renderer/renderer.h \
    player/player.h \
    player/renderer/softwarerenderer.h
