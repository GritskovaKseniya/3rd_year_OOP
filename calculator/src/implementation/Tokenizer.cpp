#include <string>

#include "../header/ExpressionAnalyzerSt.h"

Tokenizer::Tokenizer(std::string expr) {
    this->expression = expr;
    this->position = 0;
    this->has_push_back = false;
}

Token Tokenizer::next_token() {

    if (this->has_push_back) {
        this->has_push_back = false;
        return last;
    }

    if (position >= expression.size()) {
        last = Token();
        return last;
    }
    
    // Init token
    bool has_fractional_part = false;
    char symbol = expression.at(position);

    // Skips all lead spaces
    while (symbol == ' ') {
        position++;
        symbol = expression.at(position);
    }

    int start_position = position;

    if (
        symbol == '+'
        || symbol == '-'
        || symbol == '*'
        || symbol == '/'
        || symbol == '('
        || symbol == ')'
    ) {
        position++;
        last = Token(symbol);
        return last;
    }

    TokenType token_type = (symbol >= '0' && symbol <= '9') ? NUMBER : UNKNOWN;


    // Processing expretion until token or expression ends
    while (position != expression.size()) {
        // Symbol may be part of NUMBER or UNKNOWN
        // Or it may be OPER
        symbol = expression.at(position);

        // If symbol is OPER or BRACKET then EoC
        // OPER or BRACKET are a single symbol. It means that previous symbols was another Token
        if (
            symbol == '+'
            || symbol == '-'
            || symbol == '*'
            || symbol == '/'
            || symbol == '('
            || symbol == ')'
        ) {
            break;
        }

        // If previous symbols were valid NUMBER, but current symbol makes NUMBER invalid, then EoC
        if (
            (token_type == NUMBER)
            && (
                ((symbol < '0' || symbol > '9') && symbol != '.' )
                || (symbol == '.' && has_fractional_part)
            )
        ) {
            break;
        }

        // If previous symbols were UNKNOWN, but current symbol starts valid NUMBER, then EoC
        if (
            token_type == UNKNOWN
            && symbol >= '0'
            && symbol <= '9'
        ) {
            break;
        }

        // Here we sure that token still valid
        // If NUMBER and symbol is '.' then we mark that token has fracrional part
        if(
            token_type == NUMBER
            && symbol == '.'
        ) {
            has_fractional_part = true;
        }

        position++;
    }

    // Returns value depending on token_type
    // Here may be NUMBER of UNKNOWN
    switch (token_type)
    {
    case NUMBER:
        last = Token(::atof(expression.substr(start_position, position - start_position + 1).c_str()));
        return last;
        break;

    case UNKNOWN:
        last = Token(expression.substr(start_position, position - start_position));
        return last;
        break;
    }
    
}

bool Tokenizer::push_back() {
    if (this->has_push_back) {
        return false;
    }

    this->has_push_back = true;
    return true;
}
