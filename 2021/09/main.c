#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
	FILE	*stream;
	char	*line;
	size_t	len = 10;

	int xmax = 100;
	int	ymax = 100;

	int x = 0;
	int y = 0;

	int card[100][100];
	char *inputs;
	int	totalCount = 0;

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
			printf("%d ", card[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	fclose(stream);

	y = 0;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			if (x == 0 && y == 0)
			{
				if (card[y][x] < card[y][x + 1] && card[y][x] < card[y + 1][x])
					totalCount += card[y][x] + 1;
			}
			else if (x == 0 && y == ymax - 1)
			{
				if (card[y][x] < card[y][x + 1] && card[y][x] < card[y - 1][x])
					totalCount += card[y][x] + 1;
			}
			else if (x == xmax - 1 && y == 0)
			{
				if (card[y][x] < card[y][x - 1] && card[y][x] < card[y + 1][x])
					totalCount += (card[y][x] + 1);
			}
			else if (x == xmax - 1 && y == ymax - 1)
			{
				if (card[y][x] < card[y][x - 1] && card[y][x] < card[y - 1][x])
					totalCount += card[y][x] + 1;
			}
			else if (x == 0)
			{
				if (card[y][x] < card[y][x + 1] && card[y][x] < card[y + 1][x] && card[y][x] < card[y - 1][x])
					totalCount += (card[y][x] + 1);
			}
			else if (x == xmax - 1)
			{
				if (card[y][x] < card[y][x - 1] && card[y][x] < card[y + 1][x] && card[y][x] < card[y - 1][x])
					totalCount += (card[y][x] + 1);
			}
			else if (y == 0)
			{
				if (card[y][x] < card[y][x + 1] && card[y][x] < card[y][x - 1] && card[y][x] < card[y + 1][x])
					totalCount += (card[y][x] + 1);
			}
			else if (y == ymax - 1)
			{
				if (card[y][x] < card[y][x + 1] && card[y][x] < card[y][x - 1] && card[y][x] < card[y - 1][x])
					totalCount += (card[y][x] + 1);
			}
			else
			{
				if (card[y][x] < card[y][x + 1] && card[y][x] < card[y][x - 1] && card[y][x] < card[y - 1][x] && card[y][x] < card[y + 1][x])
					totalCount += (card[y][x] + 1);
			}
			x++;
		}
		y++;
	}
	printf("totalCount: %d", totalCount);
}
