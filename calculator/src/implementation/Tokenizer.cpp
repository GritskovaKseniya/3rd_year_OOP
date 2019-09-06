#include <string>

#include "../header/ExpressionAnalyzerSt.h"

Tokenizer::Tokenizer(std::string expr) {
    this->expression = expr;
}

Token Tokenizer::next_token() {
    return Token();
}