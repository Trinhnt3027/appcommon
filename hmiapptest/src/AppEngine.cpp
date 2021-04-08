#include <memory>
#include "AppEngine.h"
#include "Window.h"
#include <QDebug>
#include <QQuickItem>

AppEngine::AppEngine(const QString &appId)
    : HmiAppEngineBase(appId)
{
    std::unique_ptr<Window> windowPtr = std::make_unique<Window>(this);
    declareWindow(std::move(windowPtr));
}

AppEngine::~AppEngine()
{

}

void AppEngine::start()
{

}
