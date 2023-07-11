SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

NAME = violence

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all