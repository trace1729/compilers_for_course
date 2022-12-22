#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
#include "grammar.h"
#include "lr.h"
#include "lex.h"

using namespace std;
#define DEBUG 0

bool LR_Parser(string input) {
    stack<char> symbol;
    stack<int> states;
    states.push(0);
    symbol.push('#');
    input += '#';
    int state = 0;
    int idx = 0;

    int prod_id;
    Production prod;
    char nt;
    string rhs;

    while (!symbol.empty()) {

        state = states.top();
        char sym = idx >= input.length() ? '#' : input[idx]; 

#if DEBUG == 1
        printf("Now, input idx has pointed to char=%c\n", sym);
        printf("action = actionTable[%d][%c]\n", state, sym);
#endif
        auto action = actionTable[state][sym];
        switch (action.act)
        {
        case SHIFT:

#if DEBUG == 1
            printf("Now we are performing shift(%d) operation\n", action.content);
#endif
            if (sym != '#')
                symbol.push(sym);

            states.push(action.content);
#if DEBUG == 1
            printf("Push char input[%d]= %c into the stack\n", idx, input[idx]);
#endif
            idx ++;
            break;
        case REDUCE:
#if DEBUG == 1
            printf("Now we are performing reduce(%d) operation, prod = %c -> %s\n", action.content, 
            productionTable[action.content].LHS, productionTable[action.content].RHS.c_str());
#endif
            // do reduce
            prod_id = action.content;
            prod = productionTable[prod_id];
            nt = prod.LHS, rhs = prod.RHS;
            for (int _ = 0; _ < rhs.length(); _++) {
                states.pop();
                symbol.pop();

            }
#if DEBUG == 1
            printf("Push char %c into the stack\n", nt);
#endif
            symbol.push(nt);
            state = gotoTable[states.top()][nt].content;
            if (state < 0) 
                return false;
            else 
                states.push(state);
            break;
        case ACC:
            return true;
        case ERROR:
            return false;
        default:
            break;
        }
    }
    return false;
}



void test_lr_parser() {
    // Test 1
    string input = "10;";
    string toTest = convert(input);
    cout << "Test sentence " << toTest << "[EOF]" << endl;
    bool expected_output = true;
    cout << LR_Parser(toTest) << endl;
    assert(LR_Parser(toTest) == expected_output);

    // Test 2
    input = "1+2;";
    toTest = convert(input);
    cout << "Test sentence " << toTest << "[EOF]" << endl;
    expected_output = true;
    assert(LR_Parser(toTest) == expected_output);

    // Test 3
    input = "(1+2)*3+(5+6*7);";
    toTest = convert(input);
    cout << "Test sentence " << toTest << "[EOF]" << endl;
    expected_output = true;
    assert(LR_Parser(toTest) == expected_output);

    // Test 4
    input = "((1+2)*3+4";
    toTest = convert(input);
    expected_output =false;
    assert(LR_Parser(toTest) == expected_output);

    // Test 5
    input = "1+2+3+(*4+5)";
    toTest = convert(input);
    expected_output =false;
    assert(LR_Parser(toTest) == expected_output);

    // Test 6
    input = "(a+b)*(c+d)";
    toTest = convert(input);
    expected_output = true;
    assert(LR_Parser(toTest) == expected_output);

    // Test 7
    input = "((ab3+de4)**5)+1";
    toTest = convert(input);
    expected_output = false;
    assert(LR_Parser(toTest) == expected_output);
}

int main()
{
    Grammar grammar;
    grammar.read_generator_list("./grammar5.txt");
    grammar.print_grammar();
    printf("-------------------------------\n");
    
    int prod_id = 1;
    
    for (int prod_pri = 0; prod_pri < productionPriority.size(); prod_pri++) {
        char nt = productionPriority[prod_pri];
        for (auto& rhs : grammar.generator[nt]) {
            Production prod = {nt, rhs};
            productionTable.insert({prod_id, prod});
            prod_id++;
        }

    }

    /** 只是为了序号保持一致， 无实际意义 */
        productionTable.erase(3);
        productionTable.erase(4);
        productionTable.insert({3, {'T', "T*F"}});
        productionTable.insert({4, {'T', "F"}});
    /** 只是为了序号保持一致， 无实际意义 */

    for (auto&[id, prod]: productionTable) {
        auto&[lhs, rhs] = prod;
        printf("%d: %c -> %s\n", id, lhs, rhs.c_str());
    }
    printf("-------------------------------\n");

    test_lr_parser();

    cout << "You passed all tests!" << endl;

    return 0;
}
