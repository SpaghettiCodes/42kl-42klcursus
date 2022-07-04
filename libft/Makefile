# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:13:29 by cshi-xia          #+#    #+#              #
#    Updated: 2022/07/04 12:13:30 by cshi-xia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c 	\
		ft_isdigit.c 	\
		ft_isalnum.c 	\
		ft_isascii.c 	\
		ft_isprint.c 	\
		ft_strlen.c 	\
		ft_memset.c 	\
		ft_bzero.c 		\
		ft_memcpy.c 	\
		ft_memmove.c 	\
		ft_strlcpy.c 	\
		ft_strlcat.c 	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c 	\
		ft_strrchr.c	\
		ft_strncmp.c 	\
		ft_memchr.c 	\
		ft_memcmp.c 	\
		ft_strnstr.c 	\
		ft_atoi.c 		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

SRCSB = $(SRCS)				\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c

SRCS_H = libft.h

SRCS_O = ${SRCS:.c=.o}

SRCSB_O = ${SRCSB:.c=.o}

CFLAG = -Wall -Wextra -Werror

NAME = libft.a

all : ${NAME}

$(NAME)	: ${SRCS_O}
		@ar rcs ${NAME} ${SRCS_O}
		@echo "libft.a generated"

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
