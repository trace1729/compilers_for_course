#include "iostream"
#include <stdlib.h>
#include <string.h>
#include <unit_test.h>

#include "lex.h"


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
        
        default:
            break;
        }
    }
}

int main(int argc, char* argv[]) {

    printf("Testing begins \n");
    string test1 = "if data+92>0x3f then; \
        \n\t data=data+01; \
        \nelse   \
        \n\tdata=data-01\n1+2;";
    string test2 = "1**2";
    SymbolTable symbols = parse(test2);
    print_symbol_table(symbols);
}
