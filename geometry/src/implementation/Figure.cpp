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
}

void Figure::setBorderColor(int c) {
    this->c = c;
}

int Figure::getBorderColor() const {
    return c;
}

void Figure::setVisible(bool isVisible = true) {
    visible = isVisible;
}

bool Figure::isVisible() const {
    return visible;
}
