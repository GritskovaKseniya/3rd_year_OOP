#pragma once

#include <string>

// using namespace std;

/// Результат разбора выражения - число либо текст ошибки
class ParseResult
{
    public:
        /// Конструирует корректный результат (число)
        ParseResult(double result);
        
        /// Конструирует ошибочный результат
        ParseResult(std::string error);
        
        /// Возвращает значение, показывающее, есть ли ошибка
        bool is_error();

        /// Возвращает число
        double get_result();
        
        /// Возвращает текст ошибки
        std::string get_error();
    private:
    
        double result;

        std::string error;
};

/// Типы токенов - перечисление, где каждому имени компилятором автоматически сопоставляется целое число.
enum TokenType
{
    EMPTY,
    NUMBER,
    OPER,
    BRACKET,
    UNKNOWN // Не пойми что - ошибка разбора
};

/// Токен (лексема, слово) - число, строка, пусто либо не пойми что.
class Token
{
    public:

        Token();
        
        Token(double number);

        Token(char operation);

        Token(std::string unknown);

        bool is_number();

        bool is_empty();

        bool is_oper();

        bool is_bracket();

        double get_number();

        char get_oper();

        char get_bracket();

        std::string debug();
    
    private:

        TokenType type;

        double number_value;

        char operation_value;

        char bracket_value;

        std::string unknown_value; 

};

/// Разбивает строку на токены
class Tokenizer
{
    public:
        /// Конструирует новый объект - при этом запоминается строка для разбора
        Tokenizer(std::string expr);
        
        /// Возвращает следующий токен из запомненной строки.
        /// Если строка кончилась, возвращает пустой токен token.is_empty()=true
        /// Если в строке ерунда - возвращает токен с type=UNKNOWN
        Token next_token();

        bool push_back();

    private:

        std::string expression;

        Token last;

        int position;

        bool has_push_back;
};


/// Применяет оператор к аргументам num1 и num2 и записывает результат в result
/// Возвращает true, если оператор известен, иначе false
bool apply_op(char op, double num1, double num2, double* result);


/// Разбирает арифметическое выражение и считает результат
ParseResult eval(std::string expr);
