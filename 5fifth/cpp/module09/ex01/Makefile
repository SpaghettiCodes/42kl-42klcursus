SOURCE = RPN.cpp main.cpp

HEAD = RPN.hpp

CPP = g++

CFLAGS = -Wall -Wextra -Werror

NAME = RPN

all: $(NAME)

$(NAME) : $(HEAD) $(SOURCE)
	@$(CPP) $(CFLAGS) $(SOURCE) -o $(NAME)
	@echo $(NAME) program compiled

clean :
	@echo "theres nothing to clean!"

fclean:
	@rm $(NAME)
	@echo $(RPN) "program removed"

re: fclean all