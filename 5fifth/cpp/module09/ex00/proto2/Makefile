SOURCE = BitcoinExchange.cpp main.cpp

HEAD = BitcoinExchange.hpp

CPP = g++

CFLAGS = -Wall -Wextra -Werror

NAME = btc

all: $(NAME)

$(NAME) : $(HEAD) $(SOURCE)
	@$(CPP) $(CFLAGS) $(SOURCE) -o $(NAME)
	@echo $(NAME) program compiled

clean :
	@echo "theres nothing to clean!"

fclean:
	@rm $(NAME)
	@echo "program removed"

re: fclean all