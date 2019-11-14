#pragma once

#include <string>

class Color {
    public:

        Color(short red = 0, short green = 0, short blue = 0);
        
        Color(const Color &color);
        
        ~Color();

        std::string toHexCode();

        Color operator+(const Color &color);

        Color operator+(const std::string &name);

        Color operator-(const Color &color);

        Color operator=(const Color &color);

        bool operator==(const Color &color);

        bool operator!=(const Color &color);

    private:

        short red = 0, green = 0, blue = 0;
};

namespace colors {
    const Color BLACK = Color(0, 0, 0);
    const Color GRAY = Color(128, 128, 128);
    const Color SILVER = Color(192, 192, 192);
    const Color WHITE = Color(255, 255, 255);

    const Color FUCHSIA = Color(255, 0, 255);
    const Color PURPLE = Color(128, 0, 128);
    const Color RED = Color(255, 0, 0);
    const Color MAROON = Color(128, 0, 0);

    const Color YELLOW = Color(255, 255, 0);
    const Color OLIVE = Color(128, 128, 0);
    const Color LIME = Color(0, 255, 0);
    const Color GREEN = Color(0, 128, 0);

    const Color AQUA = Color(0, 255, 255);
    const Color TEAL = Color(0, 128, 128);
    const Color BLUE = Color(0, 0, 255);
    const Color NAVY = Color(0, 0, 128);
}