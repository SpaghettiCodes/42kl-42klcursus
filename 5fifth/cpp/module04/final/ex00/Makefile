MAIN = main.cpp

MAIN2 = main2.cpp

SRCS = Animal.cpp Cat.cpp Dog.cpp $(MAIN)

SRCS2 = WrongAnimal.cpp WrongCat.cpp $(MAIN2)

HEADER = Animal.hpp Cat.hpp Dog.hpp

HEADER2 = WrongAnimal.hpp WrongCat.hpp

NAME = animal

NAME2 = wanimal

all: $(NAME) $(NAME2)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

$(NAME2) : $(SRCS2) $(HEADER2)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME2) $(SRCS2)

clean :

fclean : clean
		rm -f $(NAME)
		rm -f $(NAME2)

re : fclean all