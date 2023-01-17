SRCS_C =    $(wildcard ./pushswap_srcs/*.c)

BONUS_C =   $(wildcard ./checker_srcs/*.c)

BONUS_H = checker.h

SRCS_H = push_swap.h

SRCS_O := ${SRCS_C:.c=.o}

BONUS_O := ${BONUS_C:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = push_swap

BONUS = checker

all : $(NAME)

bonus : $(BONUS)

.c.o :
		gcc ${CFLAG} -I./includes -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
		gcc $(CFLAG) -o $(NAME) $(SRCS_O)

$(BONUS): ${BONUS_O}
		gcc $(CFLAG) -o $(BONUS) $(BONUS_O)

clean :
		rm -f ${SRCS_O}
		rm -f ${BONUS_O}

fclean : clean
		rm -f $(NAME)
		rm -f $(BONUS)

test : $(NAME) $(BONUS) clean
	./$(NAME) $(ARG) | ./$(BONUS) $(ARG)

re : fclean all bonus