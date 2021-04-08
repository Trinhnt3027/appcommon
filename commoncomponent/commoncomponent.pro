TEMPLATE = lib
TARGET = commoncomponent
QT += qml quick
CONFIG += plugin c++11


INCLUDEPATH += include/

# Input
SOURCES += \
        src/commoncomponent_plugin.cpp \
        src/myitem.cpp

HEADERS += \
        include/commoncomponent_plugin.h \
        include/myitem.h

RESOURCES += qml/qml.qrc

INSTALL_DIR = $$PWD/../../Common

DESTDIR = $$INSTALL_DIR/lib

copyCommands.commands += echo Copy library data...
copyCommands.commands += && mkdir -p $$INSTALL_DIR/qml/$$TARGET
copyCommands.commands += && cp -r $$PWD/qml/* $$INSTALL_DIR/qml/$$TARGET
copyCommands.commands += && echo Copy done!!!
first.depends          = $(first) copyCommands
QMAKE_EXTRA_TARGETS   += first copyCommands

target.path = $$INSTALL_DIR/lib
qml.path   = $$INSTALL_DIR/qml/$$TARGET
qml.files  = $$files(qml/*)

INSTALLS += qml target
