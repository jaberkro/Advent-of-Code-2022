#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	ft_filledfully(int basinplotter[100][100])
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (basinplotter[i][j] == 1)
				return (0);
		}
	}
	return (1);
}

int main(void)
{
	FILE	*stream;
	char	*line;
	size_t	len = 10;

	int xmax = 100;
	int	ymax = 100;

	int x = 0;
	int y = 0;
	int bx;
	int by;

	int card[ymax][xmax];
	int	basinplotter[ymax][xmax];
	char *inputs;
	int	totalCount = 0;

	int top1 = 0;
	int top2 = 0;
	int top3 = 0;
	int basincount = 0;

	stream = fopen("input2.txt", "r");
	y = 0;
	while (y < ymax)
	{
		getline(&line, &len, stream);
		inputs = line;
		x = 0;
		while (x < xmax)
		{
			card[y][x] = inputs[x] - 48;
			x++;
		}
		y++;
	}
	fclose(stream);

	
	y = 0;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			for (int i = 0; i < ymax; i++)
			{
				for (int j = 0; j < xmax; j++)
				{
					basinplotter[i][j] = 0;
				}
			}
			if (card[y][x] != 9)
			{
				basinplotter[y][x] = 1;
				while (!ft_filledfully(basinplotter))
				{
					for (int i = 0; i < ymax; i++)
					{
						for (int j = 0; j < ymax; j++)
						{
							if (basinplotter[i][j] == 1)
							{
								if (i == 0 && j == 0)
								{
									if (card[i][j + 1] == 9)
										basinplotter[i][j + 1] = -1;
									else if (basinplotter[i][j + 1] != 2)
										basinplotter[i][j + 1] = 1;
									if (card[i + 1][j] == 9)
										basinplotter[i + 1][j] = -1;
									else if (basinplotter[i + 1][j] != 2)
										basinplotter[i + 1][j] = 1;
								}
								else if (i == 0 && j == xmax - 1)
								{
									if (card[i + 1][j] == 9)
										basinplotter[i + 1][j] = -1;
									else if (basinplotter[i + 1][j] != 2)
										basinplotter[i + 1][j] = 1;
									if (card[i][j - 1] == 9)
										basinplotter[i][j - 1] = -1;
									else if (basinplotter[i][j - 1] != 2)
										basinplotter[i][j - 1] = 1;
								}
								else if (i == ymax - 1 && j == 0)
								{
									if (card[i - 1][j] == 9)
										basinplotter[i - 1][j] = -1;
									else if (basinplotter[i - 1][j] != 2)
										basinplotter[i - 1][j] = 1;
									if (card[i][j + 1] == 9)
										basinplotter[i][j + 1] = -1;
									else if (basinplotter[i][j + 1] != 2)
										basinplotter[i][j + 1] = 1;
								}
								else if (i == ymax - 1 && j == xmax - 1)
								{
									if (card[i - 1][j] == 9)
										basinplotter[i - 1][j] = -1;
									else if (basinplotter[i - 1][j] != 2)
										basinplotter[i - 1][j] = 1;
									if (card[i][j - 1] == 9)
										basinplotter[i][j - 1] = -1;
									else if (basinplotter[i][j - 1] != 2)
										basinplotter[i][j - 1] = 1;
								}
								else if (i == 0)
								{
									if (card[i][j - 1] == 9)
										basinplotter[i][j - 1] = -1;
									else if (basinplotter[i][j - 1] != 2)
										basinplotter[i][j - 1] = 1;
									if (card[i][j + 1] == 9)
										basinplotter[i][j + 1] = -1;
									else if (basinplotter[i][j + 1] != 2)
										basinplotter[i][j + 1] = 1;
									if (card[i + 1][j] == 9)
										basinplotter[i + 1][j] = -1;
									else if (basinplotter[i + 1][j] != 2)
										basinplotter[i + 1][j] = 1;
								}
								else if (i == ymax - 1)
								{
									if (card[i][j - 1] == 9)
										basinplotter[i][j - 1] = -1;
									else if (basinplotter[i][j - 1] != 2)
										basinplotter[i][j - 1] = 1;
									if (card[i][j + 1] == 9)
										basinplotter[i][j + 1] = -1;
									else if (basinplotter[i][j + 1] != 2)
										basinplotter[i][j + 1] = 1;
									if (card[i - 1][j] == 9)
										basinplotter[i - 1][j] = -1;
									else if (basinplotter[i - 1][j] != 2)
										basinplotter[i - 1][j] = 1;
								}
								else if (j == 0)
								{
									if (card[i + 1][j] == 9)
										basinplotter[i + 1][j] = -1;
									else if (basinplotter[i + 1][j] != 2)
										basinplotter[i + 1][j] = 1;
									if (card[i - 1][j] == 9)
										basinplotter[i - 1][j] = -1;
									else if (basinplotter[i - 1][j] != 2)
										basinplotter[i - 1][j] = 1;
									if (card[i][j + 1] == 9)
										basinplotter[i][j + 1] = -1;
									else if (basinplotter[i][j + 1] != 2)
										basinplotter[i][j + 1] = 1;
								}
								else if (j == xmax - 1)
								{
									if (card[i + 1][j] == 9)
										basinplotter[i + 1][j] = -1;
									else if (basinplotter[i + 1][j] != 2)
										basinplotter[i + 1][j] = 1;
									if (card[i - 1][j] == 9)
										basinplotter[i - 1][j] = -1;
									else if (basinplotter[i - 1][j] != 2)
										basinplotter[i - 1][j] = 1;
									if (card[i][j - 1] == 9)
										basinplotter[i][j - 1] = -1;
									else if (basinplotter[i][j - 1] != 2)
										basinplotter[i][j - 1] = 1;
								}
								else
								{
									if (card[i][j - 1] == 9)
										basinplotter[i][j - 1] = -1;
									else if (basinplotter[i][j - 1] != 2)
										basinplotter[i][j - 1] = 1;
									if (card[i][j + 1] == 9)
										basinplotter[i][j + 1] = -1;
									else if (basinplotter[i][j + 1] != 2)
										basinplotter[i][j + 1] = 1;
									if (card[i - 1][j] == 9)
										basinplotter[i - 1][j] = -1;
									else if (basinplotter[i - 1][j] != 2)
										basinplotter[i - 1][j] = 1;
									if (card[i + 1][j] == 9)
										basinplotter[i + 1][j] = -1;
									else if (basinplotter[i + 1][j] != 2)
										basinplotter[i + 1][j] = 1;
								}
								basinplotter[i][j] = 2;
							}
						}
					}	
				}
				basincount = 0;
				for (int i = 0; i < ymax; i++)
				{
					for (int j = 0; j < xmax; j++)
					{
						if (basinplotter[i][j] == 2)
							basincount += 1;
					}
				}
				printf("basincount: %d\n", basincount);
				if (basincount > top1)
				{
					top3 = top2;
					top2 = top1;
					top1 = basincount;
					printf("1! highest basincounts: %d %d %d\n", top1, top2, top3);
				}
				else if (basincount > top2 && basincount != top1)
				{
					top3 = top2;
					top2 = basincount;
					printf("2! highest basincounts: %d %d %d\n", top1, top2, top3);
				}
				else if (basincount > top3 && basincount != top2 && basincount != top1)
				{
					top3 = basincount;
					printf("3! highest basincounts: %d %d %d\n", top1, top2, top3);
				}
			}
			x++;
		}
		y++;
	}
	printf("highest basincounts: %d %d %d\n", top1, top2, top3);
}
