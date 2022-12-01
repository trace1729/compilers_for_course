#include <iostream>
#include "grammar.h"

int main() 
{
    Grammar grammar;
    grammar.read_generator_list("grammar.txt");
    grammar.print_grammar();
    grammar.print_non_termial();
    grammar.print_termial();
    return 0;
}

