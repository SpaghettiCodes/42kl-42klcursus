SRCS_C = $(wildcard ./srcs/*.c)

SRCS_H = philo.h

SRCS_O = ${SRCS_C:.c=.o}

BONUS_O = ${BONUS_C:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = philo

all : $(NAME)

.c.o :
		gcc ${CFLAG} -I./includes -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
		gcc $(CFLAG) -lpthread -o $(NAME) $(SRCS_O)

clean :
		rm -f ${SRCS_O}

fclean : clean
		rm -f $(NAME)

re : fclean all
