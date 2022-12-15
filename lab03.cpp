#include <iostream>
#include <set>
#include <vector>
#include "grammar.h"
#include "elim_rec.h"
#include "trie.h"

using namespace std;

void elim_dir_rec(Grammar& grammar, char nt) {

    set<string> non_rec_set;
    set<string> rec_set;  // 集合记得清空 
    for (auto & rhs : grammar.generator[nt]) {
        if (rhs[0] == nt) {
            
        cout << "exists left Recursio " 
            << nt << "->" << rhs << " !" << endl;
            rec_set.insert(rhs);
        } else {
            non_rec_set.insert(rhs);
        }
    }

    if (rec_set.size() > 0)
    {
        cout << "Left recursion exists for non-termial " <<
            nt <<  endl;
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
        grammar.generator[new_nt].insert(string(1, VAREPSILON));
        grammar.use_non_ter(new_nt);
        grammar.non_terminal.insert(new_nt); // a little dangerous
        grammar.terminal.insert(VAREPSILON);
    } else {
        cout << "No left recusion exists for non terminal " << nt << endl;
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
    cout << "size: " << n << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            // if exists pattern A_i -> A_j..
            // do substitution;
            
            cout << "check if exists productions liks "
                << nts[i] << "->" << nts[j] << "..." << endl; 

            vector<string> old_rhs_to_remove;
            vector<string> new_rhs_of_i;
            for (auto RHS : grammar.generator[nts[i]]) {
                // if the first ele of RHS of A_i start with A_j,
                // we then going to substitute it
                if (RHS[0] == nts[j]) {
                    
                    cout << "\texists production " 
                        << nts[i] << "->" << RHS << " !" << endl;

                    old_rhs_to_remove.push_back(RHS);
                    // build new productions
                    // remove old productions
                    for (auto rhs: grammar.generator[nts[j]]) {
                        new_rhs_of_i.push_back(rhs.append(RHS.substr(1, RHS.length())));
                    }
                    // grammar.non_terminal.erase(nts[j]);
                    // grammar.generator.erase(nts[j]);
                }
            }
            // add new, remove old
            for (auto ss : old_rhs_to_remove) {

                    cout << "\twe are going to remove production " 
                        << nts[i] << "->" << ss << " !" << endl;

                grammar.generator[nts[i]].erase(ss);
            }

            for (auto ss : new_rhs_of_i) {

                    cout << "\twe are going to insert production " 
                        << nts[i] << "->" << ss << " !" << endl;

                grammar.generator[nts[i]].insert(ss);
            }

        }
    }
}

void left_factor(Grammar& grammar) {
    for (auto nt : grammar.non_terminal) {
        MyTrie prod_trie;
        for (auto &rhs : grammar.generator[nt])
        {
            prod_trie.add(rhs);
        }
        string longest = prod_trie.findLongestPrefix();

        if (longest.length() > 0)
        {
            auto prefix_set = prod_trie.keysWithPrefix(longest);
            auto new_nt = grammar.gen_non_ter();
            grammar.use_non_ter(new_nt);

            for (auto s : prefix_set)
            {
                grammar.generator[nt].erase(s);
                string tmp = s.substr(s.find_first_not_of(longest));
                grammar.generator[new_nt].insert(tmp);
            }

            grammar.non_terminal.insert(new_nt);
            grammar.generator[nt].insert(longest + new_nt);
        }
    }
}

int main()
{
  Grammar grammar;
  grammar.read_generator_list("./grammar2.txt");
  cout << "----------" << endl;

  grammar.print_grammar();
  cout << "----------" << endl;
  
  elim_in_rec(grammar);
  cout << "----------" << endl;

  grammar.print_grammar();
  cout << "----------" << endl;

  elim_dir_rec(grammar);
  cout << "----------" << endl;

  grammar.print_grammar();
  cout << "----------" << endl;

  left_factor(grammar);
  grammar.print_grammar();
  cout << "----------" << endl;

  
}
