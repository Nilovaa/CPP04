NAME = Polymorphism

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(FLAGS) $(OBJS) -o $@

%.o: %.cpp
		$(CPP) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
