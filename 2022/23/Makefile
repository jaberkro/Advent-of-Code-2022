NAME1 = ground_tiles1
SRC1 = part1+2.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME1)

$(NAME1): $(SRC1)
	c++ $(FLAGS) $(SRC1) -o $(NAME1)

clean:

fclean: clean
	rm -rf $(NAME1)

re: fclean all

.PHONY: all, clean, fclean, re
