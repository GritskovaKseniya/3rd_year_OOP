#include <iostream>

#include "header/Geometry.h"

int main(int argc, char **argv) {
    Romb* romb = new Romb(0, 0, 0, 1, 1);
    FilledRomb* filledRomb = new FilledRomb(0, 1, 0, 0, 1, 1);
    Figure* figure;
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

    // Demo: polymorphism
    figure = romb;
    std::cout << "Figure(Romb) border color: " << figure->getBorderColor() << std::endl;
    std::cout << "Trying to change border color to 2..." << std::endl;
    figure->setBorderColor(2);
    std::cout << "New Figure(Romb) border color: " << figure->getBorderColor() << std::endl;
    figure = filledRomb;
    std::cout << "Figure(FilledRomb) border color: " << figure->getBorderColor() << std::endl;
    std::cout << "Trying to change border color to 1..." << std::endl;
    figure->setBorderColor(1);
    std::cout << "New Figure(FilledRomb) border color: " << figure->getBorderColor() << std::endl;
    
    delete romb;
    delete filledRomb;

    SVGRomb* svgRomb = new SVGRomb(0, 50, 50, 100, 100, argv[1], argv[2]);
    SVGFilledRomb* svgFilledRomb = new SVGFilledRomb(0, 1, 50, 50, 100, 100, argv[1], argv[2]);
    svgRomb->setVisible(); svgFilledRomb->setVisible();
    delete svgRomb; delete svgFilledRomb;
    
    return 0;
}
