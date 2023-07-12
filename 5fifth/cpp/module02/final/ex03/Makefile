SRCS = Fixed.cpp main.cpp bsp.cpp Point.cpp

HEADER = Fixed.hpp bsp.hpp Point.hpp

NAME = bsp

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
		rm -f $(NAME)

fclean : clean

re : fclean all