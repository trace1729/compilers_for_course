CC=g++
CFLAGS=-g --std=c++17

########################################### 编译原理 实验一
lex: test_lex.o lab01.o unit_test.o 
	$(CC) $(CFLAGS) -o lex test_lex.o lab01.o unit_test.o
	@mv *.o out/

test_lex.o: test_lex.cpp # 
	$(CC) $(CFLAGS) -c test_lex.cpp

lab01.o: lab01.cpp
	$(CC) $(CFLAGS) -c lab01.cpp

########################################### unit_test
unit_test.o: unit_test.cpp unit_test.h
	$(CC) $(CFLAGS) -c unit_test.cpp

clean:
	rm -f 
	rm -f lex
	rm -f out/*.o

save:
	git add *.c *.cpp *.h Makefile 
	git commit -m "lazy"

