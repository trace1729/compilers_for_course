#include <iostream>
#include <grammer.h>

int main() 
{
    Grammer grammer;
    grammer.read_generator_list("grammer.txt");
    grammer.print_grammer();
    return 0;
}

