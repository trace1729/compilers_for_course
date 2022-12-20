CC=g++
CFLAGS=-g --std=c++17

########################################### 编译原理 实验五
TARGET5 = lab05
OBJ5 =  lab05.o grammar.o lab01.o trie.o 
HEADERS5 = lr.h lex.h
FILE5 = grammar5.txt

# $@ 表示 目标文件, $^ 表示所有依赖文件 $< 表示第一个依赖文件

$(TARGET5): $(OBJ5) $(HEADERS5) $(FILES)
	$(CC) -o $@ $^
	@./lab05

lab05.o: lab05.cpp
	$(CC) $(CFLAGS) -c $<

########################################### 编译原理 实验四
TARGET4 = lab04 
OBJ4 = lab04.o grammar.o lab01.o trie.o lab03.o 
FILE4 = ./grammar4.txt

$(TARGET4): $(OBJ4) $(FILE4)
	$(CC) $(CFLAGS) -o $(TARGET4) $(OBJ4)
	@./lab04

lab04.o: lab04.cpp
	$(CC) $(CFLAGS) -c lab04.cpp

########################################### 编译原理 实验三
TARGET3 = lab03
OBJ3 = lab03.o trie.o grammar.o
FILE3 = ./grammar1.txt ./grammar2.txt

$(TARGET3): $(OBJ3) $(FILE3)
	$(CC) $(CFLAGS) -o $(TARGET3) $(OBJ3) 
	@./lab03

lab03.o: lab03.cpp
	$(CC) $(CFLAGS) -c lab03.cpp


########################################### 编译原理 实验二
TARGET2 = lab02 
OBJ2 = lab02.o grammar.o

$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2)
	@./lab02

grammar.o: grammar.cpp grammar.h
	$(CC) $(CFLAGS) -c grammar.cpp

lab02.o: lab02.cpp
	$(CC) $(CFLAGS) -c lab02.cpp


########################################### 编译原理 实验一
TARGET1 = lab01
OBJ1 = test_lex.o lab01.o 

$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJ1)

test_lex.o: test_lex.cpp # 
	$(CC) $(CFLAGS) -c test_lex.cpp

lab01.o: lab01.cpp
	$(CC) $(CFLAGS) -c lab01.cpp

########################################### util
trie: trie.o
	$(CC) $(CFLAGS) -o trie trie.o
	@./trie

trie.o: trie.cpp trie.h
	$(CC) $(CFLAGS) -c trie.cpp

clean:
	rm -f 
	rm -f lab01 lab02 lab03 lab04 lab05 demo 
	rm -f *.o

save:
	git add *.cpp *.h Makefile 
	git commit -m "lazy"

