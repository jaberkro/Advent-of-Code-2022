NAME = calories
SRC = main.cpp
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
