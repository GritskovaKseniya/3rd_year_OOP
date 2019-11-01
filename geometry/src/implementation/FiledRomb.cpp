#include <iostream>

#include "../header/Geometry.h"

FilledRomb::~FilledRomb() {
    //
}

int FilledRomb::getFillColor() {
    return fillColor;
}

void FilledRomb::setFillColor(int c) {
    if (isVisible()) {
        this->fillColor = c;

        draw();
    }
}

void FilledRomb::setBorderColor(int c) {
    if (c != this->fillColor) {
        Romb::setBorderColor(c);
    }
}

void FilledRomb::draw() const {
    std::cout << "### FILLED ROMB DRAW ###" << std::endl;
    drawer->draw(x, y, width, height, getBorderColor(), fillColor);
    std::cout << "### END OF FILLED ROMB DRAW ###" << std::endl;
}
