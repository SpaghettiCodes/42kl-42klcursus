all : compile run

compile :
		gcc -Wall -Wextra -Werror -o test *.c

debug :
		gcc -o test *.c -g

run :
		./test

macclean :
		-rm -f *.c
		-rm -f *.exe

winclean :
		-del -f *.c
		-del -f *.exe
	
norm	:
		norminette *.