#include "iostream"
#include <stdlib.h>
#include <string.h>
#include <unit_test.h>

#include "lex.h"

extern Symbol symbol[N];
extern int s_idx;

void print_symbol_table () {
    for (int i = 0; i < s_idx; i++) {
        switch (symbol[i].s)
        {
        case RESERVED:
            printf("<%s, ->\n", symbol[i].content.c_str());
            break;
        
        case IDENTIFIER:
            printf("<0, %s>\n", symbol[i].content.c_str());
            break;
        
        case DELIMINATOR:
            printf("<%s, ->\n", symbol[i].content.c_str());
            break;

        case OPERATOR:
            printf("<%s, ->\n", symbol[i].content.c_str());
            break;

        case DEC:
            printf("<1, %s>\n", symbol[i].content.c_str());
            break;
        case OCT:
            printf("<2, %s>\n", symbol[i].content.c_str());
            break;

        case HEX:
            printf("<3, %s>\n", symbol[i].content.c_str());
            break;
        
        default:
            break;
        }
    }
}

int main(int argc, char* argv[]) {

    printf("Testing begins \n");
    char test_phrase[100] = "if data+92>0x3f then; \
        \n\t data=data+01; \
        \nelse   \
        \n\tdata=data-01;";
        
    int a = 2;
    parse(test_phrase);
    print_symbol_table();

}