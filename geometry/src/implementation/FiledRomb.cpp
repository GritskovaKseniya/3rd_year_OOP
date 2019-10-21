#include "../header/Geometry.h"

FilledRomb::~FilledRomb() {
    //
}

int FilledRomb::getFillColor() {
    return fillColor;
}

void FilledRomb::setFillColor(int c) {
    this->fillColor = c;

    update();
}

void FilledRomb::setBorderColor(int c) {
    if (c != this->fillColor) {
        Romb::setBorderColor(c);
    }
}

void FilledRomb::draw() const {
    // TODO
}
