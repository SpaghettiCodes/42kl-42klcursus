SRCS =  ft_printf.c		\
		ft_case.c		\
		ft_charconv.c	\
		ft_intconv.c	\
		ft_ptrconv.c	\

SRCSB = $(wildcard *_bonus.c)

SRCS_H = ft_printf.h

SRCSB_H = ft_printf_bonus.h

SRCS_O = ${SRCS:.c=.o}

SRCSB_O = ${SRCSB:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

all : ${NAME}

$(NAME)	: ${SRCS_O}
		@ar rcs ${NAME} ${SRCS_O}
		@echo "libftprintf.a generated"

.c.o :
		@gcc ${CFLAG} -c -I./ $< -o ${<:.c=.o}

bonus : fclean ${SRCSB_O}
	@ar r ${NAME} ${SRCSB_O}
	@echo "libftprintf.a with bonus generated"

clean :
		@rm -rf $(wildcard *.o)
		@echo "cleaned"

fclean : clean
		@rm -rf ${NAME}
		@echo "deleted everything"

re : fclean all
