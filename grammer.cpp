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

 
void Grammer::read_generator_list(string filename){
    string s;
    std::ifstream file("./grammer.txt");
    while(std::getline(file, s)) {
        
        if (file.fail() || file.eof()) {
            break;
        }
        string s1 = s.substr(0, s.find('-'));
        string s2 = s.substr(s.find('>') + 1, s.length() - s.find('>') - 2);
        std::cout << s2 << std::endl;
        generator[s1].insert(s2);
   }
}

void Grammer::print_grammer() {
    print_table(generator);
}

void Grammer::print_set(const set<string>& ss) {
    int size = ss.size(), cnt = 0;
    for (auto it = ss.begin(); it != ss.end(); ++it) {
        cnt++;
        if (cnt < size)
            cout << *it << "|";
        else
            cout << *it ;
    }
    cout << ";" << endl;
}

void Grammer::print_table (const map<string, set<string>>& m) {
    for (const auto& [non_terminal, set] : m) {
        cout << non_terminal << "->";
        print_set(set);
    }
}

