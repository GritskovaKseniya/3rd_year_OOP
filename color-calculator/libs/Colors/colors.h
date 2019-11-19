#pragma once

#include <string>

namespace libs__Colors {
    
/**
 * Represents Color. Support math and compare operations
*/
class Color {
    public:

        /**
         * Creates color with given RGB values (0-255)
         * Creates black by default
         * 
         * @param red Red part of the Color
         * @param green Green part Of the Color
         * @param blue Blue part of the Сolor
        */
        Color(short red = 0, short green = 0, short blue = 0);
        
        /**
         * Creates copy of given color
         * 
         * @param color Color to copy
        */
        Color(const Color &color);
        
        ~Color();

        /**
         * Hexadecimal representation of object
         * For example: Color(0, 255, 0).toHexCode() == "00ff00"
         * 
         * @return String with hexadecimal number
        */
        std::string toHexCode();

        /**
         * Sums this object with given.
         * Sums up by RGB parts. If result part > 255, it sets equal to 255
         * 
         * @param color Color to summation
         * @return Result color
        */
        Color operator+(const Color &color);

        /**
         * Sums this color with string like "red"
         * Supports all colors from colors namespace
         * If color not supported, returns this color and prints error
         * 
         * @param name String with color name (For example: "green")
         * @return Result color or this color in case of error
        */
        Color operator+(const std::string &name);

        /**
         * Substracts from this color the given
         * Substraction by RGB parts. If result part < 0, it sets to 0
         * 
         * @param color Color that is substracted
         * @return Result color
        */
        Color operator-(const Color &color);

        /**
         * Assigns given color to this
         * 
         * @param color Color, that is assigned
         * @result Color whose values are the same as given color
        */
        Color operator=(const Color &color);

        /**
         * Compare this color with given
         * 
         * @param color Color to compare
         * @return true if colors are equal
        */
        bool operator==(const Color &color);

        bool operator!=(const Color &color);

    private:

        inline short sumChanel(short first, short second);

        inline short diffChanel(short first, short second);

        inline std::string chanelToHexString(short value);

        short red = 0, green = 0, blue = 0;
};

/**
 * Some constant colors to easier usage
*/
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

}
