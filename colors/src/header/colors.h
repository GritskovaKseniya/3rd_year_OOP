#pragma once

#include <string>

class Color {
    public:

        Color(short red = 0, short green = 0, short blue = 0);
        
        Color(const Color &color);
        
        ~Color();

        std::string toHexCode();

        Color operator+(Color &color);

        Color operator-(Color &color);

        Color operator=(Color &color);

        bool operator==(Color &color);

        bool operator!=(Color &color);

    private:

        short red = 0, green = 0, blue = 0;
};
