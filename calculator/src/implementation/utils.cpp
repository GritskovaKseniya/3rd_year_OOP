#include <string>

#include "../header/ExpressionAnalyzerSt.h"

ParseResult get_number(Tokenizer* tokenizer);

ParseResult eval(std::string expr)
{
    /*
     * Грамматика
     * 
     * Expression = Number [op Number]*
     * op = '+' | '-'
     * Number = Digit+[.Digit+]
     * Digit = '0' | '1' | ... | '8' | '9'
     * 
     * (где [] - необязательная часть выражения
     * something* - выражение something может повторяться 0 и более раз
     * something+ - выражение something должно быть - по крайней мере 1 раз. Но можно и много раз подряд.
     * )
    */
    
    // Токенайзер считывает строку "по словам (лексемам)"
    Tokenizer tok = Tokenizer(expr);    
    
    // Первый токен должен быть числом
    ParseResult t1 = get_number(&tok);
    if (t1.is_error())
    {
        return ParseResult("Expected number");
    }
    
    double result = t1.get_result();
    
    // В цикле обрабатываем последующие сложения и вычитания
    while(true)
    {
        Token op_token = tok.next_token();
        if (op_token.is_empty())
        {
            // Если вместо оператора +,- получаем пустой токен, то это признак
            // конца обрабатываемой строки. Выходим из цикла и формируем результат.
            break;
        }
        if (!op_token.is_oper())
        {
            return ParseResult("Expected operator");
        }
        
        ParseResult num_token = get_number(&tok);
        if (num_token.is_error())
        {
            return ParseResult("Expected number");
        }
        
        // Применяем оператор + или - к разобранным числам.
        char op = op_token.get_oper();                
        if (!apply_op(op, result, num_token.get_result(), &result))
        {
            return ParseResult(std::string("Unknown operator ") + op);
        }
    }
    
    return ParseResult(result);
}

bool apply_op(char op, double num1, double num2, double* result)
{
    if (op == '+')
    {
        *result = num1 + num2;
    }
    else if (op == '-')
    {
        *result = num1 - num2;
    }
    else
    {
        return false;
    }
    
    return true;
}

ParseResult get_number(Tokenizer* tokenizer) {
    Token token = tokenizer -> next_token();
    
    if (!(token.is_number() || token.is_oper())) {
        return ParseResult("Expected number");
    }

    if (token.is_number()) {
        return ParseResult(token.get_number());
    }

    int multipl = token.get_oper() == '+' ? 1 : -1;

    token = tokenizer -> next_token();

    if (!token.is_number()) {
        return ParseResult("Expected number");
    }

    return ParseResult(token.get_number() * multipl);
}
