#include <string>

#include "../header/ExpressionAnalyzerSt.h"

ParseResult get_number(Tokenizer* tokenizer);

ParseResult read_term(Tokenizer* tokenizer);

ParseResult read_number_or_brackets(Tokenizer* tokenizer);

ParseResult eval(std::string expr);

ParseResult eval(Tokenizer* tokenizer);

ParseResult eval(std::string expr)
{
    /*
     * Грамматика
     * 
     * Expression = Term [op Term]*
     * op = '+' | '-'
     * Term = NumberOR ['*' | '/' NumberOR]
     * NumberOR = Number | '('Expression')'
     * Number = ['+' | '-']Digit+[.Digit+]
     * Digit = '0' | '1' | ... | '8' | '9'
     * 
     * (где [] - необязательная часть выражения
     * something* - выражение something может повторяться 0 и более раз
     * something+ - выражение something должно быть - по крайней мере 1 раз. Но можно и много раз подряд.
     * )
    */
    
    // Токенайзер считывает строку "по словам (лексемам)"
    Tokenizer tok = Tokenizer(expr);
    ParseResult result = eval(&tok);
    tok.push_back();

    return tok.next_token().is_empty() ? result : ParseResult("Error");
}

ParseResult eval(Tokenizer* tokenizer) {
    ParseResult t1 = read_term(tokenizer);

    if (t1.is_error())
    {
        return t1;
    }
    
    double result = t1.get_result();
    
    // В цикле обрабатываем последующие сложения и вычитания
    while(true)
    {
        Token op_token = tokenizer->next_token();

        if (
            op_token.is_empty()    
            || (op_token.is_bracket() && op_token.get_bracket() == ')')
        )
        {
            // Если вместо оператора +,- получаем пустой токен, то это признак
            // конца обрабатываемой строки. Выходим из цикла и формируем результат.
            break;
        }

        if (!op_token.is_oper())
        {
            return ParseResult("Expected operator");
        }
         
        ParseResult term = read_term(tokenizer);

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

    if (token.is_number()) {
        return ParseResult(token.get_number());
    }
    
    if (!token.is_oper()) {
        return ParseResult("Expected number");
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
    ParseResult num = read_number_or_brackets(tokenizer);

    if (num.is_error()) {
        return num;
    }

    double result = num.get_result();

    Token operation_token = tokenizer -> next_token();

    if (
        operation_token.is_empty()
        || (operation_token.is_bracket() && operation_token.get_bracket() == ')')
    ) {
        return ParseResult(result);
    }
    
    if (!operation_token.is_oper()) {
        return ParseResult("Expected opeation");
    }

    char oper = operation_token.get_oper();;

    while (oper == '*' || oper == '/')
    {
        num = read_number_or_brackets(tokenizer);
        
        if (num.is_error()) {
            return num;
        }

        apply_op(oper, result, num.get_result(), &result);

        operation_token = tokenizer -> next_token();

        if (operation_token.is_empty()) {
            tokenizer->push_back();
            return ParseResult(result);
        }        

        if (!operation_token.is_oper()) {
            return ParseResult("Expected operation");
        }

        oper = operation_token.get_oper();
    }

    tokenizer->push_back();
    return ParseResult(result);
    
}

ParseResult read_number_or_brackets(Tokenizer* tokenizer) {
    Token token = tokenizer->next_token();

    if (token.is_bracket() && token.get_bracket() == '(') {
        ParseResult result = eval(tokenizer);
        return result;
    }

    tokenizer->push_back();
    return get_number(tokenizer);
        
}
