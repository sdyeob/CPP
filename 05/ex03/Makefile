CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES = -I./includes
RM += -rf
NAME = Interns
SRCS = main.cpp Bureaucrat.cpp Intern.cpp \
		$(addprefix Forms/, AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp)

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
