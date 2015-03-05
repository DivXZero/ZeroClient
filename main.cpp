
// *****************************************************************************

#include "zero.h"
#include "utility/ruby/ruby.h"
#include "system/window/sfmlwindow.h"
#include "system/graphics/glscene.h"
#include "system/graphics/scenemanager.h"

#include <iostream>

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

void banner(const char* msg, bool preReturn = true)
{
    if (preReturn)
        std::cout << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "  " << msg << std::endl;
    std::cout << "================================================" << std::endl;
}

// *****************************************************************************

int main(int argc, char** argv)
{
    // *************************************************************************
    // JSON Test
    // *************************************************************************
    banner("JSON Test", false);
    JSON json;
    json.loadFromFile("./main.cfg");
    for (auto& entry : json)
    {
        std::cout << entry.name.GetString() << " : " << entry.value.GetString() << std::endl;
    }

    // *************************************************************************
    // Window Test
    // *************************************************************************
    banner("Window Test");
    System::SFMLWindow window;
    if (window.create())
        std::cout << "Window Initialized..." << std::endl;

    // *************************************************************************
    // Scene Test
    // *************************************************************************
    banner("Scene Test");
    Graphics::SceneManager scnMgr;
    std::shared_ptr<Graphics::GLScene> glScene(new Graphics::GLScene);
    scnMgr.push(glScene);

    // *************************************************************************
    // Ruby Test
    // *************************************************************************
    banner("Ruby Test");
    Ruby::VM ruby;
    ruby.init(argc, argv);
    ruby.load("./hello.rb");

    // *************************************************************************
    // Main Loop
    // *************************************************************************
    while (window.isOpen())
    {
        ruby.update();

        scnMgr.update();
        scnMgr.render();

        window.pollEvents();
        window.swapBuffers();
    }

    // *************************************************************************
    // Cleanup
    // *************************************************************************
    ruby.shutdown();

    return 0;
}
