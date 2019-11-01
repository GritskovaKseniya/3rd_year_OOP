#include <iostream>

#include "../header/Geometry.h"

void TextRombDrawer::draw(int x, int y, double width, double height, int borderColor, int fillColor) {
    std::cout << "Center x: " << x << std::endl;
    std::cout << "Center y: " << y << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Border color: " << borderColor << std::endl;

    if (fillColor != -1) {
        std::cout << "Fill color: " << fillColor << std::endl;
    }
}