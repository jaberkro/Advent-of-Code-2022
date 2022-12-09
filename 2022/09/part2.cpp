#include <iostream>
#include <fstream>
#include <string>

#define SIZE 400

int main(void)
{
	std::ifstream myfile("input.txt");
	std::string line;
	int	locs[20] = {};
	int	grid[SIZE][SIZE] = {};
	int	count = 0;

	grid[SIZE / 2 + locs[19]][SIZE / 2 + locs[18]] = 1;
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
				//update 1-9
				for (int j = 2; j < 20; j += 2)
				{
					if (abs(locs[j - 2] - locs[j]) >= 2)
					{
						locs[j] += (locs[j - 2] - locs[j]) / 2;
						if (locs[j - 1] - locs[j + 1] > 0)
							locs[j + 1] = (locs[j + 1] + 1);
						else if (locs[j - 1] - locs[j + 1] < 0)
							locs[j + 1] = (locs[j + 1] - 1);
					}
					else if (abs(locs[j - 1] - locs[j + 1]) >= 2 )
					{
						locs[j + 1] += (locs[j - 1] - locs[j + 1]) / 2;
						if (locs[j - 2] - locs[j] > 0)
							locs[j] = (locs[j] + 1);
						else if (locs[j - 2] - locs[j] < 0)
							locs[j] = (locs[j] - 1);
					}
					if (SIZE / 2 + locs[j + 1] >= SIZE || SIZE / 2 + locs[j] >= SIZE || \
						SIZE / 2 + locs[j + 1] < 0 || SIZE / 2 + locs[j] < 0)
					{
						std::cout << "ATTENTION! SIZE TOO SMALL!" << std::endl;
						return (1);
					}
				}
				//save location of 9 in grid
				grid[SIZE / 2 + locs[19]][SIZE / 2 + locs[18]] = 1;
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
