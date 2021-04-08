#include "SceneController.h"
#include "CommonWindow.h"
#include "Scene.h"
#include "HLog.h"

using namespace hmiappcommon;

SceneController::SceneController(CommonWindow* parentWindow)
    : pParentWindow(parentWindow)
{
}

SceneController::~SceneController()
{

}

void SceneController::setRootScene(const QString& sceneId, const QString& qmlPath)
{
    HInfo() << " >> sceneId: " << sceneId << " qmlPath: " << qmlPath;
    if (pSceneStack.count() > 0) {
        HWarning() << "Scene root already added, can not set root scene any more!";
    }
    else {
        declareScene(sceneId, qmlPath);
        pushScene(sceneId);
    }
}

void SceneController::pushScene(const QString &sceneId)
{
    HInfo() << " sceneId: " << sceneId;
    bool sceneIsDeclared{false};
    for (const auto& sceneInfo : pSceneInfoList) {
        if (sceneInfo->mSceneId == sceneId) {
            sceneIsDeclared = true;
            std::shared_ptr<Scene> sceneRef = std::make_shared<Scene>(pParentWindow, sceneInfo.get());
            pSceneStack.push_back(sceneRef);
        }
    }

    if (!sceneIsDeclared) {
        HWarning() << "Scene is not declared: " << sceneId;
    }
}

void SceneController::popScene()
{
    if (pSceneStack.count() == 1) {
        HWarning() << "Current scene is root scene, can not pop!";
    }
    else {
        HInfo() << " sceneId: " << pSceneStack.top()->getSceneId();
        pSceneStack.pop();
    }
}

void SceneController::declareScene(const QString &sceneId, const QString &qmlPath)
{
    HInfo() << " sceneId: " << sceneId << " qmlPath: " << qmlPath;
    bool sceneIsAdded{false};
    for (const auto& sceneInfo : pSceneInfoList) {
        if (sceneInfo->mSceneId == sceneId) {
            sceneIsAdded = true;
            HInfo() << "Scene id already added: " << sceneId;
            break;
        }
    }

    if (!sceneIsAdded) {
        pSceneInfoList.push_back(std::make_shared<SceneInfo>(sceneId, qmlPath));
    }
}

CommonWindow* SceneController::getParentWindow()
{
    return  pParentWindow;
}
