#include "../header/ColorCalculator.h"
#include "../header/utils.h"

#include <string>
#include <algorithm>

Tokenizer::Tokenizer(std::string expression) {
    std::transform(
        expression.begin(),
        expression.end(),
        expression.begin(),
        [](unsigned char c){ return std::tolower(c); }
    );

    tokenizer = libs__ExpressionAnalyserSt::Tokenizer(expression);
}

Token Tokenizer::nextToken() {
    libs__ExpressionAnalyserSt::Token token = tokenizer.next_token();

    if (token.is_empty()) {
        return Token();
    }

    if (token.is_oper()) {
        char operation = token.get_oper();

        if (operation == '+' || operation == '-') {
            return Token(operation);
        } else {
            return Token("'*' and '/' not supported");
        }
    }

    if (token.is_number() || token.is_bracket()) {
        return Token("NUMBER OR BRACKET");
    }

    std::string unknownValue = token.get_unknown();

    if (unknownValue != "rgb") {

        if (startsWith("\"", unknownValue) || startsWith("'", unknownValue)) { // If Unknown value is a Color's name
            std::string colorName = unknownValue.substr(1, unknownValue.length()-2);
            libs__Colors::Color black;

            if (colorName == "black") {
                return Token(black);
            }

            libs__Colors::Color result = black + colorName;

            if (result == libs__Colors::colors::BLACK) { // Error when summation. Color's name doesn't exist
                return Token(unknownValue);
            }

            return Token(result);
        } else { // Unknown value not color's name and not rgb function
            return Token(unknownValue);
        }

    }

    // Construct color Token from  string like "rgb(255, 255, 255)"

    token = tokenizer.next_token();

    if (!token.is_bracket()) {
        return Token("Expected Bracket");
    }

    token = tokenizer.next_token();

    if (!token.is_number() || token.get_number() > 255) {
        return Token("Incorrect Number");
    }

    short red = token.get_number();

    token = tokenizer.next_token();

    if (!(token.get_unknown() == ",")) {
        return Token("Expected ','");
    }

    token = tokenizer.next_token();

    if (!token.is_number() || token.get_number() > 255) {
        return Token("Incorrect Number");
    }

    short green = token.get_number();

    token = tokenizer.next_token();

    if (!(token.get_unknown() == ",")) {
        return Token("Expected ','");
    }

    token = tokenizer.next_token();

    if (!token.is_number() || token.get_number() > 255) {
        return Token("Incorrect Number");
    }

    short blue = token.get_number();

    token = tokenizer.next_token();

    if (!token.is_bracket()) {
        return Token("Expected ')'");
    }

    return Token(libs__Colors::Color(red, green, blue));
}
