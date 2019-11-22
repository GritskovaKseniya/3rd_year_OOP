#pragma once

#include "../../libs/Colors/colors.h"

#include <string>

bool startsWith(std::string predicate, std::string string);

bool applyOpperation(
    char operation,
    libs__Colors::Color &result,
    libs__Colors::Color first,
    libs__Colors::Color second
);
