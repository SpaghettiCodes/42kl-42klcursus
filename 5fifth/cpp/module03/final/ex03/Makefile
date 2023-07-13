SRCS = DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp

HEADER = DiamondTrap.hpp FragTrap.hpp ScavTrap.hpp ClapTrap.hpp

NAME = diatrap

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
		rm -f $(NAME)

fclean : clean

re : fclean all