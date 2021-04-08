#include "commoncomponent_plugin.h"
#include "myitem.h"
#include <qqml.h>

void CommoncomponentPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
//    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
    qmlRegisterType(QUrl("qrc:/BaseButton.qml"), uri, 1, 0, "BaseButton");
}

