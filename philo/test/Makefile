.PHONEY: re

all: thread time

thread : 
	gcc test2.c -lpthread -o test

time :
	gcc daytime.c -o time

clean :
	rm -rf test time

re: clean all