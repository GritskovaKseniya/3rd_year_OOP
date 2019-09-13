#include <string>

#include "../header/ExpressionAnalyzerSt.h"

ParseResult get_number(Tokenizer* tokenizer);

ParseResult read_term(Tokenizer* tokenizer);

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
    ParseResult t1 = read_term(&tok);
    if (t1.is_error())
    {
        return t1;
    }
    
    double result = t1.get_result();
    
    // В цикле обрабатываем последующие сложения и вычитания
    while(true)
    {
        Token op_token = tok.last_token();
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
         
        ParseResult term = read_term(&tok);
        if (term.is_error())
        {
            return term;
        }
        
        // Применяем оператор + или - к разобранным числам.
        char op = op_token.get_oper();                
        if (!apply_op(op, result, term.get_result(), &result))
        {
            return ParseResult(std::string("Unknown operator ") + op);
        }
    }
    
    return ParseResult(result);
}

bool apply_op(char op, double num1, double num2, double* result)
{
    switch (op)
    {
    case '+':
        *result = num1 + num2;
        break;
    case '-':
        *result = num1 - num2;
        break;
    case '*':
        *result = num1 * num2;
        break;
    case '/':
        *result = num1 / num2;
        break;
    default:
        return false;
        break;
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

    char oper = token.get_oper();

    if (oper != '+' && oper != '-') {
        return ParseResult("Expected '+' or '-'");
    }

    int multipl = oper == '+' ? 1 : -1;

    token = tokenizer -> next_token();

    if (!token.is_number()) {
        return ParseResult("Expected number");
    }

    return ParseResult(token.get_number() * multipl);
}

ParseResult read_term(Tokenizer* tokenizer) {
    ParseResult num = get_number(tokenizer);

    if (num.is_error()) {
        return num;
    }

    double result = num.get_result();

    Token operation_token = tokenizer -> next_token();

    if (operation_token.is_empty()) {
        return ParseResult(result);
    }
    
    if (!operation_token.is_oper()) {
        return ParseResult("Expected opeation");
    }

    char oper = operation_token.get_oper();;

    while (oper == '*' || oper == '/')
    {
        num = get_number(tokenizer);
        
        if (num.is_error()) {
            return num;
        }

        apply_op(oper, result, num.get_result(), &result);

        operation_token = tokenizer -> next_token();

        if (operation_token.is_empty()) {
            return ParseResult(result);
        }        

        if (!operation_token.is_oper()) {
            return ParseResult("Expected operation");
        }

        oper = operation_token.get_oper();
    }

    return ParseResult(result);
    
}
