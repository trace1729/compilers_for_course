#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"
#include "lex.h"



bool isNonsense(char ch) {

    if (ch == ' ' || ch == '\t' || ch == '\n')
         return (true);
    return false;
}

bool isDelimiter(char ch) {
    
    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '+' || ch == '-'  || ch == '*'  || ch == '/'
         || ch == '<'  || ch == '>' || ch == '('  || ch == ')' || ch == ';' ) 
         return (true);

    return false;
}

bool isOperator(char ch) {
    return  (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


char* substr(char* s, int left, int right) {

    char* res = (char* )malloc((right - left + 2) * sizeof(char));
    // 这里的2是因为还需要存`\0` a
    if (res == NULL) exit(1);
    char* l = s + left, *r = s + right;
    int i = 0;
    for (i = 0; l <= r; i++, l++) {
        res[i] = *l;
    }
    res[i] = '\0';
    return res;
}

bool isReserveWord(char* str) {

    return  !strcmp(str, "while") ||  !strcmp(str, "then") ||
                !strcmp(str, "else")  || !strcmp(str, "do")   || !strcmp(str, "if");
}

// Parsing the input STRING.
void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false) {
            right++;

        } else if (isDelimiter(str[right]) == true && left == right) { //假设一开始就是 间隔符
            if (isOperator( str[right] )) {
                // + 1 是用来与该符号临近的符号作比较
                // if (right + 1 <= len && str[right] == str[right + 1] || str[right + 1] == '=') {
                //     printf("%c%c is a dul Operator", str[right], str[right+1]);
                //     right++;
                // }
                printf("%c is an Operator\n", str[right]);
            } else if(isNonsense( str[right] )){
                // do nothing
            } else {
                printf("%c is diliminater\n", str[right]);
            }

            right++;  // left 和 right 并行增加
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right // 两种情况， 一种是right 指针指向 界符
            ||  (right == len && right != left)) { // 另一种是 right 指针指向 字符串 末尾

            char* subString = substr(str, left, right - 1); // -1 是因为right 指针指向的位置在 界符 上 
            int len = right - 1 - left;
            /* 判断是不是关键字 */
            if (isReserveWord(subString)) {
                printf("%s is reserved word\n", subString);

            /* 判断是不是 十进制数字 */
            } else if (len == 1 && subString[0] == '0' || 
                        len > 1 && subString[0] != '0') {
                printf("%s is decimal\n", subString); 

            /* 判断是不是 十六进制数字 */
            } else if (len > 2  && subString[0] == '0' && subString[1] == 'x') {
                printf("%s is hex\n", subString); 
            
            } else if (len > 1 && subString[0] == '0') {

                printf("%s is oct\n", subString); 

            } else {
                printf("%s is identifier\n", subString);
            }
            left = right;
        }
    }
    return;
}
