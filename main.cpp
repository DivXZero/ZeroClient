
// *****************************************************************************

#include "zero.h"
#include "utility/ruby/ruby.h"
#include "system/window/sfmlwindow.h"
#include "system/window/win32window.h"

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
    // Window Test
    // *************************************************************************
    banner("Window Test", false);
    System::SFMLWindow window;
    if (window.create())
        std::cout << "Window Initialized..." << std::endl;

    // *************************************************************************
    // JSON Test
    // *************************************************************************
    banner("JSON Test");
    JSON json;
    json.loadFromFile("./main.cfg");
    for (auto& entry : json)
    {
        std::cout << entry.name.GetString() << " : " << entry.value.GetString() << std::endl;
    }

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
        window.pollEvents();
        ruby.update();
    }

    // *************************************************************************
    // Cleanup
    // *************************************************************************
    ruby.shutdown();

    return 0;
}
