#include <iostream>
#include <string>

//#include "ExpressionAnalyzer.h"
#include "ExpressionAnalyzerSt.h"

using namespace std;

// Отладка токенайзера
void TestTokenizer(string expr);


int main()
{
    cout << "Input expression: ";
    string expr;
    getline(cin, expr);
    
    //TestTokenizer(expr);
    ParseResult result = eval(expr);
    
    if (result.is_error())
    {
        cout << "ERROR: " << result.get_error() << endl;
    }
    else
    {     
        cout << "Result is " << result.get_result() << endl;
    }
    
    return 0;
}

void TestTokenizer(string expr)
{
    Tokenizer test = Tokenizer(expr);
    bool exit = false;
    while(!exit)
    {
        Token t = test.next_token();
        cout << t.debug() << endl;
        
        exit = t.is_empty();
    }
}
