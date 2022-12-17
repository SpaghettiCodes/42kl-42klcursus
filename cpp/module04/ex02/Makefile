EXEC = test

G++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: compile

compile : 
	$(G++) $(FLAGS) *.cpp -o $(EXEC)

a_san :
	$(G++) $(FLAGS) -fsanitize=address *.cpp -o $(EXEC)