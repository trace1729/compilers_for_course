#include <iostream>
#include <set>
#include <vector>
#include "grammar.h"
using namespace std;

void elim_dir_rec(Grammar& grammar, char nt) {

    set<string> non_rec_set;
    set<string> rec_set;  // 集合记得清空 
    for (auto & rhs : grammar.generator[nt]) {
        if (rhs[0] == nt) {
            rec_set.insert(rhs);
        } else {
            non_rec_set.insert(rhs);
        }
    }

    if (rec_set.size() > 0)
    {
        cout << "we are going to eliminate left recursion" << endl;
        grammar.generator[nt].clear();
        char new_nt = grammar.gen_non_ter();
        // new_n.push_back(new_nt);            
        for (auto &nts : non_rec_set)
        {
            string t = nts + new_nt;
            cout  << "insert " << nt << " -> " << t << endl;
            grammar.generator[nt].insert(t);

        }
        for (auto &rs : rec_set)
        {
            string t = rs.substr(1, rs.length()) + new_nt;
            cout  << "insert " << new_nt << " -> " << t << endl;
            grammar.generator[new_nt].insert(t);
        }
        grammar.generator[new_nt].insert(VAREPSILON);
        grammar.use_non_ter(new_nt);
        grammar.non_terminal.insert(new_nt); // a little dangerous
    }
}

void elim_dir_rec(Grammar& grammar)  
{   
    for (auto & nt : grammar.non_terminal) {
        elim_dir_rec(grammar, nt);
    }
}


void elim_in_rec(Grammar& grammar) {
    vector<char> nts = {'0'};
    for (auto & nt : grammar.non_terminal) {
        nts.push_back(nt);
    }
    int n = nts.size() - 1; // 因为多填充了一个 '0'
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            // if exists pattern A_i -> A_j..
            // do substitution;
        }
    }
}


int main()
{
    Grammar grammar;
    grammar.read_generator_list("./grammar1.txt");
    grammar.print_grammar();
    elim_dir_rec(grammar);
    grammar.print_grammar();
}
