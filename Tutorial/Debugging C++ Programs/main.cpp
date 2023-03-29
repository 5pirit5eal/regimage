#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Log.h>  // Step 1: include the logger headers

#include <iostream>

#include "add.h"

// int add(int x, int y);  // forward declaration using function prototype

int main() {
    //!
    std::cerr << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}