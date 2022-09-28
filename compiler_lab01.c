#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdbool.h"


bool isDelimiter(char ch) {
    
    if (ch == ' ' || ch == '+' || ch == '-'  || ch == '*'  || ch == '/'
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
    if (res == NULL) return NULL;

    return res;
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
            if (isOperator(str[right])) {
                // + 1 是用来与该符号临近的符号作比较
                if (right + 1 <= len && str[right] == str[right + 1] || str[right + 1] == '=') {
                    printf("%c%c is a dul Operator", str[right], str[right+1]);
                    right++;
                }
                printf("%c is an Operator", str[right]);
            } 
            right++;  // left 和 right 并行增加
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
            ||  (right == len && right != left)) {

            char* substr = substring(str, left, right - 1);

        }
    }
    return;
}

int main(int argc, char* argv[]) 
{
    char input[100] = "if data+92>0x3f then";
    parse(input);
    return 0;
}