#include <string>
#include <sstream>
#include <iostream>
#include <map>

#include "../header/colors.h"

static const std::map<std::string, Color> STRING_TO_COLOR = {
    {"black", colors::BLACK},
    {"gray", colors::GRAY},
    {"silver", colors::SILVER},
    {"white", colors::WHITE},
    {"fuchsia", colors::FUCHSIA},
    {"purple", colors::PURPLE},
    {"red", colors::RED},
    {"maroon", colors::MAROON},
    {"yellow", colors::YELLOW},
    {"olive", colors::OLIVE},
    {"lime", colors::LIME},
    {"green", colors::GREEN},
    {"aqua", colors::AQUA},
    {"teal", colors::TEAL},
    {"blue", colors::BLUE},
    {"navy", colors::NAVY}
};

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
    std::string red, green, blue;
    red = chanelToHexString(this->red);
    green = chanelToHexString(this->green);
    blue = chanelToHexString(this->green);

    return red + green + blue;
}

short Color::sumChanel(short first, short second) {
    return first + second > 255 ? 255 : first + second;
}

short Color::diffChanel(short first, short second) {
    return first - second < 0 ? 0 : first - second;
}

std::string Color::chanelToHexString(short value) {
    std::stringstream stream;
    stream << (value < 16 ? "0" : "") << std::hex << value;

    return stream.str();
}

Color Color::operator+(const Color &color) {
    short red = sumChanel(this->red, color.red);
    short green = sumChanel(this->green, color.green);
    short blue = sumChanel(this->blue, color.blue);

    return Color(red, green, blue);
}

Color Color::operator+(const std::string &name) {
    if (STRING_TO_COLOR.count(name) == 0) {
        std::cerr << "Color " << name << " doesn't exist. Please use Color class" << std::endl;
        return *this;
    }

    return *this + STRING_TO_COLOR.at(name);
}

Color Color::operator-(const Color &color) {
    short red = diffChanel(this->red, color.red);
    short green = diffChanel(this->green, color.green);
    short blue = diffChanel(this->blue, color.blue);

    return Color(red, green, blue);
}

Color Color::operator=(const Color &color) {
    if (this != &color) {
        this->red = color.red;
        this->green = color.green;
        this->blue = color.blue;
    }

    return *this;
}

bool Color::operator==(const Color &color) {
    return this->red == color.red
        && this->green == color.green
        && this->blue == color.blue;
}

bool Color::operator!=(const Color &color) {
    return !(*this == color);
}
