CC = g++ -g -c -Wall -ansi -pedantic -std=c++17
LN = g++


OBJS = main.o Token.o Grammar.o

myEval: $(OBJS)
	$(LN) -o myEval $(OBJS)

main.o: main.cpp Grammar.hpp Token.hpp
	$(CC) main.cpp

Grammar.o: Grammar.cpp Grammar.hpp Token.hpp
	$(CC) Grammar.cpp

Token.o: Token.cpp Token.hpp
	$(CC) Token.cpp

clean:
	/bin/rm -f  $(OBJS) myEval *~
