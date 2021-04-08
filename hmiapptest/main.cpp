#include <QGuiApplication>
#include "AppEngine.h"
#include "Window.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    const QString appId("TESTAPP");
    AppEngine engine(appId);
    engine.start();
    engine.getWindow()->show();

    return app.exec();
}
