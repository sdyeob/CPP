
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
INCLUDES = -Idefines -Iincludes

NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp utils.cpp 

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

.PHONY: clean all fclean re
