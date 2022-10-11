CC=g++
CFLAGS=-g --std=c++17


################################################### week 3

week3_ex01: data_week3_ex01.o util.o
	$(CC) $(CFLAGS) -o ex01 data_week3_ex01.o util.o

data_week3_ex01.o: data_week3_ex01.cpp dm.h
	$(CC) $(CFLAGS) -c data_week3_ex01.cpp

week3_ex02: data_week3_ex02.o 
	$(CC) $(CFLAGS) -o ex02 data_week3_ex02.o

data_week3_ex02.o: data_week3_ex02.cpp
	$(CC) $(CFLAGS) -c data_week3_ex02.cpp

################################################### week 4
# 1
week4_ex01: data_week4_ex01.o util.o
	$(CC) $(CFLAGS) -o ex01 data_week4_ex01.o util.o

data_week4_ex01.o: data_week4_ex01.cpp dm.h
	$(CC) $(CFLAGS) -c data_week4_ex01.cpp

# 2
week4_ex02: data_week4_ex02.o util.o
	$(CC) $(CFLAGS) -o ex02 data_week4_ex02.o util.o

data_week4_ex02.o: data_week4_ex02.cpp dm.h
	$(CC) $(CFLAGS) -c data_week4_ex02.cpp

# 3
week4_ex03: data_week4_ex03.o util.o
	$(CC) $(CFLAGS) -o ex03 data_week4_ex03.o util.o

data_week4_ex03.o: data_week4_ex03.cpp dm.h
	$(CC) $(CFLAGS) -c data_week4_ex03.cpp


################################################# 工具函数

util.o: util.cpp dm.h
	$(CC) $(CFLAGS) -c util.cpp

#################################################



########################################### 编译原理 实验一
lex1: test_lex.o lex_compiler_lab01.o
	$(CC) $(CFLAGS) -o lex1 test_lex.o lex_compiler_lab01.o

test_lex.o: test_lex.c lex.h  # 在每一个.cpp 文件中 加上 头文件即可
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

