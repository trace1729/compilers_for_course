cmake_minimum_required(VERSION 3.10)
configure_file(res/grammar5.txt res/grammar4.txt COPYONLY)

project(compilers)

add_executable(lab01 test_lex.cpp lab01.cpp)
add_executable(lab02 lab02.cpp grammar.cpp)
add_executable(lab04 lab04.cpp grammar.cpp lab01.cpp trie.cpp lab03.cpp)
add_executable(lab05 lab05.cpp grammar.cpp lab01.cpp)



## 输入文件过多可以使用 cmake里 foreach语句。指定文件可以使用正则表达式
### 为lab02.cpp 指定输入文件 grammar.txt
add_custom_command(OUTPUT res/grammar.txt
        COMMAND ${CMAKE_COMMAND} -E copy res/grammar.txt ${CMAKE_CURRENT_BINARY_DIR}/grammar.txt
        DEPENDS res/grammar.txt)

add_custom_target(copy_file DEPENDS res/grammar.txt)
add_dependencies(lab02 copy_file)

### 为lab04.cpp lab05.cpp 指定输入文件 grammar.txt
add_custom_command(OUTPUT res/grammar5.txt
        COMMAND ${CMAKE_COMMAND} -E copy res/grammar5.txt ${CMAKE_CURRENT_BINARY_DIR}/grammar5.txt
        DEPENDS res/grammar5.txt)

add_custom_target(copy_file5 DEPENDS res/grammar5.txt)
add_dependencies(lab04 copy_file5)
add_dependencies(lab05 copy_file5)

### 可以做的改进
## 构建grammar链接库 和 trie 链接库。 项目需要的时候 直接链接上去，而不是直接使用
## .cpp 文件
## 正确引入资源文件