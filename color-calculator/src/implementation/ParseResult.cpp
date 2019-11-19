#include "../header/ColorCalculator.h"

#include <string>

ParseResult::ParseResult(libs__Colors::Color color) {
    result = libs__Colors::Color(color);
    error = "NULL";
}

ParseResult::ParseResult(std::string error) {
    this->error = error;
}
bool ParseResult::isError() {
    return error.compare("NULL") != 0;
}

libs__Colors::Color ParseResult::getResult() {
    return libs__Colors::Color(result);
}

std::string ParseResult::getError() {
    return error;
}
