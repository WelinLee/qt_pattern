#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T16:06:10
#
#-------------------------------------------------

QT       += core

TARGET = sharedLib
TEMPLATE = lib

DEFINES += SHAREDLIB_LIBRARY

SOURCES += sharedlib.cpp

HEADERS += sharedlib.h\
        sharedlib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += debug_and_release
CONFIG(debug, debug|release): TARGET = $$join(TARGET,,,d)
CONFIG(debug, release|debug): DESTDIR = ../../debug/
CONFIG(release, release|debug): DESTDIR = ../../release/
