
// *****************************************************************************

#include "Zero.h"
#include "Utility/Ruby/Ruby.h"

#include <iostream>

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

int main(int argc, char** argv)
{
    // JSON Test
    JSON json;
    json.loadFromFile("./main.cfg");

    for (auto& entry : json)
    {
        std::cout << entry.name.GetString() << " : " << entry.value.GetString() << std::endl;
    }

    // Ruby Test
    Ruby::VM ruby;
    ruby.init(argc, argv);
    ruby.run("./hello.rb");
    ruby.shutdown();

    system("pause");

    return 0;
}
