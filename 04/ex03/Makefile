CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES = -I./includes
NAME = Polymorphism
SRCS = main.cpp \
		$(addprefix Character/, ICharacter.cpp Character.cpp ) \
		$(addprefix Materia/, AMateria.cpp Cure.cpp Ice.cpp ) \
		$(addprefix MateriaSource/, MateriaSource.cpp IMateriaSource.cpp )

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
