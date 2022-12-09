#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define SIZE 99

int	check_view(int i, int j, int tree_grid[SIZE][SIZE])
{
	int result = 1;
	int k;
	int	count = 0;

	k = i - 1;
	while (k >= 0)
	{
		if (tree_grid[k][j] >= tree_grid[i][j])
		{
			count ++;
			break ;
		}
		count++;
		k--;
	}
	result *= count;
	count = 0;
	k = i + 1;
	while (k < SIZE)
	{
		if (tree_grid[k][j] >= tree_grid[i][j])
		{
			count ++;
			break ;
		}
		count++;
		k++;
	}
	result *= count;
	count = 0;
	k = j - 1;	
	while (k >= 0)
	{
		if (tree_grid[i][k] >= tree_grid[i][j])
		{
			count ++;
			break ;
		}
		count++;
		k--;
	}
	result *= count;
	count = 0;
	k = j + 1;
	while (k < SIZE)
	{
		if (tree_grid[i][k] >= tree_grid[i][j])
		{
			count ++;
			break ;
		}
		count++;
		k++;
	}
	result *= count;
	return (result);
}

int main(void)
{
	std::ifstream myfile("input.txt");
	std::string line;
	int	tree_grid[SIZE][SIZE];
	std::vector<int> views;

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
				views.push_back(check_view(i, j, tree_grid));
			}
		}
		sort(views.begin(), views.end());
		std::cout << "highest scenic score: " << views.at(views.size() - 1) << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
