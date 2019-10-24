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
    Romb::draw();
    std::cout << "Fill color: " << fillColor << std::endl;
}
