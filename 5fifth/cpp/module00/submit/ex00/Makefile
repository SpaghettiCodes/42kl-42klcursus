SRCS = megaphone.cpp

NAME = megaphone

all: $(NAME)

$(NAME) : 
	g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

test : $(NAME)
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all