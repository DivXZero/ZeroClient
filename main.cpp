
// *****************************************************************************

#include "zero.h"
#include "system/graphics/glscene.h"

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

class ExampleScene : public Graphics::GLScene
{
public:
    void init() {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    }

    void render() {
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

// *****************************************************************************

int main(int argc, char** argv)
{
    JSON gameConfig;
    if (!gameConfig.loadFromFile("./main.cfg"))
        return -1;

    const char* title = gameConfig.getValue("title").GetString();
    int width = gameConfig.getValue("width").GetInt();
    int height = gameConfig.getValue("height").GetInt();
    bool fullscreen = gameConfig.getValue("fullscreen").GetBool();

    getGame()->init();
    getGame()->window()->create(width, height, title, fullscreen);
    getGame()->sceneMgr()->push<ExampleScene>();
    getGame()->TEMPscriptMgr()->load("./hello.rb");
    getGame()->run();
    getGame()->cleanup();

    return 0;
}
