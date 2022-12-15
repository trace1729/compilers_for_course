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


#endif
