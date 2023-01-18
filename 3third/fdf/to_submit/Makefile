SRCS = $(wildcard ./srcs/*.c)

OBJ = $(SRCS:.c=.o)

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : a_san

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

a_san: $(OBJ)
	$(CC) $(OBJ) -lmlx -fsanitize=address -g3 -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Iincludes -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
