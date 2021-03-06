#include <iostream>
#include "NameGenerator.h"

using namespace codesmith;

int main(int argc, char** argv)
{
    Names gen;
    std::cout << "Always 10 random names:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << ": " << gen.firstName(2) << " " << gen.lastName(4) << std::endl;
    }

    Names gen2(1234);
    std::cout << "Always same names (seed 1234):" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << ": " << gen2.firstName(2) << " " << gen2.lastName(4) << std::endl;
    }

    Names gen3;
    std::cout << "Always 10 random names using fullName methods:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "first last: " << gen3.fullName() << std::endl;
        std::cout << "last first: " << gen3.fullNameReversed() << std::endl;
    }


    return 0;
}
