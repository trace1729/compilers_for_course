#include <cstdio>
#include <string>
#include <vector>
#include "lex.h"
using std::vector;

bool isNonsense(char ch) {

    if (ch == ' ' || ch == '\t' || ch == '\n')
         return true;
    return false;
}

bool isDelimiter(char ch) {
    
    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '+' || ch == '-'  || ch == '*'  || ch == '/'
         || ch == '<'  || ch == '>' || ch == '('  || ch == ')' || ch == ';' || ch == '=' || ch == '\0' || ch == '?')
         return true;

    return false;
}

bool isOperator(char ch) {
    return  (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}



bool isReserveWord(string str) {

    return  (str == "while") ||  (str == "then") ||
                (str == "else")  || (str == "do")   || (str == "if");
}

bool isNum(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isOct(char ch) {
    return ch >= '0' && ch <= '7';
}

bool isAlphaBeta(char ch) {
    return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ;
}

bool isHex(char ch) {
    return ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'F'|| ch >= 'a' && ch <= 'f' ;
}


void update_symbol_table(SymbolTable& symbols, enum SYMBOL s, string c) {
    symbols.push_back({s, c});
}

// Parsing the input STRING.
SymbolTable scan(string str)
{
    SymbolTable symbols;
    int left = 0, right = 0;
    int len = str.length();
 
    while (right <= len && left <= right) {
        if (!isDelimiter(str[right]) or str[right] == '_') {
            right++;
        } else if (isDelimiter(str[right]) && left == right) { //假设一开始就是 间隔符
            if (isOperator( str[right] )) {
                // + 1 是用来与该符号临近的符号作比较
                // if (right + 1 <= len && str[right] == str[right + 1] || str[right + 1] == '=') {
                //     //printf("%c%c is a dul Operator", str[right], str[right+1]);
                //     right++;
                // }
                string tmp(1, str[left]);
                update_symbol_table(symbols, OPERATOR, tmp);
                //printf("%c is an Operator\n", str[right]);
            } else if(isNonsense( str[right] )){
                // do nothing
            } else {
                if (str[right] != '\0') {
                    string tmp(1, str[right]);
                    update_symbol_table( symbols, DELIMINATOR, tmp);
                }
                //printf("%c is diliminater\n", str[right]);
            }
            right++;  // left 和 right 并行增加
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right // 两种情况， 一种是right 指针指向 界符
            ||  (right == len && right != left)) { // 另一种是 right 指针指向 字符串 末尾

            // char* subString = substr(str, left, right - 1); // -1 是因为right 指针指向的位置在 界符 上 
            string subString = str.substr(left, right - left);
            int len = subString.length();
            /* 判断是不是关键字 */
            if (isReserveWord(subString)) {
                update_symbol_table(symbols, RESERVED, subString);
                //printf("%s is reserved word\n", subString);

                /* 判断是否有错误数字 */
            }
               /* 判断是不是 十进制数字 */
            else if (len == 1 && isNum(subString[0]) ||
                        (len > 1 && subString[0] != '0' \
                          && subString[0] >= '1' && subString[0] <= '9' \
                        )) {
                        int flag = 1;
                        for (char t: subString) {
                            if (!isNum(t)) {
                                update_symbol_table(symbols, ERRO, subString);
                                flag = 0;
                            }
                        }
                        if (flag)
                            update_symbol_table(symbols, DEC, (subString));
                //printf("%s is decimal\n", subString); 

            /* 判断是不是 十六进制数字 */
            } else if (len > 2  && subString[0] == '0' && ( subString[1] == 'x' || subString[1] == 'X' ) ) {
                int flag = 1;
                for (char t: subString.substr(2)) {
                    if (!isHex(t)) {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    update_symbol_table(symbols, HEX, (subString));
                else
                    update_symbol_table(symbols, ERRO, subString);
                //printf("%s is hex\n", subString);
            
            } else if (len > 1 && subString[0] == '0') {
                int flag = 1;
                if (subString[1] == '0') flag = 0;
                for (char t: subString.substr(1)) {
                    if (!isOct(t)) {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    update_symbol_table(symbols, OCT, (subString));
                else
                    update_symbol_table(symbols, ERRO, subString);
                //printf("%s is oct\n", subString);

            } else {
                int flag = 1;
                if (isNum(subString[0])) flag = 0;
                // 可以优化
                for (char t: subString.substr(1)) {
                    if (isDelimiter(t)) {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    update_symbol_table(symbols, IDENTIFIER, (subString));
                else
                    update_symbol_table(symbols, ERRO, (subString));
            }
            left = right;
        }
    }
    return symbols;
}


void print_symbol_table (SymbolTable symbol) {
    for (int i = 0; i < symbol.size(); i++) {
        switch (symbol[i].first)
        {
        case RESERVED:
            printf("<%s, ->\n", symbol[i].second.c_str());
            break;
        
        case IDENTIFIER:
            printf("<0, %s>\n", symbol[i].second.c_str());
            break;
        
        case DELIMINATOR:
            printf("<%s, ->\n", symbol[i].second.c_str());
            break;

        case OPERATOR:
            printf("<%s, ->\n", symbol[i].second.c_str());
            break;

        case DEC:
            printf("<1, %s>\n", symbol[i].second.c_str());
            break;
        case OCT:
            printf("<2, %s>\n", symbol[i].second.c_str());
            break;

        case HEX:
            printf("<3, %s>\n", symbol[i].second.c_str());
            break;
            case ERRO:
                printf("<ERROR, %s>\n", symbol[i].second.c_str());
                break;
        default:
            break;
        }
    }
    
}


string convert(string input) {
    char res[100];
    auto symbol = scan(input);

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
