EXEC = test

G++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: compile

compile : 
	$(G++) *.cpp -o $(EXEC)

a_san :
	g++ $(FLAGS) -fsanitize=address *.cpp -o test