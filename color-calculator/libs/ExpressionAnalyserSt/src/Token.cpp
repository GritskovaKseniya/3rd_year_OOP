#include <string>

#include "../ExpressionAnalyzerSt.h"

using namespace libs__ExpressionAnalyserSt;

Token::Token() {
    this->type = EMPTY;
}

Token::Token(double value) {
    this->type = NUMBER;
    this->number_value = value;
}

Token::Token(char operation_or_bracket) {
    if (
        operation_or_bracket == '('
        || operation_or_bracket == ')'
    ) {
        this->type = BRACKET;
        this->bracket_value = operation_or_bracket;
    } else {
        this->type = OPER;
        this-> operation_value = operation_or_bracket;
    }
    
}

Token::Token(std::string unkknown) {
    this->type = UNKNOWN;
    this->unknown_value = unkknown;
}

bool Token::is_empty() {
    return this->type == EMPTY;
}

bool Token::is_number() {
    return this->type == NUMBER;
}

bool Token::is_oper() {
    return this->type == OPER;
}

bool Token::is_bracket() {
    return this->type == BRACKET;
}

double Token::get_number() {
    return this->number_value;
}

char Token::get_oper() {
    return this->operation_value;
}

char Token::get_bracket() {
    return this->bracket_value;
}

std::string Token::get_unknown() {
    return this->unknown_value;
}

std::string Token::debug() {
    std::string type_str = "";
    std::string value_str = "";

    switch (this->type)
    {
    case NUMBER:
        type_str = "NUMBER";
        value_str = std::to_string(number_value);
        break;

    case OPER:
        type_str = "OPERATION";
        value_str.push_back(operation_value);
        break;

    case EMPTY:
        type_str = "EMPTY";
        break;

    case BRACKET:
        type_str = "BRACKET";
        value_str.push_back(bracket_value);
        break;
    
    default:
        type_str = "UNKNOWN";
        value_str = unknown_value;
        break;
    }

    return "Token type: " + type_str + ". Value: " + value_str;
}
