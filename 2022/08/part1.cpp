#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define SIZE 99

int	check_visible(int i, int j, int tree_grid[SIZE][SIZE])
{
	int ii = 0;
	int jj = 0;
	int	not_visible = 0;

	while (ii < SIZE)
	{
		if (tree_grid[ii][j] >= tree_grid[i][j])
		{
			if (ii < i)
				ii = i;
			else
				ii = SIZE;
			not_visible++;
		}
		ii++;
	}
	while (jj < SIZE)
	{
		if (tree_grid[i][jj] >= tree_grid[i][j])
		{
			if (jj < j)
				jj = j;
			else
				jj = SIZE;
			not_visible++;
		}
		jj++;
	}
	return (not_visible < 4);
}

int main(void)
{
	std::ifstream myfile("input.txt");
	std::string line;
	int	tree_grid[SIZE][SIZE];
	int	visible_trees = (SIZE - 1) * 4;

	if (myfile.is_open())
	{
		for (int i = 0; i < SIZE; i++)
		{
			getline (myfile,line);
			for (int j = 0; j < SIZE; j++)
			{
				tree_grid[i][j] = line.at(j) - 48;
			}
		}
		for (int i = 1; i < SIZE - 1; i++)
		{
			for (int j = 1; j < SIZE - 1; j++)
			{
				visible_trees += check_visible(i, j, tree_grid);
			}
		}
		std::cout << "most visible trees from one tree: " << visible_trees << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
