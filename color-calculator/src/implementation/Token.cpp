#include "../header/ColorCalculator.h"

#include <string>

Token::Token() {
    type = EMPTY;
}

Token::Token(libs__Colors::Color color) {
    type = COLOR;
    colorValue = libs__Colors::Color(color);
}

Token::Token(char operation) {
    type = OPERATION;
    operationValue = operation;
}

Token::Token(std::string unknown) {
    type = UNKNOWN;
    unknownValue = unknown;
}

bool Token::isColor() {
    return type == COLOR;
}

bool Token::isEmpty() {
    return type == EMPTY;
}

bool Token::isOperation() {
    return type == OPERATION;
}

libs__Colors::Color Token::getColorValue() {
    return libs__Colors::Color(colorValue);
}

char Token::getOperationValue() {
    return operationValue;
}

std::string Token::getUnknownValue() {
    return unknownValue;
}
