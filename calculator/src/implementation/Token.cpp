#include <string>

#include "../header/ExpressionAnalyzerSt.h"

Token::Token() {
    this->type = EMPTY;
}

Token::Token(double value) {
    this->type = NUMBER;
    this->number_value = value;
}

Token::Token(char operation) {
    this->type = OPER;
    this-> operation_value = operation;
}

Token::Token(std::string unkknown) {
    this->type = UNKNOWN;
    this->unknown_value = unkknown;
}

bool Token::is_empty() {
    return this->type == EMPTY;
}

bool Token::is_number() {
    return this->type = NUMBER;
}

bool Token::is_oper() {
    return this->type = OPER;
}

double Token::get_number() {
    return this->number_value;
}

char Token::get_oper() {
    return this->operation_value;
}

std::string Token::debug() {
    return this->unknown_value;
}
