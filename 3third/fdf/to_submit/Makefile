SRCS = $(wildcard ./srcs/*.c)

OBJ = $(SRCS:.c=.o)

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) clean

$(NAME): $(OBJ)
	cd ./mlx && make
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

a_san: $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -fsanitize=address -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) -Iincludes -Imlx -c $< -o $@

clean :
	rm -rf *.o
	cd ./mlx && make clean

fclean : clean
	rm -rf $(NAME)

re : fclean all
