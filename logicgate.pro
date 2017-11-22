#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T09:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logicgate
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
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# 32-bit Windows
win32:contains(QT_ARCH, i386) {
    # No one is using a 32-bit machine, right?
}

# 64-bit Windows (Kit: MSVC2015 64bit)
# I can't test the MinGW kit from the lab machines, but those would likely need a 'win32-g++' block or something.
# Using the MSVC2015 64-bit kit would likelye be easiest at this point.
win32:contains(QT_ARCH, x86_64) {
    # Box2D
    CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/Box2D/win64/debug -lBox2D
    CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/Box2D/win64/release -lBox2D
    INCLUDEPATH += $$PWD/thirdparty/Box2D/include
    DEPENDPATH += $$PWD/thirdparty/Box2D/include

    # SFML (DLLs are also in the lib directory)
    CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/SFML/win64/lib  -lsfml-system-d -lsfml-window-d -lsfml-graphics-d -lsfml-audio-d
    CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/SFML/win64/lib  -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
    INCLUDEPATH += $$PWD/thirdparty/SFML/win64/include
    DEPENDPATH += $$PWD/thirdparty/SFML/win64/include
}

# MacOS (Untested)
unix:macos {
    # Box2D
    LIBS += -L$$PWD/thirdparty/Box2D/mac/lib -lBox2D
    INCLUDEPATH += $$PWD/thirdparty/Box2D/include
    DEPENDPATH += $$PWD/thirdparty/Box2D/include

    # SFML
    LIBS += -L$$PWD/thirdparty/SFML/mac/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
    INCLUDEPATH += $$PWD/thirdparty/SFML/mac/include
    DEPENDPATH += $$PWD/thirdparty/SFML/mac/include
}

# Linux/Other
unix:!macos {
    LIBS += -L$$PWD/thirdparty/SFML/linux/lib -L$$PWD/thirdparty/Box2D/linux/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lBox2D
    INCLUDEPATH += $$PWD/thirdparty/SFML/linux/include $$PWD/thirdparty/Box2D
    DEPENDPATH += $$PWD/thirdparty/SFML/linux/include $$PWD/thirdparty/Box2D
}
