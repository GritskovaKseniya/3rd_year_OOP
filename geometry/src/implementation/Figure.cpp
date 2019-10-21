#include "../header/Geometry.h"

Figure::Figure(int c, int x, int y) {
    this->c = c;
    this->x = x;
    this->y = y;
    visible = false;
}

Figure::~Figure() {
    //
}

void Figure::move(int dx, int dy) {
    x+=dx;
    y+=dy;

    update();
}

void Figure::setBorderColor(int c) {
    this->c = c;

    update();
}

int Figure::getBorderColor() const {
    return c;
}

void Figure::setVisible(bool isVisible) {
    visible = isVisible;

    update();
}

bool Figure::isVisible() const {
    return visible;
}
