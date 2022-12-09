CC=g++
CFLAGS=-g --std=c++17
########################################### 编译原理 实验四
lab04: lab04.o grammar.o lab03.o grammar.h ./grammar4.txt
	$(CC) $(CFLAGS) -o lab04 lab04.o lab03.o grammar.o 
	@./lab04

lab04.o: lab04.cpp
	$(CC) $(CFLAGS) -c lab04.cpp
########################################### 编译原理 实验三

lab03: lab03.o grammar.o grammar.h ./grammar1.txt ./grammar2.txt
	$(CC) $(CFLAGS) -o lab03 lab03.o grammar.o 
	@./lab03

lab03.o: lab03.cpp
	$(CC) $(CFLAGS) -c lab03.cpp

########################################### 编译原理 实验二
lab02: lab02.o grammar.o grammar.h
	$(CC) $(CFLAGS) -o lab02 lab02.o grammar.o
	@./lab02

grammar.o: grammar.cpp
	$(CC) $(CFLAGS) -c grammar.cpp

lab02.o: lab02.cpp
	$(CC) $(CFLAGS) -c lab02.cpp


########################################### 编译原理 实验一
lab01: test_lex.o lab01.o unit_test.o 
	$(CC) $(CFLAGS) -o lab01 lab01.o test_lex.o unit_test.o

test_lex.o: test_lex.cpp # 
	$(CC) $(CFLAGS) -c test_lex.cpp

lab01.o: lab01.cpp
	$(CC) $(CFLAGS) -c lab01.cpp

########################################### unit_test
unit_test.o: unit_test.cpp unit_test.h
	$(CC) $(CFLAGS) -c unit_test.cpp

clean:
	rm -f 
	rm -f lab01
	rm -f lab02
	rm -f *.o
	rm -f out/*.o

save:
	git add *.c *.cpp *.h Makefile 
	git commit -m "lazy"

