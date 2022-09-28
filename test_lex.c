#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"


int main(int argc, char* argv[]) {

    printf("Let's do some tests\n");
    char test_substr[20] = "helloworld";
    char* res = substr(test_substr, 0, 5);
    printf("%s", res);        

}