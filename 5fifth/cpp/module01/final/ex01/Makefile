SRCS = main.cpp Zombie.cpp zombieHorde.cpp

HEADER = Zombie.hpp

NAME = zombiehorde

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all