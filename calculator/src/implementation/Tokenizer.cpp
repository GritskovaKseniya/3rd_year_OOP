#include <string>

#include "../header/ExpressionAnalyzerSt.h"

Tokenizer::Tokenizer(std::string expr) {
    this->expression = expr;
    this->position = 0;
}

Token Tokenizer::next_token() {

    if (position == expression.size()) {
        return Token();
    }
    
    // Init token
    bool has_fractional_part = false;
    char symbol = ' ';

    // Skips all lead spaces
    while (symbol == ' ') {
        symbol = expression.at(position);
        position++;
    }

    int start_position = position-1;

    if (symbol == '+' || symbol == '-') {
        return Token(symbol);
    }

    TokenType token_type = (symbol >= '0' && symbol <= '9') ? NUMBER : UNKNOWN;


    // Processing expretion until token or expression ends
    while (position != expression.size()) {
        // Symbol may be part of NUMBER or UNKNOWN
        // Or it may be OPER
        symbol = expression.at(position);

        // If symbol is OPER then EoC
        // OPER is a single symbol. It means that previous symbols was another Token
        if (symbol == '+' || symbol == '-') {
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
        return Token(::atof(expression.substr(start_position, position - start_position).c_str()));
        break;

    case UNKNOWN:
        return Token(expression.substr(start_position, position - start_position));
        break;
    }
    
}