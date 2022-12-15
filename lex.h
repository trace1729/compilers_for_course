#ifndef LEX_H
#define LEX_H

#include <string>
#include <vector>
using namespace std;

enum SYMBOL {
    RESERVED,
    IF,
    THEN,
    ELSE,
    WHILE,
    DO,
    OPERATOR,  // 运算符号 + - * / > < 
    DELIMINATOR, // 界符  { ( ; , 
    IDENTIFIER, // 用户自定义标识符
    OCT = 80,
    DEC = 100,
    HEX = 160,

};


const int N = 1000;
typedef vector<pair<SYMBOL, string> > SymbolTable;

SymbolTable parse(string str);

string convert(string input) {
    char res[100];
    auto symbol = parse(input);

    int idx = 0;

    for (int i = 0; i < symbol.size(); i++) {
        if (symbol[i].second[0] == ';') continue;
        switch (symbol[i].first)
        {
        
        case DELIMINATOR:
        case OPERATOR:
            res[idx++] = symbol[i].second[0];
            break;

        case IDENTIFIER:
        case DEC:
            res[idx++] = 'i';
            break;
        
        default:
            break;
        }
    }
    res[idx] = '\0';
    
    string toTest(res);
    return toTest;
}

#endif
