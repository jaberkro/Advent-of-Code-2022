#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define STARTWIDTH 400 // 490
#define WIDTH 200 //20
#define HEIGHT 200 //10

int	drawSand(std::vector<std::string> *map, int startX, int sandCount)
{
	for (unsigned long i = 0; i < (*map).size() - 1; i++)
	{
		if ((*map).at(i + 1).at(startX) == '.')
		{
			(*map).at(i).at(startX) = '.';
			(*map).at(i + 1).at(startX) = 'o';
		}
		else if ((*map).at(i + 1).at(startX - 1) == '.')
		{
			(*map).at(i).at(startX) = '.';
			(*map).at(i + 1).at(startX - 1) = 'o';
			startX--;
		}
		else if ((*map).at(i + 1).at(startX + 1) == '.')
		{
			(*map).at(i).at(startX) = '.';
			(*map).at(i + 1).at(startX + 1) = 'o';
			startX++;
		}
		else
		{
			return (1);
		}
	}
	std::cout << "done at sand nr: " << sandCount << std::endl;
	return (0);
}

void	fillSandMap(std::vector<std::string> *map)
{
	int	startX = 500 - STARTWIDTH;
	int sandCount = 0;

	while (1)
	{
		if (!drawSand(map, startX, sandCount))
			break ;
		sandCount++;
	}
}

void drawLine(std::vector<std::string> *map, int toX, int toY, int fromX, int fromY)
{
	std::cout << "drawing line" << std::endl;
	if (toX == fromX)
	{
		while (toY > fromY)
		{
			(*map).at(fromY).at(fromX - STARTWIDTH) = '#';
			fromY++;
		}
		while (toY < fromY)
		{
			(*map).at(toY).at(fromX - STARTWIDTH) = '#';
			toY++;
		}
		(*map).at(toY).at(fromX - STARTWIDTH) = '#';
	}
	else
	{
		while (toX > fromX)
		{
			(*map).at(fromY).at(fromX - STARTWIDTH) = '#';
			fromX++;
		}
		while (toX < fromX)
		{
			(*map).at(fromY).at(toX - STARTWIDTH) = '#';
			toX++;
		}
		(*map).at(fromY).at(toX - STARTWIDTH) = '#';
	}
}

void	parseMap(std::vector<std::string> *map)
{
	std::ifstream myfile("input.txt");
	std::string line;
	int toX;
	int toY;
	int len;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int	fromX = 0;
			int fromY = 0;
			unsigned long	i = 0;
			while (i < line.size())
			{
				len = line.find(',', i);
				toX = stoi(line.substr(i, len));
				i += len - i + 1;
				len = line.find(' ', i);
				if (len == -1)
				{
					toY = stoi(line.substr(i));
					std::cout << toX << "," << toY << "		i: " << i << std::endl;
					if (fromX > 0)
						drawLine(map, toX, toY, fromX, fromY);
					break ;
				}
				else
					toY = stoi(line.substr(i, len));
				i += len - i + 1;
				std::cout << toX << "," << toY << "		i: " << i << std::endl;
				i += 3;
				if (fromX > 0)
					drawLine(map, toX, toY, fromX, fromY);
				fromX = toX;
				fromY = toY;
			}
		}
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

void	emptyMap(std::vector<std::string> *map)
{
	std::string tmpString;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			tmpString.push_back('.');
		}
		(*map).push_back(tmpString);
		tmpString.clear();
	}
}

int main(void)
{
	std::vector<std::string> sandMap;

	emptyMap(&sandMap);	
	parseMap(&sandMap);
	printMap(sandMap);
	fillSandMap(&sandMap);
	printMap(sandMap);
	return (0);
}
