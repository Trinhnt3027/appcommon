TEMPLATE = lib
TARGET   = hmiappcommon
QT      += qml quick core
CONFIG  += plugin c++14

BASE_INCLUDE_PATH = /usr/local/include

INCLUDEPATH += $$BASE_INCLUDE_PATH/Utility

INCLUDEPATH += include/
INCLUDEPATH += include/hmi
INCLUDEPATH += include/Util

#
HEADERS += \
           include/hmi/HmiAppEngineBase.h \
           include/hmi/CommonWindow.h \
           include/hmi/Scene.h \
           include/hmi/SceneController.h \
           include/Util/HLog.h \

SOURCES += \
           src/hmi/HmiAppEngineBase.cpp \
           src/hmi/CommonWindow.cpp \
           src/hmi/Scene.cpp \
           src/hmi/SceneController.cpp \
           src/Util/HLog.cpp \

INSTALL_DIR = /usr/local
#DIR_INSTALL = /home/trinhnt/WorkSpace/Qt_Projects/Build

#DESTDIR = $$DIR_INSTALL/lib

#UTIL_LIB_DIR = /home/trinhnt/WorkSpace/C++_Projects/install/lib
LIBS += -lUtility

#copyCommands.commands += echo Copy library data...
#copyCommands.commands += && mkdir -p $$INSTALL_DIR/include/$$TARGET
#copyCommands.commands += && cp -r $$PWD/include/* $$INSTALL_DIR/include/$$TARGET
#copyCommands.commands += && echo Copy done!!!
#first.depends          = $(first) copyCommands
#QMAKE_EXTRA_TARGETS   += first copyCommands

target.path = $$INSTALL_DIR/lib
header.path   = $$INSTALL_DIR/include/$$TARGET
header.files  = $$files(include/*)

INSTALLS += header target
