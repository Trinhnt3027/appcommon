TEMPLATE = app
QT += quick
CONFIG += c++14

INCLUDEPATH += ../../Common/include/hmiappcommon/hmi

INCLUDEPATH += include/

HEADERS += include/AppEngine.h \
           include/Window.h

SOURCES += src/AppEngine.cpp \
           src/Window.cpp \
           main.cpp

COMMON_LIB_DIR = /home/trinhnt/WorkSpace/Qt_Projects/Common/lib
LIBS += -L$$COMMON_LIB_DIR -lhmiappcommon
UTIL_LIB_DIR = /home/trinhnt/WorkSpace/C++_Projects/install/lib
LIBS += -L$$UTIL_LIB_DIR -lUtility

RESOURCES += qml/qml.qrc
