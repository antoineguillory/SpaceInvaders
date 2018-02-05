TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

QMAKE_MAC_SDK = macosx10.11

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    const.h \
    manage.h \
    space.h \
    filemanage.h \
    menus.h \
    gamemode.h

