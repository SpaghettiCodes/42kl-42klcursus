# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 16:29:12 by cshi-xia          #+#    #+#              #
#    Updated: 2022/07/17 18:55:58 by cshi-xia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

SRCS_H = ft_printf.h

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

clean :
		@rm -rf $(wildcard *.o)
		@echo "cleaned"

fclean : clean
		@rm -rf ${NAME}
		@echo "deleted everything"

bonus : re

re : fclean all
