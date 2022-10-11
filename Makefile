CC=g++
CFLAGS=-g --std=c++17


################################################### week 3
week3_ex01: data_week3_ex01.o
	$(CC) $(CFLAGS) -o ex01 data_week3_ex01.o

data_week3_ex01.o: data_week3_ex01.c
	$(CC) $(CFLAGS) -c data_week3_ex01.c

week3_ex02: data_week3_ex02.o
	$(CC) $(CFLAGS) -o ex02 data_week3_ex02.o

data_week3_ex02.o: data_week3_ex02.cpp
	$(CC) $(CFLAGS) -c data_week3_ex02.cpp

################################################### week 4

week4_ex01: data_week4_ex01.o
	$(CC) $(CFLAGS) -o ex01 data_week4_ex01.o

data_week4_ex01.o: data_week4_ex01.cpp
	$(CC) $(CFLAGS) -c data_week4_ex01.cpp


week4_ex02: data_week4_ex02.o
	$(CC) $(CFLAGS) -o ex02 data_week4_ex02.o

data_week4_ex02.o: data_week4_ex02.cpp
	$(CC) $(CFLAGS) -c data_week4_ex02.cpp

################################################### week 5
week5_ex02: data_week5_ex02.o
	$(CC) $(CFLAGS) -o ex02 data_week5_ex02.o

data_week5_ex02.o: data_week5_ex02.cpp
	$(CC) $(CFLAGS) -c data_week5_ex02.cpp

week6_ex02: data_week6_ex02.o
	$(CC) $(CFLAGS) -o ex02 data_week6_ex02.o

data_week6_ex02.o: data_week6_ex02.cpp
	$(CC) $(CFLAGS) -c data_week6_ex02.cpp

week7_ex02: data_week7_ex02.o
	$(CC) $(CFLAGS) -o ex02 data_week7_ex02.o

data_week7_ex02.o: data_week7_ex02.cpp
	$(CC) $(CFLAGS) -c data_week7_ex02.cpp

lex1: test_lex.o lex_compiler_lab01.o
	$(CC) $(CFLAGS) -o lex1 test_lex.o lex_compiler_lab01.o

test_lex.o: test_lex.c lex.h
	$(CC) $(CFLAGS) -c test_lex.c

lex_compiler_lab01.o: lex_compiler_lab01.c lex.h
	$(CC) $(CFLAGS) -c lex_compiler_lab01.c

clean:
	rm -f 
	rm -f lex1
	rm -f ex*
	rm -f *.o

save:
	git add *.c *.cpp *.h Makefile 
	git commit -m "lazy"

