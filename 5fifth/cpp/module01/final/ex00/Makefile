SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

HEADER = Zombie.hpp

NAME = zombie

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all