#include <iostream>
#include <string>

#include "header/ColorCalculator.h"

// using namespace std;

// Отладка токенайзера
void TestTokenizer(std::string expr);

int main()
{
    std::cout << "Input expression: ";
    std::string expr;
    getline(std::cin, expr);
    
    TestTokenizer(expr);
    
    return 0;
}

void TestTokenizer(std::string expr)
{
    Tokenizer test = Tokenizer(expr);
    bool exit = false;
    while(!exit)
    {
        Token t = test.nextToken();
        std::cout << t.debug() << std::endl;
        
        exit = t.isEmpty();
    }
}
