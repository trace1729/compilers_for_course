#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


int main(int argc, char* argv[]) {

    printf("Testing begins \n");
    char test_phrase[20] = "if data > (a)";
    parse(test_phrase);

}