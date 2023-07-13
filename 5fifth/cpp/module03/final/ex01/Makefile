SRCS = ScavTrap.cpp ClapTrap.cpp main.cpp

HEADER = ScavTrap.hpp ClapTrap.hpp

NAME = scavtrap

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
		rm -f $(NAME)

fclean : clean

re : fclean all