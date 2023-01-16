# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:13:29 by cshi-xia          #+#    #+#              #
#    Updated: 2022/07/06 17:21:36 by cshi-xia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c \
		get_next_line_utils.c \
		get_next_line.h

SRCSB = get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		get_next_line_bonus.h

SRCS_H = get_next_line.h

SRCSB_H = get_next_line_bonus.h

SRCS_O = ${SRCS:.c=.o}

SRCSB_O = ${SRCSB:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = get_next_line.a

all : ${NAME}

$(NAME)	: ${SRCS_O}
		@ar rcs ${NAME} ${SRCS_O}
		@echo "get_next_line.a generated"

.c.o :
		@gcc ${CFLAG} -c -I./ $< -o ${<:.c=.o}

bonus : fclean ${SRCSB_O}
	@ar r ${NAME} ${SRCSB_O}
	@echo "libft.a with bonus generated"

clean :
		@rm -rf $(wildcard *.o)
		@echo "cleaned"

fclean : clean
		@rm -rf ${NAME}
		@echo "deleted everything"

re : fclean all
