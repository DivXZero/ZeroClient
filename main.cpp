
// *****************************************************************************

#include "Utility/Ruby/Ruby.h"

// *****************************************************************************

using namespace Zero;

// *****************************************************************************

int main(int argc, char** argv)
{
    Ruby::VM ruby;

    ruby.init(argc, argv);

    ruby.run("./hello.rb");

    ruby.shutdown();

    system("pause");

    return 0;
}