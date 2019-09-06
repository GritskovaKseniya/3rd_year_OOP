#include <iostream>
#include <string>

#include "header/ExpressionAnalyzerSt.h"

// using namespace std;

// Отладка токенайзера
void TestTokenizer(std::string expr);

int main()
{
    std::cout << "Input expression: ";
    std::string expr;
    getline(std::cin, expr);
    
    //TestTokenizer(expr);
    ParseResult result = eval(expr);
    
    if (result.is_error())
    {
        std::cout << "ERROR: " << result.get_error() << std::endl;
    }
    else
    {     
        std::cout << "Result is " << result.get_result() << std::endl;
    }
    
    return 0;
}

void TestTokenizer(std::string expr)
{
    Tokenizer test = Tokenizer(expr);
    bool exit = false;
    while(!exit)
    {
        Token t = test.next_token();
        std::cout << t.debug() << std::endl;
        
        exit = t.is_empty();
    }
}
