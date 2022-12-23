#include <iostream>
#include <fstream>
#include <string>

#define SIZE 300
#define STARTWIDTH 70
#define STARTHEIGHT 70

void	countMap(char elvesMap[SIZE][SIZE])
{
	int minX = SIZE;
	int maxX = 0;
	int minY = SIZE;
	int maxY = 0;
	int count = 0;

	//find rectangle
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (elvesMap[y][x] == '#')
			{
				if (x > maxX)
					maxX = x;
				if (x < minX)
					minX = x;
				if (y > maxY)
					maxY = y;
				if (y < minY)
					minY = y;
			}
		}
	}

	//count rectangle empty spots
	for (int y = minY; y <= maxY; y++)
	{
		for (int x = minX; x <= maxX; x++)
		{
			if (elvesMap[y][x] == '.')
				count++;
		}
	}
	std::cout << "count of empty spots in rectangle at round 10: " << count << std::endl;
}

int freeEast(char elvesMap[SIZE][SIZE], int x, int y)
{
	if (elvesMap[y - 1][x + 1] == '.' && elvesMap[y][x + 1] == '.' && elvesMap[y + 1][x + 1] == '.')
		return (1);
	return (0);
}

int freeWest(char elvesMap[SIZE][SIZE], int x, int y)
{
	if (elvesMap[y - 1][x - 1] == '.' && elvesMap[y][x - 1] == '.' && elvesMap[y + 1][x - 1] == '.')
		return (1);
	return (0);
}

int freeSouth(char elvesMap[SIZE][SIZE], int x, int y)
{
	if (elvesMap[y + 1][x - 1] == '.' && elvesMap[y + 1][x] == '.' && elvesMap[y + 1][x + 1] == '.')
		return (1);
	return (0);
}

int freeNorth(char elvesMap[SIZE][SIZE], int x, int y)
{
	if (elvesMap[y - 1][x - 1] == '.' && elvesMap[y - 1][x] == '.' && elvesMap[y - 1][x + 1] == '.')
		return (1);
	return (0);
}

int freeAround(char elvesMap[SIZE][SIZE], int x, int y)
{
	if (elvesMap[y - 1][x - 1] == '.' && elvesMap[y - 1][x] == '.' && elvesMap[y - 1][x + 1] == '.' && \
		elvesMap[y][x - 1] == '.' && elvesMap[y][x + 1] == '.' && \
		elvesMap[y + 1][x - 1] == '.' && elvesMap[y + 1][x] == '.' && elvesMap[y + 1][x + 1] == '.')
		return (1);
	return (0);
}

int	findDir(char elvesMap[SIZE][SIZE], int x, int y, int i)
{
	if (freeAround(elvesMap, x, y))
		return (0);
	if (i % 4 == 0)
	{
		if (freeNorth(elvesMap, x, y))
			return (1);
		if (freeSouth(elvesMap, x, y))
			return (2);
		if (freeWest(elvesMap, x, y))
			return (3);
		if (freeEast(elvesMap, x, y))
			return (4);
	} 
	else if (i % 4 == 1)
	{
		if (freeSouth(elvesMap, x, y))
			return (2);
		if (freeWest(elvesMap, x, y))
			return (3);
		if (freeEast(elvesMap, x, y))
			return (4);
		if (freeNorth(elvesMap, x, y))
			return (1);
	}
	else if (i % 4 == 2)
	{
		if (freeWest(elvesMap, x, y))
			return (3);
		if (freeEast(elvesMap, x, y))
			return (4);
		if (freeNorth(elvesMap, x, y))
			return (1);
		if (freeSouth(elvesMap, x, y))
			return (2);
	}
	else if (i % 4 == 3)
	{
		if (freeEast(elvesMap, x, y))
			return (4);
		if (freeNorth(elvesMap, x, y))
			return (1);
		if (freeSouth(elvesMap, x, y))
			return (2);
		if (freeWest(elvesMap, x, y))
			return (3);
	}
	return (0);
}

void	printMap(char printMap[SIZE][SIZE])
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			std::cout << printMap[y][x];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	std::ifstream myfile("input.txt");
	char	elvesMap[SIZE][SIZE] = {};
	char	newElvesMap[SIZE][SIZE] = {};
	int		proposeMap[SIZE][SIZE] = {};

	//fill maps empty
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			newElvesMap[i][j] = '.';
			elvesMap[i][j] = '.';
			proposeMap[i][j] = 0;
		}
	}

	//init elvesMap
	if (myfile.is_open())
	{
		std::string line;
		int y = SIZE / 2 - STARTHEIGHT / 2;
		while (getline (myfile,line))
		{
			for (unsigned long x = 0; x < line.size(); x++)
			{
				if (line.at(x) == '#')
				{
					elvesMap[y][SIZE / 2 - STARTWIDTH / 2 + x] = '#';
				}
				else
				{
					elvesMap[y][SIZE / 2 - STARTWIDTH / 2 + x] = '.';
				}
			}
			y++;			
		}
		myfile.close();
	}
  	else
		std::cout << "Unable to open file"; 

	printMap(elvesMap);
	for (int i = 0; i < 30000; i++)
	{
		int dir = 0;
		int	movedCount = 0;

		//propose steps
		for (int y = 0; y < SIZE; y++)
		{
			for (int x = 0; x < SIZE; x++)
			{
				if (elvesMap[y][x] == '#')
				{
					dir = findDir(elvesMap, x, y, i);
					if (dir == 1)
						proposeMap[y - 1][x]++;
					else if (dir == 2)
						proposeMap[y + 1][x]++;
					else if (dir == 3)
						proposeMap[y][x - 1]++;
					else if (dir == 4)
						proposeMap[y][x + 1]++;
				}
			}
		}

		//execute steps
		for (int y = 0; y < SIZE; y++)
		{
			for (int x = 0; x < SIZE; x++)
			{
				if (elvesMap[y][x] == '#')
				{
					dir = findDir(elvesMap, x, y, i);
					if (dir == 1 && proposeMap[y - 1][x] == 1)
					{
						newElvesMap[y - 1][x] = '#';
						movedCount++;
					}
					else if (dir == 2 && proposeMap[y + 1][x] == 1)
					{
						newElvesMap[y + 1][x] = '#';
						movedCount++;
					}
					else if (dir == 3 && proposeMap[y][x - 1] == 1)
					{
						newElvesMap[y][x - 1] = '#';
						movedCount++;
					}
					else if (dir == 4 && proposeMap[y][x + 1] == 1)
					{
						newElvesMap[y][x + 1] = '#';
						movedCount++;
					}
					else
						newElvesMap[y][x] = '#';
				}
			}
		}

		//copy newElvesMap to elvesMap
		for (int y = 0; y < SIZE; y++)
		{
			for (int x = 0; x < SIZE; x++)
			{
				elvesMap[y][x] = newElvesMap[y][x];
				proposeMap[y][x] = 0;
				newElvesMap[y][x] = '.';
			}
		}
		if (i == 9)
		{
			printMap(elvesMap);
			countMap(elvesMap);
		}
		if (movedCount == 0)
		{
			std::cout << "no moves after round: " << i + 1 << std::endl;
			return (0);
		}
	}
	return (0);
}
