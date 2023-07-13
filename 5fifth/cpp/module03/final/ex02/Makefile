SRCS = FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp

HEADER = FragTrap.hpp ScavTrap.hpp ClapTrap.hpp

NAME = fragtrap

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
		rm -f $(NAME)

fclean : clean

re : fclean all