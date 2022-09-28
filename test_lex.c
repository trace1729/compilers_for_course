#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


int main(int argc, char* argv[]) {

    printf("Testing begins \n");
    char test_phrase[100] = "if data+92>0x3f then";
    parse(test_phrase);

}