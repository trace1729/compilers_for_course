#include <iostream>
#include <fstream>
#include "grammar.h"

Grammar::Grammar() { 
    this->alphabet = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        this->alphabet[i] = 0;
    }
    num = 0;
}

Grammar::~Grammar() {
    num = 0;
}


char Grammar::gen_non_ter() {
    for (int i = 0; i < SIZE; i++) {
        if (this->alphabet[i] == 0) {
            return (char)(i + 'A');
        }
    }
    return '\0';
}

void Grammar::use_non_ter(char nt) {
    this->alphabet[(int)(nt - 'A')] = 1;
}

/**
 *  LHS of a production must be non-terminal, 
 *  RHS of a production must contains terminal 
 *  So the way to find terminals is 
 *  1. store all the terminals (It is definate)
 *  2. for RHS of each production 
 *    iterate through each character
 *    if not in non-terminal set 
 *    put it in terminal set
 */



void Grammar::read_generator_list(string filename){
    string s;
    int cnt = 0;
    std::ifstream file(filename);
    while(std::getline(file, s)) {
        if (file.fail() || file.eof()) {
            break;
        }
        string s1 = s.substr(0, s.find('-'));
        string s2 = s.substr(s.find('>') + 1, s.length() - s.find('>') - 2);
        this->non_terminal.insert(s1[0]);
        if (cnt++ == 0) {
            this->start = s1[0];
        }
        this->use_non_ter(s1[0]);
        generator[s1[0]].insert(s2);
    }

    for (auto & [k, v]:generator) {
        for (auto & ss : v) {
            for (auto & cc : ss) {
                if (this->non_terminal.count(cc) == 0) {
                    this->terminal.insert(cc);
                }
            }
        }
    }
}

void Grammar::print_grammar() {
    print_table(generator);
}

void Grammar::print_non_termial() {
    cout << "文法G的非终结符：" << endl;
    print_set<char>(non_terminal);
}
void Grammar::print_termial() {
    cout << "文法G的终结符" << endl;
    print_set<char>(terminal);
}

void Grammar::print_table (const map<char, set<string>>& m) {
    for (const auto& [non_terminal, set] : m) {
        cout << non_terminal << "->";
        print_set(set);
        putchar('\n');
    }
}

