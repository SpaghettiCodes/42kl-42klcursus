SRC = main.cpp RPN.cpp

HEADER = RPN.hpp

OBJ = $(SRC:.cpp=.o)

EXEC = RPN

G++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(EXEC)

%.o: %.cpp $(HEADER)
	g++ ${FLAGS} -c $< -o $@

$(EXEC) : $(OBJ)
	$(G++) $(OBJ) -o $(EXEC)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${EXEC}

re: fclean all