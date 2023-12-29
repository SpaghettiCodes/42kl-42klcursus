MAIN = main.cpp

OBJ = $(MAIN:.cpp=.o)

EXEC = test

G++ = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(EXEC)

%.o: %.cpp
	g++ ${FLAGS} -c $< -o $@

$(EXEC) : $(OBJ)
	$(G++) $(OBJ) -o $(EXEC)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${EXEC}

re: fclean all