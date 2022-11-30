#ifndef GRAMMER_H
#define GRAMMER_H 

#include <iostream>
#include <fstream>
#include <set>
#include <map>
using std::set;
using std::map;
using std::string;
using std::cin; using std::cout;
using std::endl;

class Grammer {

public:
    using production=std::pair<string, string>;
    Grammer(); //  构造器
    ~Grammer(); // 销毁器
    void read_generator_list(string filename);//从文件读取文法
    void print_grammer(); // 打印整个文法
    void print_non_termial();
    void print_termial();

private:
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
        cout << ";" << endl;
    }
    /* 打印整个文法 */
    void print_table (const map<string, set<string>>& m);
    /* 产生式的数量 */
    int num;
    /* 非终端元素 */
    set<char> non_terminal;
    /* 终端元素 */
    set<char> terminal;
    /* 开始符号 */
    string start;
    /* 保存产生式 */
    map<string, set<string>> generator; 

};


#endif
