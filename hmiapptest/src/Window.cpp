#include "Window.h"
#include "AppEngine.h"

Window::Window(AppEngine* engine)
    : CommonWindow(engine)
{
    const QString rootSceneId("SceneMain");
    const QString rootSceneQml("qrc:/main.qml");
    setRootScene(rootSceneId, rootSceneQml);

    declareScene("scene1", "qrc:/scene1.qml");
}

Window::~Window()
{

}
