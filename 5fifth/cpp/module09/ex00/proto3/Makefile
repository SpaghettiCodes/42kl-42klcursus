SRC = main.cpp BitcoinExchange.cpp

HEADER = BitcoinExchange.hpp

OBJ = $(SRC:.cpp=.o)

EXEC = btc

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