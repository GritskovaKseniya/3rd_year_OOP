#include <iostream>

#include "header/Geometry.h"

int main(int argc, char **argv) {
    Romb* romb = new Romb(0, 50, 50, 100, 100, new SVGRombDrawer(argv[1], std::string(argv[2]) + "Romb.html"));
    FilledRomb* filledRomb = new FilledRomb(0, 128, 50, 50, 100, 100, new SVGRombDrawer(argv[1], std::string(argv[2]) + "FilledRomb.html"));
    Figure* figure;
    float perimether, area;

    romb->setVisible(); filledRomb->setVisible();

    std::cout << "Open files " 
        << std::string(argv[2]) + "Romb.html" 
        << " and " 
        << std::string(argv[2]) + "FilledRomb.html" 
        << " in your browser" << std::endl; 

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
    romb->setSizes(105, 105);
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

    // Demo: polymorphism
    figure = romb;
    std::cout << "Figure(Romb) border color: " << figure->getBorderColor() << std::endl;
    std::cout << "Trying to change border color to 2..." << std::endl;
    figure->setBorderColor(2);
    std::cout << "New Figure(Romb) border color: " << figure->getBorderColor() << std::endl;
    figure = filledRomb;
    std::cout << "Figure(FilledRomb) border color: " << figure->getBorderColor() << std::endl;
    std::cout << "Trying to change border color to 1..." << std::endl;
    figure->setBorderColor(128);
    std::cout << "New Figure(FilledRomb) border color: " << figure->getBorderColor() << std::endl;
    
    delete romb;
    delete filledRomb;
    
    return 0;
}
