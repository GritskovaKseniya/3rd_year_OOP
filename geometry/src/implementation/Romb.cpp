#include <math.h>
#include <iostream>

#include "../header/Geometry.h"


Romb::~Romb() {
    delete drawer;
}

void Romb::calcParams(float& perimeter, float& area) const {
    perimeter = 2*sqrt(width*width + height*height);
    area = (width* height)/2;
}

void Romb::draw() const {
    std::cout << "### ROMB DRAW ###" << std::endl;
    drawer->draw(x, y, width, height, getBorderColor());
    std::cout << "### END OF ROMB DRAW ###" << std::endl;
}

RombSizes Romb::getSizes() {
    RombSizes sizes;
    
    sizes.width = width;
    sizes.height = height;

    return sizes;
}

void Romb::setSizes(double widht, double height) {
    if (sizesIsCorrect(widht, height) && isVisible()) {
        this->width = widht;
        this->height = height;

        draw();
    }
}

bool Romb::sizesIsCorrect(double width, double height) {
    return width > 0 && height > 0;
}
