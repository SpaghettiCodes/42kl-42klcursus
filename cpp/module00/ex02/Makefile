all: compile

compile : Account.o tests.o 
	g++ -Wall -Wextra -Werror -std=c++98 Account.o tests.o -o test

tests.o :
	g++ -c tests.cpp

Account.o :
	g++ -c Account.cpp

clean :
	rm -rf *.o

a_san : tests.o Account.o
	g++ -Wall -Wextra -Werror -std=c++98 Account.o tests.o -o test

re : clean compile