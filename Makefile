CC=gcc
CFLAGS=--std=c99

lex1: test_lex.o compiler_lab01.o
	$(CC) $(CFLAGS) -o lex1 test_lex.o compiler_lab01.o

test_lex.o: test_lex.c lex.h
	$(CC) $(CFLAGS) -c test_lex.c

compiler_lab01.o: compiler_lab01.c lex.h
	$(CC) $(CFLAGS) -c compiler_lab01.c

clean:
	rm -f lex1
	rm -f *.o
