#include "../header/ColorCalculator.h"

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
        return Token(token.get_oper());
    }

    if (token.is_number() || token.is_bracket()) {
        return Token("UNKNOWN");
    }

    if (token.get_unknown() != "rgb") {
        // TODO: Construct Color from string
    }

    // TODO: Construct color Token from  string like "rgb(255, 255, 255)"
}
