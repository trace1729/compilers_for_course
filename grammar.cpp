#include <iostream>
#include <fstream>
#include <vector>
#include "grammar.h"

using std::vector;
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
        char nt = mystrip(s.substr(0, s.find('-')))[0];
        
        string t = s.substr(s.find('>') + 1);
        auto prods = mysplit(t, '|');

        this->non_terminal.insert(nt);
        if (cnt++ == 0) {
            this->start = nt;
        }
        this->use_non_ter(nt);

        for (auto & prod : prods) {
            generator[nt].insert(prod);
        }
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
    cout << "读入的文法G：" << endl;
    print_table(generator);
}

void Grammar::print_non_termial() {
    cout << "文法G的非终结符：" << endl;
    print_set<char>(non_terminal);
    cout << endl;
}
void Grammar::print_termial() {
    cout << "文法G的终结符" << endl;
    print_set<char>(terminal);
    cout << endl;
}

void Grammar::print_table (const map<char, set<string>>& m) {
    for (const auto& [non_terminal, set] : m) {
        cout << non_terminal << "->";
        print_set(set);
        putchar('\n');
    }
}

string Grammar::mystrip(string src)
{
    int first_not_space = src.find_first_not_of(' ');
    
    string res = src;
    if (first_not_space != string::npos) {
        // 找到了空格
        res = src.substr(first_not_space);
    }
    int rfirst_not_space = res.find_last_not_of(' ');
    if (rfirst_not_space != string::npos) {
        // 找到了空格
        res = res.substr(0, rfirst_not_space + 1);
    }
    return res;
}

vector<string> Grammar::mysplit (string src, char toSplit) {
    vector<string> symbols;
    src = mystrip(src);
    int find_spilt_point = src.find(toSplit);

    while(find_spilt_point != string::npos) {
        string t = src.substr(0, find_spilt_point);
        t = mystrip(t);
        if (t.length() >= 1 && t != " ") { // 去除空格
            symbols.push_back(t);
        }
        src = src.substr(find_spilt_point + 1);
        find_spilt_point = src.find(toSplit);
    }

    if (mystrip(src).length() >= 1) {
        symbols.push_back(src.substr(0, src.find_last_of(';')));
    }

    return symbols;
}
