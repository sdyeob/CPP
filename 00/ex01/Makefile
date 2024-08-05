NAME := Phonebook
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM = rm -rf
INCLUDES = includes

SRCS = main.cpp $(addprefix srcs/, Contact.cpp PhoneBook.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c -o $@ $< 

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re