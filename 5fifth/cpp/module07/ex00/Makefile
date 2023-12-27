MAIN = main.cpp

EXEC = test

G++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(EXEC)

$(EXEC) : $(MAIN)
	$(G++) $(FLAGS) $(MAIN) -o $(EXEC)

a_san :
	g++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address *.cpp -o test

clean :
	@echo 'Definately Cleaning Something...'

fclean: clean
	rm -rf ${EXEC}

re: fclean all
