#include "Scene.h"
#include "CommonWindow.h"
#include "HmiAppEngineBase.h"
#include "HLog.h"

#include <QtCore/QtGlobal>

using namespace hmiappcommon;
using namespace Utility::Logger;


Scene::Scene(CommonWindow* parentWindow, SceneInfo* sceneInfo)
    : pParentWindow(parentWindow)
    , pSceneInfo(sceneInfo)
    , pQmlComponent(nullptr)
    , pContext(nullptr)
{
    create();
}

Scene::~Scene()
{
    destroy();
}

QString Scene::getSceneId() const
{
    return pSceneInfo->mSceneId;
}

void Scene::onContext(QQmlContext *context)
{
    Q_UNUSED(context);
    HInfo() << " sceneId:" << pSceneInfo->mSceneId;
}

void Scene::onCreated()
{
    HInfo() << " sceneId:" << pSceneInfo->mSceneId;
}

void Scene::create()
{
    pContext = std::make_unique<QQmlContext>(pParentWindow->getContext());
    pContext->setContextProperty("scene", this);
    onContext(pContext.get());

    pQmlComponent = new QQmlComponent(pParentWindow->getHmiAppEngine()->getQmlEngine(), pSceneInfo->mQmlPath);
    pQmlObject = qobject_cast<QQuickItem*>(pQmlComponent->create(pContext.get()));

    QQuickItem* parentItem = pParentWindow->contentItem();
    pParentWindow->setWidth(pQmlObject->width());
    pParentWindow->setHeight(pQmlObject->height());
    pQmlObject->setParent(parentItem);
    pQmlObject->setParentItem(parentItem);
    QQmlEngine::setObjectOwnership(pQmlObject, QQmlEngine::CppOwnership);

    onCreated();
}

void Scene::destroy()
{
    if (pQmlComponent != nullptr) {
        pQmlComponent->deleteLater();
    }
    if (pQmlObject != nullptr) {
        pQmlObject->deleteLater();
    }
    HInfo() << " sceneId:" << pSceneInfo->mSceneId;
}
