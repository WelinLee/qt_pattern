#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T16:04:45
#
#-------------------------------------------------

QT       -= core gui

TARGET = staticLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += staticlib.cpp

HEADERS += staticlib.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += debug_and_release
CONFIG(debug, debug|release): TARGET = $$join(TARGET,,,d)
DESTDIR = ../../externlib/
