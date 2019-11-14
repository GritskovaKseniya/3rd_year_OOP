#include <string>
#include <sstream>

#include "../header/colors.h"

Color::Color(const Color &color) {
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
}

Color::Color(short red, short green, short blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::~Color() {
    //
}

std::string Color::toHexCode() {
    std::stringstream red, green, blue;
    red << (this->red < 16 ? "0" : "") << std::hex << this->red;
    green << (this->green < 16 ? "0" : "") << std::hex << this->green;
    blue << (this->blue < 16 ? "0" : "") << std::hex << this->blue;

    return red.str() + green.str() + blue.str();
}

Color Color::operator+(Color &color) {
    short red = this->red + color.red > 255 ? 255 : this->red + color.red;
    short green = this->green + color.green > 255 ? 255 : this->green + color.green;
    short blue = this->blue + color.blue > 255 ? 255 : this->blue + color.blue;

    return Color(red, green, blue);
}

Color Color::operator-(Color &color) {
    short red = this->red - color.red < 0 ? 0 : this->red - color.red;
    short green = this->green - color.green < 0 ? 0 : this->green - color.green;
    short blue = this->blue - color.blue < 0 ? 0 : this->blue - color.blue;

    return Color(red, green, blue);
}

Color Color::operator=(Color &color) {
    if (this != &color) {
        this->red = color.red;
        this->green = color.green;
        this->blue = color.blue;
    }

    return *this;
}

bool Color::operator==(Color &color) {
    return this->red == color.red
        && this->green == color.green
        && this->blue == color.blue;
}

bool Color::operator!=(Color &color) {
    return !(*this == color);
}