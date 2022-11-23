FDF = help.c

SRCS = $(FDF)
 
OBJ = $(SRCS:.c=.o)

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx-linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all