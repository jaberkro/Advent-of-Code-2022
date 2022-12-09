#include <iostream>
#include <fstream>
#include <string>

#define SIZE 400

int main(void)
{
	std::ifstream myfile("input.txt");
	std::string line;
	int	locs[] = {};
	int	grid[SIZE][SIZE] = {};
	int	count = 0;

	grid[SIZE / 2 + locs[3]][SIZE / 2 + locs[2]] = 1;
	if (myfile.is_open())
	{
		while (getline (myfile,line))
		{
			for (int i = 0; i < stoi(line.substr(2)); i++)
			{
				//update H
				if (line.at(0) == 'R')
					locs[0] += 1;
				else if (line.at(0) == 'L')
					locs[0] -= 1;
				else if (line.at(0) == 'U')
					locs[1] += 1;
				else if (line.at(0) == 'D')
					locs[1] -= 1;
				//update T
				if (abs(locs[0] - locs[2]) >= 2)
				{
					locs[2] += (locs[0] - locs[2]) / 2;
					if (locs[1] - locs[3] > 0)
						locs[3] = (locs[3] + 1);
					else if (locs[1] - locs[3] < 0)
						locs[3] = (locs[3] - 1);
				}
				else if (abs(locs[1] - locs[3]) >= 2 )
				{
					locs[3] += (locs[1] - locs[3]) / 2;
					if (locs[0] - locs[2] > 0)
						locs[2] = (locs[2] + 1);
					else if (locs[0] - locs[2] < 0)
						locs[2] = (locs[2] - 1);
				}
				if (SIZE / 2 + locs[3] >= SIZE || SIZE / 2 + locs[2] >= SIZE || \
					SIZE / 2 + locs[3] < 0 || SIZE / 2 + locs[2] < 0)
				{
					std::cout << "ATTENTION! SIZE TOO SMALL!" << std::endl;
					return (1);
				}
				//save location of T in grid
				grid[SIZE / 2 + locs[3]][SIZE / 2 + locs[2]] = 1;
			}
		}
		//print grid and count visited locations
		for (int i = SIZE - 1; i >= 0; i--)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (grid[i][j] > 0)
				{
					std::cout << "#";
					count++;
				}
				else
					std::cout << ".";
			}
			std::cout << std::endl;
		}
		std::cout << "total visited: " << count << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
