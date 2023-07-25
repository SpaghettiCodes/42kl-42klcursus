SRCS = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp

HEADER = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

NAME = animal

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :

fclean : clean
		rm -f $(NAME)

re : fclean all