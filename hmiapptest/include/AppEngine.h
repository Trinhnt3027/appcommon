#pragma once
#include <HmiAppEngineBase.h>

using namespace hmiappcommon;

class AppEngine : public HmiAppEngineBase {
public:
    AppEngine(const QString& appId);
    ~AppEngine();

    void start() override;
};
