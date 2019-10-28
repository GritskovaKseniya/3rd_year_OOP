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
    if (visible) {
        x+=dx;
        y+=dy;

        draw();
    }
}

Point Figure::getCenter() {
    Point point;

    point.x = x;
    point.y = y;

    return point;
}

void Figure::setBorderColor(int c) {
    if (visible) {
        this->c = c;

        draw();
    }
}

int Figure::getBorderColor() const {
    return c;
}

void Figure::setVisible(bool isVisible) {
    bool oldVisible = visible;
    visible = isVisible;

    if (oldVisible == false && visible == true) {
        draw();
    }
}

bool Figure::isVisible() const {
    return visible;
}
