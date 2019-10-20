#include "../header/Geometry.h"

FilledRomb::~FilledRomb() {
    //
}

int FilledRomb::getFillColor() {
    return fillColor;
}

void FilledRomb::setFillColor(int c) {
    this->fillColor = c;
}

void FilledRomb::setBorderColor(int c) {
    if (c != this->fillColor) {
        // TODO: Call another method
    }
}

void FilledRomb::draw() const {
    // TODO
}
