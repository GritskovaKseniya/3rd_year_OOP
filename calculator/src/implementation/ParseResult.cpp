#include <string>

#include "../header/ExpressionAnalyzerSt.h"

ParseResult::ParseResult(double result) {
    this->result = result;
    this->error = "NULL";
}

ParseResult::ParseResult(std::string error) {
    this->error = error;
}

bool ParseResult::is_error() {
    return this->error.compare("NULL") != 0;
}

double ParseResult::get_result() {
    return this->result;
}

std::string ParseResult::get_error() {
    return this->error;
}