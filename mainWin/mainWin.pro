#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T16:03:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainWin
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

CONFIG(debug, release|debug): DESTDIR = ../../debug/
CONFIG(release, release|debug): DESTDIR = ../../release/

# depend on static library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../externlib/ -lstaticLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../externlib/ -lstaticLibd
else:unix: LIBS += -L$$OUT_PWD/../../externlib/ -lstaticLib

INCLUDEPATH += $$PWD/../staticLib
DEPENDPATH += $$PWD/../staticLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../externlib/libstaticLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../externlib/libstaticLibd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../externlib/staticLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../externlib/staticLibd.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../externlib/libstaticLib.a

#depend on shared library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../release/ -lsharedLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../debug/ -lsharedLibd
else:unix: LIBS += -L$$OUT_PWD/../sharedLib/ -lsharedLib

INCLUDEPATH += $$PWD/../sharedLib
DEPENDPATH += $$PWD/../sharedLib
