#include "lex.h"
#include <fstream>

string read_file(const string& filename){
    string res, s;
    int cnt = 0;
    std::ifstream file(filename);
    while(std::getline(file, s)) {
        if (file.fail() || file.eof()) {
            break;
        }
        res += s;
        res += '\n';
    }
    return res;
}

int main(int argc, char* argv[]) {

    printf("Testing begins \n");
    string file_test = read_file("res/read.txt");
    string short_test = "1";
    SymbolTable symbols = scan(file_test);
    print_symbol_table(symbols);
}
/*
 * 处理一些比较 简易的 错误
 * 比如 16 进制里出现了 非法字符 0x19z 001
    string test1 = "if data+92>0x3f then; \
        \n\t data=data+01; \
        \nelse   \
        \n\tdata=data-01\n1+2;";
 **/