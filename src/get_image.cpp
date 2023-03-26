/**
 * @file get_image.cpp
 * @author 5pirit5eal
 * @brief Functions to get images for further processing
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "get_image.h"

#include <iostream>

int get_fixed_image() {
    std::cout << "Enter the fixed image: ";

    return get_image();
}

int get_moving_image() {
    std::cout << "Enter the moving image: ";

    return get_image();
}

int get_image() {
    int input{};
    std::cin >> input;
    return input;
}