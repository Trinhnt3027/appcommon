#ifndef COMMONCOMPONENT_PLUGIN_H
#define COMMONCOMPONENT_PLUGIN_H

#include <QQmlExtensionPlugin>

class CommoncomponentPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // COMMONCOMPONENT_PLUGIN_H
