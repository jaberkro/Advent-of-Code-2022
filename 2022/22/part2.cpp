#include <iostream>
#include <fstream>
#include <string>
# include <vector>

#define HEIGHT 200 //12 //16
#define COMMANDS 1
#define CUBESIZE 50 //4

void	walkRight(std::vector<std::string> *map, int *posX, int *posY, int steps);
void	walkUp(std::vector<std::string> *map, int *posX, int *posY, int steps);
void	walkLeft(std::vector<std::string> *map, int *posX, int *posY, int steps);
void	walkDown(std::vector<std::string> *map, int *posX, int *posY, int steps);

void	changeDir(std::vector<std::string> *map, int *posX, int *posY, int dir)
{
	if (dir == 'R')
	{
		if ((*map).at(*posY).at(*posX) == '>')
			(*map).at(*posY).at(*posX) = 'v';
		else if ((*map).at(*posY).at(*posX) == 'v')
			(*map).at(*posY).at(*posX) = '<';
		else if ((*map).at(*posY).at(*posX) == '<')
			(*map).at(*posY).at(*posX) = '^';
		else if ((*map).at(*posY).at(*posX) == '^')
			(*map).at(*posY).at(*posX) = '>';
	}
	else
	{
		if ((*map).at(*posY).at(*posX) == '>')
			(*map).at(*posY).at(*posX) = '^';
		else if ((*map).at(*posY).at(*posX) == '^')
			(*map).at(*posY).at(*posX) = '<';
		else if ((*map).at(*posY).at(*posX) == '<')
			(*map).at(*posY).at(*posX) = 'v';
		else if ((*map).at(*posY).at(*posX) == 'v')
			(*map).at(*posY).at(*posX) = '>';
	}
}

int	findFirstVertical(std::vector<std::string> *map, int *posX)
{
	std::cout << "searching first vertical..." << std::endl;
	for (unsigned long i = 0; i < (*map).size(); i++)
	{
		if ((unsigned long)(*posX) < ((*map).at(i)).size() && ((*map).at(i).at(*posX) == '.' || (*map).at(i).at(*posX) == '#'))
			return (i);
	}
	std::cout << "not found!" << std::endl;
	return (0);
}

int	findLastVertical(std::vector<std::string> *map, int *posX)
{
	std::cout << "searching last vertical..." << std::endl;
	for (unsigned long i = HEIGHT - 1; i >= 0; i--)
	{
		if ((unsigned long)(*posX) < ((*map).at(i)).size() && ((*map).at(i).at(*posX) == '.' || (*map).at(i).at(*posX) == '#'))
			return (i);
	}
	std::cout << "not found!" << std::endl;
	return (0);
}

void	walkUp(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
	int	newPosX;
	int	newPosY;

	for (int k = 0; k < steps; k++)
	{
		if ((unsigned long)(*posY) > 0 && (unsigned long)(*posX) < (*map).at(*posY - 1).size() && (*map).at(*posY - 1).at(*posX) == '.')
		{
			(*map).at(*posY - 1).at(*posX) = '^';
			(*map).at(*posY).at(*posX) = '.';
			(*posY)--;
			std::cout << "normal up" << std::endl;
		}
		else if ((unsigned long)*posY > 0 && (unsigned long)(*posX) < (*map).at(*posY - 1).size() && (*map).at(*posY - 1).at(*posX) == '#')
			return ;
		else
		{
	
			if (*posX < CUBESIZE)
			{
				newPosX = CUBESIZE;
				newPosY = *posX + CUBESIZE;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '>';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkRight(map, posX, posY, steps - k - 1);
					k = steps;
				}
				else
					return ;
			}
			else if (*posX < CUBESIZE * 2)
			{
				newPosX = 0;
				newPosY = *posX + CUBESIZE * 2;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '>';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkRight(map, posX, posY, steps - k - 1);
					k = steps;
				}
				else
					return ;
			} 
			else
			{
				newPosX = *posX - CUBESIZE * 2;
				newPosY = CUBESIZE * 4 - 1;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '^';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
				}
				else
					return ;
			}		
		}
	}
}

void	walkLeft(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
	int	newPosX;
	int	newPosY;

	for (int l = 0; l < steps; l++)
	{
		if ((unsigned long)(*posX) > 0 && (*map).at(*posY).at(*posX - 1) == '.')
		{
			std::cout << "normal left" << std::endl;
			(*map).at(*posY).at(*posX - 1) = '<';
			(*map).at(*posY).at(*posX) = '.';
			(*posX)--;
		}
		else if ((unsigned long)(*posX) > 0 && (*map).at(*posY).at(*posX - 1) == '#')
			return ;
		else
		{
			if (*posY < CUBESIZE)
			{
				newPosX = 0;
				newPosY = CUBESIZE * 3 - 1 - *posY;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '>';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkRight(map, posX, posY, steps - l - 1);
					l = steps;
				}
				else
					return ;
			}
			else if (*posY < CUBESIZE * 2)
			{
				newPosX = *posY - CUBESIZE;
				newPosY = CUBESIZE * 2;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = 'v';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkDown(map, posX, posY, steps - l - 1);
					l = steps;
				}
				else
					return ;
			} 
			else if (*posY < CUBESIZE * 3)
			{
				newPosX = CUBESIZE;
				newPosY = CUBESIZE * 3 - 1 - *posY;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '>';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkRight(map, posX, posY, steps - l - 1);
					l = steps;
				}
				else
					return ;
			} 
			else
			{
				newPosX = *posY - CUBESIZE * 2;
				newPosY = 0;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = 'v';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkDown(map, posX, posY, steps - l - 1);
					l = steps;
				}
				else
					return ;
			}
		}
	}
}

void	walkDown(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
	int	newPosX;
	int	newPosY;

	for (int m = 0; m < steps; m++)
	{
		if ((unsigned long)(*posY) < (*map).size() - 1 && (unsigned long)(*posX) < (*map).at(*posY + 1).size() && (*map).at(*posY + 1).at(*posX) == '.')
		{
			(*map).at(*posY + 1).at(*posX) = 'v';
			(*map).at(*posY).at(*posX) = '.';
			(*posY)++;
		}
		else if ((unsigned long)(*posY) < (*map).size() - 1 && (unsigned long)(*posX) < (*map).at(*posY + 1).size() && (*map).at(*posY + 1).at(*posX) == '#')
		{
			return ;
		}
		else
		{
			if (*posX < CUBESIZE)
			{
				newPosX = *posX + CUBESIZE * 2;
				newPosY = 0;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					std::cout << "hi 4. at:[" << *posX << "," << *posY << "]";
					(*map).at(newPosY).at(newPosX) = 'v';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
				}
				else
					return ;
			}
			else if (*posX < CUBESIZE * 2)
			{
				newPosX = CUBESIZE - 1;
				newPosY = *posX + CUBESIZE * 2;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '<';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkLeft(map, posX, posY, steps - m - 1);
					m = steps;
				}
				else
					return ;
			} 
			else
			{
				newPosX = CUBESIZE * 2 - 1;
				newPosY = *posX - CUBESIZE;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '<';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkLeft(map, posX, posY, steps - m - 1);
					m = steps;
				}
				else
					return ;
			}
		}
	}
}

void	walkRight(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
	int	newPosX;
	int	newPosY;

	for (int n = 0; n < steps; n++)
	{
		if ((unsigned long)(*posX) < (*map).at(*posY).size() - 1 && (*map).at(*posY).at(*posX + 1) == '.')
		{
			(*map).at(*posY).at(*posX + 1) = '>';
			(*map).at(*posY).at(*posX) = '.';
			(*posX)++;
		}
		else if ((unsigned long)(*posX) < (*map).at(*posY).size() - 1 && (*map).at(*posY).at(*posX + 1) == '#')
			return ;
		else
		{
			if (*posY < CUBESIZE)
			{
				newPosX = CUBESIZE * 2 - 1;
				newPosY = CUBESIZE * 3 - 1 - *posY;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					std::cout << "hi 1. at:[" << *posX << "," << *posY << "]";
					(*map).at(newPosY).at(newPosX) = '<';
					(*map).at(*posY).at(*posX) = '.';
					std::cout << "	to:[" << newPosX << "," << newPosY << "]" << std::endl;
					*posX = newPosX;
					*posY = newPosY;
					walkLeft(map, posX, posY, steps - n - 1);
					n = steps;
				}
				else
					return ;
			}
			else if (*posY < CUBESIZE * 2)
			{
				newPosX = *posY + CUBESIZE;
				newPosY = CUBESIZE - 1;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					std::cout << "hi 2. at:[" << *posX << "," << *posY << "]";
					(*map).at(newPosY).at(newPosX) = '^';
					(*map).at(*posY).at(*posX) = '.';
					std::cout << "	to:[" << newPosX << "," << newPosY << "]" << std::endl;
					*posX = newPosX;
					*posY = newPosY;
					walkUp(map, posX, posY, steps - n - 1);
					n = steps;
				}
				else
					return ;
			} 
			else if (*posY < CUBESIZE * 3)
			{
				newPosX = CUBESIZE * 3 - 1;
				newPosY = CUBESIZE * 3 - 1 - *posY;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					std::cout << "hi 3. at:[" << *posX << "," << *posY << "]";
					(*map).at(newPosY).at(newPosX) = '<';
					(*map).at(*posY).at(*posX) = '.';
					std::cout << "	to:[" << newPosX << "," << newPosY << "]" << std::endl;
					*posX = newPosX;
					*posY = newPosY;
					walkLeft(map, posX, posY, steps - n - 1);
					n = steps;
				}
				else
					return ;
			} 
			else
			{
				newPosX = *posY - CUBESIZE * 2;
				newPosY = CUBESIZE * 3 - 1;
				if ((*map).at(newPosY).at(newPosX) == '.')
				{
					(*map).at(newPosY).at(newPosX) = '^';
					(*map).at(*posY).at(*posX) = '.';
					*posX = newPosX;
					*posY = newPosY;
					walkUp(map, posX, posY, steps - n - 1);
					n = steps;
				}
				else
					return ;
			}
		}
	}
}

int	findDir(std::vector<std::string> *map, int *posX, int *posY)
{
	if ((*map).at(*posY).at(*posX) == '>')
		return (0);
	else if ((*map).at(*posY).at(*posX) == 'v')
		return (1);
	else if ((*map).at(*posY).at(*posX) == '<')
		return (2);
	else if ((*map).at(*posY).at(*posX) == '^')
		return (3);
	std::cout << "could not find direction" << std::endl;
	return (-1);
}

void	setSteps(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
	int dir = findDir(map, posX, posY);
	// std::cout << "dir: " << dir << std::endl;
	if (dir == 0)
		walkRight(map, posX, posY, steps);
	if (dir == 1)
		walkDown(map, posX, posY, steps);
	if (dir == 2)
		walkLeft(map, posX, posY, steps);
	if (dir == 3)
		walkUp(map, posX, posY, steps);
}

void	parseMap(std::vector<std::string> *map, std::vector<std::string> *commands, int *posX)
{
	std::ifstream myfile("input.txt");
	std::string line;

	if (myfile.is_open())
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			getline(myfile, line);
			if (y == 0)
			{
				*posX = line.find(".");
				line.at(*posX) = '>';

			}
			map->push_back(line);		
		}
		getline(myfile, line);
		for (int y = 0; y < COMMANDS; y++)
		{
			getline(myfile, line);
			commands->push_back(line);
		}
		myfile.close();
	}
  	else
		std::cout << "Unable to open file"; 
}

void	printMap(std::vector<std::string> map)
{
	for (unsigned long i = 0; i < map.size(); i++)
	{
		std::cout << map.at(i) << std::endl;
	}
}

int main(void)
{
	std::vector<std::string> map;
	std::vector<std::string> commands;
	int	steps;
	int posX;
	int posY = 0;

	parseMap(&map, &commands, &posX);
	printMap(map);
	for (unsigned long j = 0; j < COMMANDS; j++)
	{
		for (unsigned long i = 0; i < commands.at(j).size(); i++)
		{
			if (isdigit(commands.at(j).at(i)))
			{
				steps = stoi(commands.at(j).substr(i, commands.at(j).find_first_of("LR", i)));
				i += commands.at(j).find_first_of("LR", i) - i - 1;
				std::cout << steps << std::endl;
				setSteps(&map, &posX, &posY, steps);
			}
			else
			{
				changeDir(&map, &posX, &posY, commands.at(j).at(i));
			}
		}
	}
	std::cout << "final password is: 1000 * " << posY + 1 << " + 4 * " << posX + 1 << " + " << findDir(&map, &posX, &posY) << " = " << 1000 * (posY + 1) + 4 * (posX + 1) + findDir(&map, &posX, &posY) << std::endl;
	return (0);
}
