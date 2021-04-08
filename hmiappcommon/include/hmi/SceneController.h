#pragma once
#include <memory>
#include <QObject>
#include <QStack>

namespace hmiappcommon
{
class CommonWindow;
class Scene;
class SceneInfo;

class SceneController : public QObject
{
    Q_OBJECT
public:
    explicit SceneController(CommonWindow* parentWindow);
    virtual ~SceneController();

    void setRootScene(const QString& sceneId, const QString& qmlPath);

    Q_INVOKABLE void pushScene(const QString& sceneId);
    Q_INVOKABLE void popScene();

    void declareScene(const QString& sceneId, const QString& qmlPath);

    CommonWindow* getParentWindow();

private:
    CommonWindow* pParentWindow;
    QStack<std::shared_ptr<Scene>> pSceneStack;
    QList<std::shared_ptr<SceneInfo>> pSceneInfoList;
};

} // namespace hmiappcommon
