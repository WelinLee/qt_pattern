#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T16:07:43
#
#-------------------------------------------------

QT       += widgets

TARGET = pluginForm
TEMPLATE = lib

SOURCES += pluginform.cpp \
    pluginwidget.cpp

HEADERS += pluginform.h\
    ipluginui.h \
    pluginwidget.h

FORMS += \
    pluginwidget.ui

DISTFILES += \
    pluginForm.json

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += debug_and_release
CONFIG(debug, debug|release): TARGET = $$join(TARGET,,,d)
CONFIG(debug, release|debug): DESTDIR = ../../debug/plugins/
CONFIG(release, release|debug): DESTDIR = ../../release/plugins/
