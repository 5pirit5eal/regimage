#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Log.h>  // Step 1: include the logger headers

#include <iostream>

#include "add.h"
#define DEBUG

// int add(int x, int y);  // forward declaration using function prototype
int getUserInput() {
    PLOGD << "getUserInput() called";

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main() {
    plog::init(plog::debug, "Logfile.log");
    PLOGD << "main() called";

    int x{getUserInput()};
#ifdef DEBUG
    std::cout << "You entered: " << x;
#endif

    return 0;
}