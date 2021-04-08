#include <QQmlContext>
#include "CommonWindow.h"
#include "HmiAppEngineBase.h"
#include "SceneController.h"

using namespace hmiappcommon;

CommonWindow::CommonWindow(HmiAppEngineBase* engine)
    : pEngine(engine)
    , pContext(nullptr)
    , pSceneController(nullptr)
{
    pContext = std::make_unique<QQmlContext>(pEngine->getQmlEngine()->rootContext());

    pSceneController = std::make_unique<SceneController>(this);
    pContext->setContextProperty("SceneController", pSceneController.get());
}

CommonWindow::~CommonWindow()
{

}

QQmlContext *CommonWindow::getContext()
{
    return pContext.get();
}

HmiAppEngineBase *CommonWindow::getHmiAppEngine()
{
    return pEngine;
}

void CommonWindow::setRootScene(const QString &sceneId, const QString qmlPath)
{
    pSceneController->setRootScene(sceneId, qmlPath);
}

void CommonWindow::declareScene(const QString &sceneId, const QString qmlPath)
{
    pSceneController->declareScene(sceneId, qmlPath);
}
