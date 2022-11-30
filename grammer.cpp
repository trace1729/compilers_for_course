#include <iostream>
#include <fstream>
#include <grammer.h>
using std::cin; using std::cout;
using std::endl;

Grammer::Grammer() {
    num = 0;
    start = "";
}

Grammer::~Grammer() {
    num = 0;
    start = "";
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
void Grammer::read_generator_list(string filename){
    string s;
    std::ifstream file("./grammer.txt");
    while(std::getline(file, s)) {

        if (file.fail() || file.eof()) {
            break;
        }
        string s1 = s.substr(0, s.find('-'));
        string s2 = s.substr(s.find('>') + 1, s.length() - s.find('>') - 2);
        // std::cout << s2 << std::endl;
        this->non_terminal.insert(s1[0]);
        generator[s1].insert(s2);
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

void Grammer::print_grammer() {
    print_table(generator);
}

void Grammer::print_non_termial() {
    cout << "文法G的非终结符：" << endl;
    print_set<char>(non_terminal);
}
void Grammer::print_termial() {
    cout << "文法G的终结符" << endl;
    print_set<char>(terminal);
}


//void Grammer::print_char_set(const set<char>& ss) {
    //int size = ss.size(), cnt = 0;
    //for (auto it = ss.begin(); it != ss.end(); ++it) {
        //cnt++;
        //if (cnt < size)
            //cout << *it << "|";
        //else
            //cout << *it ;
    //}
    //cout << ";" << endl;
//}
//


void Grammer::print_table (const map<string, set<string>>& m) {
    for (const auto& [non_terminal, set] : m) {
        cout << non_terminal << "->";
        print_set(set);
    }
}

