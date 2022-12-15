#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
#include "grammar.h"
#include "elim_rec.h"
#include "lex.h"
using namespace std;

typedef set<char> TerminalSet;
typedef unordered_map<char, TerminalSet> FirstSet;
typedef unordered_map<char, TerminalSet> FollowSet;
typedef unordered_map<char, unordered_map<char, Production> > ParseTable;
#define MARKER '#'
#define DEBUG 0

FirstSet ComputeFirstSet (Grammar & grammar) {   
    FirstSet first_set;
    
#if DEBUG == 1
    cout << "Initilize first set" << endl;
#endif
    for (const auto& nt: grammar.non_terminal) {
        first_set[nt] = {};
    }

    for (const auto& t: grammar.terminal) {
        first_set[t] = {t};
    }

    bool changed = true; // 停止标志
    while (changed) {        
        changed = false;
        
        for (const auto& nt : grammar.non_terminal) {
            

            TerminalSet rhs_first_set = {};
            bool is_nullable = true;
            for (const auto& RHS: grammar.generator[nt]) {
                // RHS :: string
#if DEBUG == 1
                cout << "We are working on production"
                     << " " << nt << " "  << "->" 
                     << " " << RHS << endl; 
#endif

                for (const char& symbol: RHS) {
                    // symbol :: char
                    // if the symbol is terminal, we 
                    // are done on this production
                    if (grammar.terminal.count(symbol) == 1) {
                        rhs_first_set.insert(symbol);
                        is_nullable = false;
                        
#if DEBUG == 1
                        cout << "We meet " << "nontermal " << 
                            symbol << " Stop!" << endl;
#endif

                        break;
                    } // end if

                    // if symbol is non-terminal 
                    // we then check whether 
                    //  if first(symbol) contains varpsilon
                    //      set is_nullable to true;
                    
                    rhs_first_set.insert(first_set[symbol].begin(),
                                         first_set[symbol].end());
                    if (first_set[symbol].count(VAREPSILON) == 0) {
                        
#if DEBUG == 1
                        cout << "We meet " << "a not nullable non-terminal " << 
                            symbol << " Stop!" << endl;
#endif

                        is_nullable = false;
                        break;
                    } // end if
                } // end for
            }     // end for
            if (is_nullable)
            {
#if DEBUG == 1
                cout << "non terminal " << nt << " is nullable" << endl;
#endif
                rhs_first_set.insert(VAREPSILON);
            }
            if (rhs_first_set.size() != first_set[nt].size())
            {
                changed = true;
                first_set[nt].clear();
                first_set[nt].insert(rhs_first_set.begin(),
                                     rhs_first_set.end());
#if DEBUG == 1
                cout << endl;
#endif
            }
            else
            {
#if DEBUG == 1
                cout << "first set"
                     << " " << nt << " not changed" << endl;
#endif
                changed = false;
            }
        } // end for
    }     // end while
    return first_set;
} // end fun

TerminalSet ComputeMuFirstSet (string prod, FirstSet first_set) {
    // assume len(prod) is bigger than 1
    if (prod.length() == 1) {
        return first_set[prod[0]];
    }

    auto start_first_set = first_set[prod[0]];
    TerminalSet ans(start_first_set);
    if (start_first_set.count(VAREPSILON) != 1) {
        return ans;

    } else {
        TerminalSet res = ComputeMuFirstSet(prod.substr(1), first_set);
        ans.insert(res.begin(), res.end());
        return ans;
    }

}

FollowSet ComputeFollowSet(Grammar& grammar, FirstSet first_set) 
{
    FollowSet follow_set;
    
    cout << "Initilize follow set" << endl;
    for (const auto& nt: grammar.non_terminal) {
        follow_set[nt] = {};
    }

    follow_set[grammar.start].insert(MARKER);
 
    cout << "Adding start symbol # for " << grammar.start << endl;
        

    bool changed = true; // 停止标志
    int pre_follow_set_size = 0;
    while (changed) {        
        for (const auto& nt : grammar.non_terminal) {
            for (const auto& RHS: grammar.generator[nt]) {
 #if DEBUG == 1
                cout <<"Processing prod " <<nt <<"->" << RHS << endl; 
#endif
                for (int i = 0; i < RHS.length(); i++)
                {
                    char c = RHS[i];
                    if (grammar.non_terminal.count(c) == 1)
                    {
                        // TODO 排除自己添加自己
#if DEBUG == 1
                        cout << "We are going to work out the follow set for nt " << c <<  endl;
#endif
                        if (i == RHS.length() - 1)
                        {
                            if (c == nt) continue;
#if DEBUG == 1
                            cout << "We are dealing with Type" << " A -> alpha B" << endl;
                            cout <<"\tAdding follow(" << nt << ")" << " to follow(" << c << ")!" << endl;
#endif

                            follow_set[c].insert(
                                follow_set[nt].begin(), follow_set[nt].end());
                        }
                        else
                        {
#if DEBUG == 1
                            cout << "We are dealing with Type" << " A -> alpha B beta" << endl;
#endif
                            TerminalSet first_tmp = ComputeMuFirstSet(RHS.substr(i + 1), first_set);
                            if (first_tmp.count(VAREPSILON) == 1)
                            {
                                if (c == nt) continue;  
#if DEBUG == 1
                                cout <<"\tsince first(" << RHS.substr(i+1) << ") is nullable" << endl; 
                                cout <<"\tAdding follow(" << nt << ")" << " to follow(" << c << ")!" << endl;
#endif
                                follow_set[c].insert(
                                    follow_set[nt].begin(), follow_set[nt].end());
                            }
#if DEBUG == 1
                            cout <<"\tAdding first(" << RHS.substr(i + 1) << ")" << " to follow(" << c << ")!" << endl;
#endif
                            follow_set[c].insert(
                                first_tmp.begin(), first_tmp.end());
                        }
                    }
                } // end for
            } // end for
        } // end for
        int follow_set_size = 0;
        for (auto& [k, v] : follow_set) {
            follow_set_size += v.size();
        }
        if (follow_set_size == pre_follow_set_size) {
            changed = false;
        } else {
            pre_follow_set_size = follow_set_size;
        }
    } // end while

    for (auto& [k, v] : follow_set) {
        if(v.count(VAREPSILON)==1 ) {
            v.erase(VAREPSILON);

        }
    }
    return follow_set;
}

ParseTable construct_parse_table (Grammar grammar, FirstSet first_set, FollowSet follow_set) {
    ParseTable parse_table;
    for (auto& nt: grammar.non_terminal) {
        for (auto & RHS: grammar.generator[nt]) {
            Production production = {nt, RHS};
            auto rhs_first = ComputeMuFirstSet(RHS, first_set);
            for (auto terminal: rhs_first) {
                if (terminal == VAREPSILON) continue;
                parse_table[nt][terminal] = production;
            }
            if (rhs_first.count(VAREPSILON) == 1) {
                for (auto terminal: follow_set[nt]) {
                    parse_table[nt][terminal] = production;
                }
            }
        }
    } 
    return parse_table;
}

bool LL_parse( const Grammar& grammar, const string& inpu, ParseTable& table) {
    vector<char> symbol_stack;
    symbol_stack.push_back(MARKER);
    symbol_stack.push_back(grammar.start);
    
    string input = inpu + MARKER;

    size_t pos = 0;

    while (!symbol_stack.empty() && pos < input.length()) {
        // If the top symbol on the stack is a terminal symbol and the symbol
        // at the current position in the input string is the same, pop the
        // symbol from the stack and advance the current position in the input
        // string.
        char top = symbol_stack[symbol_stack.size() - 1];
        if (top == MARKER) {
            symbol_stack.pop_back();
            pos++;
        }
        else if (grammar.terminal.count(top) == 1 || top == MARKER)
        {
            if (top == input[pos]) {
                symbol_stack.pop_back();
                pos++;
            } else if (top == VAREPSILON){
                symbol_stack.pop_back();
            } else {
                cout << "stack top" << top << " does not match " << input[pos] << endl; 
                return false;
            }
        }
        else if (grammar.non_terminal.count(top) == 1)
        {
            // If the top symbol on the symbol_stack is a nonterminal, look up the

            if (table[top].count(input[pos]) == 1) {
                symbol_stack.pop_back();
                Production prod = table[top][input[pos]];
                for (int i = prod.RHS.length() - 1; i >= 0; i--) {
                    symbol_stack.push_back(prod.RHS[i]);
                }
            } else {
                printf("Cann not find Corresponding production for table[%c][%c]\n", top, input[pos]);
                return false;
            }
        }
    }
    return true;
} 

void test_ll_parser(Grammar& grammar, ParseTable& table) {
    // Test 1
    string input = "(1+2)*3+(5+6*7);";
    string toTest = convert(input);
    cout << "Test sentence " << toTest << "[EOF]" << endl;
    bool expected_output = true;
    cout << LL_parse(grammar,toTest, table) << endl;
    assert(LL_parse(grammar,toTest, table) == expected_output);

    // Test 2
    input = "1+2;";
    toTest = convert(input);
    cout << "Test sentence " << toTest << "[EOF]" << endl;
    expected_output = true;
    assert(LL_parse(grammar,toTest, table) == expected_output);

    // Test 3
    input = "(1+2)*3+(5+6*7);";
    toTest = convert(input);
    cout << "Test sentence " << toTest << "[EOF]" << endl;
    expected_output = true;
    assert(LL_parse(grammar,toTest, table) == expected_output);

    // Test 4
    input = "((1+2)*3+4";
    toTest = convert(input);
    expected_output =false;
    assert(LL_parse(grammar,toTest, table) == expected_output);

    // Test 5
    input = "1+2+3+(*4+5)";
    toTest = convert(input);
    expected_output =false;
    assert(LL_parse(grammar,toTest, table) == expected_output);

    // Test 6
    input = "(a+b)*(c+d)";
    toTest = convert(input);
    expected_output = true;
    assert(LL_parse(grammar,toTest, table) == expected_output);

    // Test 7
    input = "((ab3+de4)**5)+1";
    toTest = convert(input);
    expected_output = false;
    assert(LL_parse(grammar,toTest, table) == expected_output);
}

int main()
{
    Grammar grammar;
    grammar.read_generator_list("./grammar5.txt");

    elim_dir_rec(grammar);
    cout << "----------" << endl;
    grammar.print_grammar();
    cout << "----------" << endl;

    auto first_set = ComputeFirstSet(grammar);

#if DEBUG == 1
    cout << "---------" << endl;
    cout << "Below is the first set for this grammar! " << endl;
    for (const auto &[k, v] : first_set)
    {
        cout << "first set for symbols " << k << " is: { ";
        for (const auto &c : v)
        {
            cout << c << " ";
        }
        cout << "}" << endl;
    }
    cout << "----------" << endl;
#endif
    auto follow_set = ComputeFollowSet(grammar, first_set);
#if DEBUG == 1
    cout << "---------" << endl;
    cout << "Below is the follow set for this grammar! " << endl;

    for (const auto &[k, v] : follow_set)
    {
        cout << "follow set for symbols " << k << " is: { ";
        for (const auto &c : v)
        {
            cout << c << " ";
        }
        cout << "}" << endl;
    }
#endif 
    auto parse_table = construct_parse_table(grammar, first_set, follow_set);
    cout << "---------" << endl;
    for (const auto& [nt, predict] :parse_table) {
        cout << nt << ": {";
        for (const auto& [terminal, prod]: predict) {
            printf("[%c : %c->%s] ", terminal, prod.LHS, prod.RHS.c_str());
        }
        cout << "}" << endl;
    }
    cout << "---------" << endl;

    test_ll_parser(grammar, parse_table);
    cout << "You passed all tests" << endl;
    
    return 0;
}