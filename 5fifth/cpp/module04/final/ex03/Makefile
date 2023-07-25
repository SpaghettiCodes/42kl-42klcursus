SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp

HEADER = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMaterialSource.hpp MateriaSource.hpp

NAME = materia

all: $(NAME)

$(NAME) : $(SRCS) $(HEADER)
		g++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

clean :
		rm -f $(NAME)

fclean : clean

re : fclean all