/**
 * @file HelloWorld.cpp
 * @author 5pirit5eal
 * @brief Test programm to learn cpp
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022
 *
 */

// preprocessor directive -> import of libraries, here standard lib iostream
#include <iostream>

/**
 * @brief Labratory for different c++ functionality.
 *
 * main function is necessary or it will fail to link
 *
 * @return int
 */
int main() {
    // things executed in main

    // initialized variable x (identifier: "x", type: int, assignement: 5
    //
    int x{};
    int y{};
    // zero initialization, only use if the value will be replaced
    // int x{};

    // cout: character output, <<: send letters or numbers to the console
    std::cout << "Enter two numbers separated by a space: ";
    // cin get number from keyboard and store it in variable x
    std::cin >> x >> y;
    std::cout << "Hello, World!" << '\n';
    std::cout << "x+y is equal to: " << x + y << '\n';
    // last statement of the programm, status message "Sucessfull"
    return 0;
}
