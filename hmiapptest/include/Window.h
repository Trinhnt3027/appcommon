#pragma once

#include <CommonWindow.h>

using namespace hmiappcommon;

class AppEngine;

class Window : public CommonWindow {
public:
    Window(AppEngine* engine);
    ~Window();
};
