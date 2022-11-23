FDF = test.c

ATOI = atoi.c

SPLIT = ft_split.c ft_strdup.c ft_substr.c

GNL = get_next_line.c get_next_line_utils.c

SRCS = $(FDF) $(SPLIT) $(GNL) $(ATOI)
 
OBJ = $(SRCS:.c=.o)

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx-linux -lXext -lX11 -lm -lz -fsanitize=address -o $(NAME)

%.o : %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all