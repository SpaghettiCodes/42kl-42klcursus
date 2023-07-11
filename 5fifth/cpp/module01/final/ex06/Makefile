SRCS = Harl.cpp main.cpp

HEADER = Harl.hpp

NAME = harlFilter

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all