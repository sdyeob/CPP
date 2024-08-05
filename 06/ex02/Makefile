CC = c++
CXXFLAGS =  -g #-Wall -Werror -Wextra -std=c++98

NAME = Identification
SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I.

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
