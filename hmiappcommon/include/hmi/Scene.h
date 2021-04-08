#pragma once
#include <QObject>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQuickItem>

namespace hmiappcommon
{
class CommonWindow;

struct SceneInfo {
    SceneInfo(const QString& sceneId, const QString& qmlPath)
        : mSceneId(sceneId), mQmlPath(qmlPath) {}

    QString mSceneId;
    QString mQmlPath;
};

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(CommonWindow* parentWindow, SceneInfo* sceneInfo);
    virtual ~Scene();

    QString getSceneId() const;

    virtual void onContext(QQmlContext* context);
    virtual void onCreated();

private:
    void create();
    void destroy();


private:
    CommonWindow* pParentWindow;
    SceneInfo* pSceneInfo;
    QQmlComponent* pQmlComponent;
    std::unique_ptr<QQmlContext> pContext;
    QQuickItem* pQmlObject;
};

} // namespace hmiappcommon
