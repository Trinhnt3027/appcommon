TEMPLATE = app
QT += quick
CONFIG += c++14

BASE_INCLUDE_PATH = /usr/local/include

INCLUDEPATH += $$BASE_INCLUDE_PATH/hmiappcommon/hmi \
               $$BASE_INCLUDE_PATH/hmiappcommon/Util

INCLUDEPATH += include

HEADERS += include/AppEngine.h \
           include/Window.h

SOURCES += src/AppEngine.cpp \
           src/Window.cpp \
           main.cpp

LIBS += -lhmiappcommon

RESOURCES += qml/qml.qrc
