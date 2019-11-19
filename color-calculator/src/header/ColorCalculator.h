#pragma once

#include "../../libs/ExpressionAnalyserSt/ExpressionAnalyzerSt.h"
#include "../../libs/Colors/colors.h"

#include <string>

class ParseResult {
    public:
        
        ParseResult(libs__Colors::Color result);

        ParseResult(std::string error);

        bool isError();

        libs__Colors::Color getResult();

        std::string getError();

    private:

        libs__Colors::Color result;
        std::string error;
};

enum TokenType {
    COLOR,
    OPERATION,
    EMPTY,
    UNKNOWN
};

class Token {
    public:

        Token();

        Token(libs__Colors::Color color);

        Token(char operation);

        Token(std::string unknown);

        bool isEmpty();

        bool isColor();

        bool isOperation();

        libs__Colors::Color getColorValue();

        char getOperationValue();

        std::string getUnknownValue();

    private:

        TokenType type;

        libs__Colors::Color colorValue;

        char operationValue;

        std::string unknownValue;

};

class Tokenizer {
    public:

        Tokenizer(std::string eval);

        Token nextToken();

    private:
        
        libs__ExpressionAnalyserSt::Tokenizer tokenizer = libs__ExpressionAnalyserSt::Tokenizer("");
};

bool applyOp(char op, libs__Colors::Color first, libs__Colors::Color second, libs__Colors::Color& result);

ParseResult eval(std::string expression);
