#ifndef GRAMMAR_H
#define GRAMMAR_H 

#include <iostream>
#include <fstream>
#include <set>
#include <map>


#define VAREPSILON "@"
#define TERMIANL 0
#define NONTERMINAL 1
#define OFFSET 27 

using std::set;
using std::map;
using std::string;
using std::cin; using std::cout;
using std::endl;

class Grammar {

public:
    Grammar(); //  构造器
    ~Grammar(); // 销毁器
    void read_generator_list(string filename);//从文件读取文法
    void print_grammar(); // 打印整个文法
    void print_non_termial();
    void print_termial();
    char gen_non_ter();
    void use_non_ter(char nt);

    /* 打印一个产生式的右端  */
    template <typename T=string>
    void print_set(const set<T>& ss) {
        int size = ss.size(), cnt = 0;
        for (auto it = ss.begin(); it != ss.end(); ++it) {
            cnt++;
            if (cnt < size)
                cout << *it << "|";
            else
                cout << *it ;
        }
    }
    /* 打印整个文法 */
    void print_table (const map<char, set<string>>& m);
    /* 产生式的数量 */
    int num;
    /* 非终端元素 */
    set<char> non_terminal;
    /* 终端元素 */
    set<char> terminal;
    /* 开始符号 */
    string start;
    /* 保存产生式 */
    map<char, set<string>> generator; 
    /* 保存未使用的字母 */
private:
    int* alphabet;
    const int SIZE = 27;
};


#endif
