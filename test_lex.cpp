#include "iostream"
#include <stdlib.h>
#include <string.h>
#include "lex.h"


int main(int argc, char* argv[]) {

    printf("Testing begins \n");
    string test1 = "if data+92>0x3f then; \
        \n\t data=data+01; \
        \nelse   \
        \n\tdata=data-01\n1+2;";
    string test2 = "1**2";
    SymbolTable symbols = parse(test1);
    print_symbol_table(symbols);
}
