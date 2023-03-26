/**
 * @brief Request two images and registers them to eachother
 *
 * @return int
 */
#include "get_image.h"
#include "register.h"

int main() {
    // initialize variabesl
    int moving_img{get_moving_image()};
    int fixed_img{get_fixed_image()};

    // Register images
    register_images(fixed_img, moving_img);

    return 0;
}