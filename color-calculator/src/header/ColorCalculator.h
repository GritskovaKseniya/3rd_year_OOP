#pragma once

#include "../../libs/ExpressionAnalyserSt/ExpressionAnalyzerSt.h"
#include "../../libs/Colors/colors.h"

#include <string>

enum ColorTokenType {
    COLOR,
    OPERATION,
    EMPTY,
    UNKNOWN
};

class ColorToken {
    public:

        ColorToken();

        ColorToken(Color color);

        ColorToken(char operation);

        ColorToken(std::string unknown);

        bool isEmpty();

        bool isColor();

        bool isOperation();

        bool isUnknown();

        Color getColorValue();

        char getOperationValue();

        std::string getUnknownValue();

    private:

        ColorTokenType type;

        Color colorValue;

        char operationValue;

        std::string unknownValue;

};

class ColorTokenizer {
    public:

        ColorTokenizer(std::string eval);

        ColorToken nextToken();

    private:
        
        Tokenizer tokenizer;
};

bool applyOp(char op, Color first, Color second, Color& result);

ParseResult colorEval(std::string expression);
