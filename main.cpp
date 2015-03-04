
// *****************************************************************************

#include "Zero.h"
#include "Utility/Ruby/Ruby.h"

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
    // JSON Test

    banner("JSON Test", false);
    JSON json;
    json.loadFromFile("./main.cfg");

    for (auto& entry : json)
    {
        std::cout << entry.name.GetString() << " : " << entry.value.GetString() << std::endl;
    }

    // Ruby Test

    banner("Ruby Test");
    Ruby::VM ruby;
    ruby.init(argc, argv);

    ruby.load("./hello.rb");

    for (int i = 0; i < 10000000; i++)
        ruby.update();

    ruby.shutdown();

    system("pause");

    return 0;
}
