#include <iostream>
#include "header/colors.h"

int main() {
    Color red = Color(255, 0, 0);
    Color green = Color(0, 255, 0);

    std::cout << "Red: " << red.toHexCode() << std::endl;
    std::cout << "Green: " << green.toHexCode() << std::endl;

    Color newRed = Color(red);

    std::cout << "Copied red: " << newRed.toHexCode() << std::endl;

    Color yellow = red + green;

    std::cout << "Red + green:" << yellow.toHexCode() << std::endl;

    Color black = red - red;

    std::cout << "Red - red: " << black.toHexCode() << std::endl;

    std::cout << "Compare red and red: " << (red == red) << std::endl;

    std::cout << "Compare red and green: " << (red == green) << std::endl; 

    return 0;
}
