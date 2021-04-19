#pragma once

#include <QQmlEngine>
#include <memory>

namespace hmiappcommon
{
class CommonWindow;

class HmiAppEngineBase
{
public:
    explicit HmiAppEngineBase(const QString& appId);
    virtual ~HmiAppEngineBase();

    void declareWindow(std::unique_ptr<CommonWindow>&& window);

    QQmlEngine* getQmlEngine();
    CommonWindow* getWindow();

    template<typename T>
    T* getHmiEngine()
    {
        return static_cast<T*>(getEngine());
    }

    virtual void start();

private:
    HmiAppEngineBase* getEngine();

private:
    QString mAppId;
    std::unique_ptr<QQmlEngine> pQmlEngine;
    std::unique_ptr<CommonWindow> pWindow;
};

} // namespace hmiappcommon
