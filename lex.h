#ifndef LEX_H
#define LEX_H

#include <string>
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

typedef struct {
    enum SYMBOL s;
    string content;
} Symbol;

const int N = 1000;


char* substr(char* s, int left, int right);
void parse(char* str);


#endif