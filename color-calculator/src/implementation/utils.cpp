#include "../header/utils.h"
#include "../header/ColorCalculator.h"

#include <string>

bool startsWith(std::string predicate, std::string string) {
    return string.rfind(predicate, 0) == 0;
}

bool appplyOperation(
    char operation,
    libs__Colors::Color &result,
    libs__Colors::Color first,
    libs__Colors::Color second
) {
    switch (operation) {
        case '+':
            result =  first + second;
            break;
        case '-':
            result =  first - second;
            break;
        default:
            return false;
    }
    
    return true;
}

ParseResult eval(std::string expression) {
    Tokenizer tokenizer(expression);
    Token t1 = tokenizer.nextToken();

    if (!t1.isColor()) {
        return ParseResult("Expected Color");
    }
    
    libs__Colors::Color result = t1.getColorValue();
    
    // В цикле обрабатываем последующие сложения и вычитания
    while(true) {
        Token op_token = tokenizer.nextToken();

        if (op_token.isEmpty()) {
            // Если вместо оператора +,- получаем пустой токен, то это признак
            // конца обрабатываемой строки. Выходим из цикла и формируем результат.
            break;
        }

        if (!op_token.isOperation()) {
            return ParseResult("Expected operator");
        }
         
        Token t2 = tokenizer.nextToken();

        if (!t2.isColor()) {
            return ParseResult("Expected Color");
        }
        
        // Применяем оператор + или - к разобранным числам.
        char op = op_token.getOperationValue();

        if (!appplyOperation(op, result, result, t2.getColorValue())) {
            return ParseResult(std::string("Unknown operator ") + op);
        }
    }

    return ParseResult(result);
}
