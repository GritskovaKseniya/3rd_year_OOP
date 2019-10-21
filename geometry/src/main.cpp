#include <iostream>

#include "header/Geometry.h"

int main() {
    Romb* romb = new Romb(0, 0, 0, 1, 1);
    FilledRomb* filledRomb = new FilledRomb(0, 1, 0, 0, 1, 1);
    float perimether, area;

    romb->setVisible(); filledRomb->setVisible();

    // Demo: moving romb
    std::cout << "Romb's center x: " << romb->getCenter().x << std::endl;
    std::cout << "Romb's center y: " << romb->getCenter().y << std::endl;
    std::cout << "Moving romb..." << std::endl;
    romb->move(5, 5);
    std::cout << "Romb's new center x: " << romb->getCenter().x << std::endl;
    std::cout << "Romb's new center y: " << romb->getCenter().y << std::endl;
    std::cout << std::endl;

    // Demo: changing romb's paramethers
    std::cout << "Romb width: " << romb->getSizes().width << std::endl;
    std::cout << "Romb height: " << romb->getSizes().height << std::endl;
    romb->calcParams(perimether, area);
    std::cout << "Romb perimether: " << perimether << std::endl;
    std::cout << "Romb area: " << area << std::endl;
    std::cout << "Changing sizes..." << std::endl;
    romb->setSizes(2, 2);
    std::cout << "Romb width: " << romb->getSizes().width << std::endl;
    std::cout << "Romb height: " << romb->getSizes().height << std::endl;
    romb->calcParams(perimether, area);
    std::cout << "Romb perimether: " << perimether << std::endl;
    std::cout << "Romb area: " << area << std::endl;
    std::cout << std::endl;

    // Demo: changing romb's border color
    std::cout << "Romb border color: " << romb->getBorderColor() << std::endl;
    std::cout << "Changing border color..." << std::endl;
    romb->setBorderColor(1);
    std::cout << "New romb border color: " << romb->getBorderColor() << std::endl;
    std::cout << std::endl;

    // Demo: polymorphism. Border color doesn't changes
    std::cout << "Filled romb border color: " << filledRomb->getBorderColor() << std::endl;
    std::cout << "Filled romb fill color: " << filledRomb->getFillColor() << std::endl;
    std::cout << "Trying to change border color to 1..." << std::endl;
    filledRomb->setBorderColor(1);
    std::cout << "New filled romb border color: " << filledRomb->getBorderColor() << std::endl;
    
    delete romb;
    delete filledRomb;
    
    return 0;
}
