#include <string>

using namespace std;

/// Результат разбора выражения - число либо текст ошибки
class ParseResult
{
public:
    /// Конструирует корректный результат (число)
    ParseResult(double result);
    
    /// Конструирует ошибочный результат
    ParseResult(string error);
    
    /// Возвращает значение, показывающее, есть ли ошибка
    bool is_error();

    /// Возвращает число
    double get_result();
    
    /// Возвращает текст ошибки
    string get_error();
};

/// Типы токенов - перечисление, где каждому имени компилятором автоматически сопоставляется целое число.
enum TokenType
{
    EMPTY,
    NUMBER,
    OPER,
    UNKNOWN // Не пойми что - ошибка разбора
};

/// Токен (лексема, слово) - число, строка, пусто либо не пойми что.
class Token
{
    TokenType type;
public:
    // TODO

    bool is_number();

    bool is_empty();

    bool is_oper();

    double get_number();

    char get_oper();

    string debug();
};

/// Разбивает строку на токены
class Tokenizer
{
    public:
        /// Конструирует новый объект - при этом запоминается строка для разбора
        Tokenizer(string expr);
        
        /// Возвращает следующий токен из запомненной строки.
        /// Если строка кончилась, возвращает пустой токен token.is_empty()=true
        /// Если в строке ерунда - возвращает токен с type=UNKNOWN
        Token next_token();

    private:
        string expression;
};


/// Применяет оператор к аргументам num1 и num2 и записывает результат в result
/// Возвращает true, если оператор известен, иначе false
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


/// Разбирает арифметическое выражение и считает результат
ParseResult eval(string expr)
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
    Token t1 = tok.next_token();
    if (!t1.is_number())
    {
        return ParseResult("Expected number");
    }
    
    double result = t1.get_number();
    
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
        
        Token num_token = tok.next_token();
        if (!num_token.is_number())
        {
            return ParseResult("Expected number");
        }
        
        // Применяем оператор + или - к разобранным числам.
        char op = op_token.get_oper();                
        if (!apply_op(op, result, num_token.get_number(), &result))
        {
            return ParseResult(string("Unknown operator ") + op);
        }
    }
    
    return ParseResult(result);
}

