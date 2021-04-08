#pragma once
#include <QQuickWindow>

namespace hmiappcommon
{
class HmiAppEngineBase;
class SceneController;

class CommonWindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit CommonWindow(HmiAppEngineBase* engine);
    virtual ~CommonWindow();

    QQmlContext* getContext();
    HmiAppEngineBase* getHmiAppEngine();

protected:
    void setRootScene(const QString& sceneId, const QString qmlPath);
    void declareScene(const QString& sceneId, const QString qmlPath);

private:
    HmiAppEngineBase* pEngine;
    std::unique_ptr<QQmlContext> pContext;
    std::unique_ptr<SceneController> pSceneController;
};

} // namespace hmiappcommon
