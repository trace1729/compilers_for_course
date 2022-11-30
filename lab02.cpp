#include <iostream>
#include <grammer.h>

void add() {

}

int main() 
{
    Grammer grammer;
    grammer.read_generator_list("grammer.txt");
    grammer.print_grammer();
    grammer.print_non_termial();
    grammer.print_termial();
    return 0;
}

