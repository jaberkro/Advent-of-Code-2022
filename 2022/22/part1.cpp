#include <iostream>
#include <fstream>
#include <string>
# include <vector>

#define HEIGHT 200 //12
#define COMMANDS 1

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
			if ((*map).at(findLastVertical(map, posX)).at(*posX) == '.')
			{
				std::cout << "up flipover" << std::endl;
				int newPosY = findLastVertical(map, posX);
				(*map).at(newPosY).at(*posX) = '^';
				(*map).at(*posY).at(*posX) = '.';
				*posY = newPosY;
			}			
			else
				return ;
		}
	}
}

void	walkLeft(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
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
			int endDot = (*map).at(*posY).find_last_of(".");
			int endHash = (*map).at(*posY).find_last_of("#");
			if (endDot > endHash)
			{
				std::cout << "left flipover" << std::endl;
				(*map).at(*posY).at(endDot) = '<';
				(*map).at(*posY).at(*posX) = '.';
				*posX = endDot;
			}
			else
				return ;
		}
	}
}

void	walkDown(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
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
			if ((*map).at(findFirstVertical(map, posX)).at(*posX) == '.')
			{
				int newPosY = findFirstVertical(map, posX);
				(*map).at(newPosY).at(*posX) = 'v';
				(*map).at(*posY).at(*posX) = '.';
				*posY = newPosY;
			}			
			else
			{
				return ;
			}
		}
	}
}

void	walkRight(std::vector<std::string> *map, int *posX, int *posY, int steps)
{
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
			int beginDot = (*map).at(*posY).find(".");
			int beginHash = (*map).at(*posY).find("#");
			if (beginDot < beginHash)
			{
				(*map).at(*posY).at(beginDot) = '>';
				(*map).at(*posY).at(*posX) = '.';
				*posX = beginDot;
			}
			else
				return ;
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
