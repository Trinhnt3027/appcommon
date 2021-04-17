#include "HmiAppEngineBase.h"
#include "CommonWindow.h"
#include "HLog.h"

#include <Logger/Logger.h>

using namespace hmiappcommon;
using namespace Utility::Logger;

HmiAppEngineBase::HmiAppEngineBase(const QString& appId)
    : mAppId(appId)
    , pQmlEngine(nullptr)
    , pWindow(nullptr)
{
    Logger::getInstance().initialize(mAppId.toStdString(), {LogOutput::FILE});
    HInfo() << "Loading App Info: " << mAppId;

    pQmlEngine = std::make_unique<QQmlEngine>();
}

HmiAppEngineBase::~HmiAppEngineBase()
{

}

void HmiAppEngineBase::declareWindow(std::unique_ptr<CommonWindow> &&window)
{
    pWindow = std::move(window);
}

QQmlEngine* HmiAppEngineBase::getQmlEngine()
{
    return pQmlEngine.get();
}

CommonWindow *HmiAppEngineBase::getWindow()
{
    return pWindow.get();
}

void HmiAppEngineBase::start()
{
    HInfo();
}
