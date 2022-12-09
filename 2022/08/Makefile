NAME1 = most_visible_trees1
NAME2 = highest_scenic_score2
SRC1 = part1.cpp
SRC2 = part2.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1)
	c++ $(FLAGS) $(SRC1) -o $(NAME1)

$(NAME2): $(SRC2)
	c++ $(FLAGS) $(SRC2) -o $(NAME2)

clean:

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all

.PHONY: all, clean, fclean, re
