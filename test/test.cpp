#include <cstdlib>
#include <iostream>
#include "../code_point.h"

int main()
{
    using namespace unicode;

    // test code point printing
    std::cout << 0x20_cp << " " << 0xFFFD_cp << " " << 0x10FFFF_cp << "\n";

    // pause
    std::cin.get();
    return EXIT_SUCCESS;
}
