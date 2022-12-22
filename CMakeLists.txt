cmake_minimum_required(VERSION 3.10)
# configure_file(res/grammar5.txt res/grammar4.txt res/grammar3.txt COPYONLY)

project(compilers)

add_executable(lab01 test_lex.cpp lab01.cpp)
add_executable(lab02 lab02.cpp grammar.cpp)

# add_executable(lab03 lab03.cpp trie.cpp grammar.cpp)
add_executable(lab04 lab04.cpp grammar.cpp lab01.cpp trie.cpp lab03.cpp)

add_executable(lab05 lab05.cpp grammar.cpp lab01.cpp)

### 可以做的改进
## 构建grammar链接库 和 trie 链接库。 项目需要的时候 直接链接上去，而不是直接使用
## .cpp 文件
## 正确引入资源文件