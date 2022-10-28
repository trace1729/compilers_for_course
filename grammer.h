#ifndef GRAMMER_H
#define GRAMMER_H 

#include <iostream>
#include <fstream>
#include <set>
#include <map>
using std::set;
using std::map;
using std::string;

class Grammer {
public:
    Grammer();
    ~Grammer();
    void read_generator_list(string filename);
    void print_grammer();

private:
    void print_set(const set<string>& ss);
    void print_table (const map<string, set<string>>& m);
    int num;
    set<string> non_terminal;
    set<string> terminal;
    string start;
    map<string, set<string>> generator; 

};

#endif
