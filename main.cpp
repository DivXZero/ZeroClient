
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

    void update() {
        // update stuff
    }

    void render() {
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

// *****************************************************************************

int main(int argc, char** argv)
{
    auto game = ZeroGame::Instance();
    game->init();
    game->window()->create();
    game->sceneMgr()->push<ExampleScene>();
    //game->TEMPscriptMgr()->load("./hello.rb");
    game->run();
    game->cleanup();

    return 0;
}
