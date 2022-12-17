EXEC = test

G++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: compile

no_flag :
	$(G++) *.cpp -o $(EXEC)

compile : 
	$(G++) $(FLAGS) *.cpp -o $(EXEC)

a_san :
	g++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address *.cpp -o test

test : compile
	./test