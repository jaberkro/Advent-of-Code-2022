#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int count(char map[900][1350], int width, int height)
{
	int m = 0;
	int n;
	int count = 0;
	while (m < height)
	{
		n = 0;
		while (n < width)
		{
			if (map[m][n] == '#')
				count++;
			n++;
		}
		m++;
	}
	printf("count: %d \n", count);
	return (count);
}

int main(void)
{
	FILE	*stream;
	char	*line;
	size_t	len = 100;

	int i = 0;
	int j;
	int k;

	char **xy;

	int width = 1350;
	int height = 900;
	int foldy = 0;
	int foldx = 0;
	char map[height][width];
	int counter = 0;
	
	stream = fopen("input2.txt", "r");
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			map[j][k] = '.';
			k++;
		}
		j++;
	}
	while (i < 715)
	{
		getline(&line, &len, stream);
		xy = ft_split(line, ',');
		map[atoi(xy[1])][atoi(xy[0])] = '#';
		i++;
	}
	// //PRINT
	// j = 0;
	// while (j < height)
	// {
	// 	k = 0;
	// 	while (k < width)
	// 	{
	// 		printf("%c ", map[j][k]);
	// 		k++;
	// 	}
	// 	printf("\n");
	// 	j++;
	// }
	count(map, width, height);

	//VERTICAL FOLD ON LiNE 655 X
	foldx = 655;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (k > foldx && map[j][k] == '#')
			{
				map[j][k - 2 * (k - foldx)] = '#';
			}
			if (k >= foldx)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE 447 Y
	foldy = 447;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//VERTICAL FOLD ON LiNE X = 327
	foldx = 327;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (k > foldx && map[j][k] == '#')
			{
				map[j][k - 2 * (k - foldx)] = '#';
			}
			if (k >= foldx)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE Y = 223
	foldy = 223;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//VERTICAL FOLD ON LiNE X = 163
	foldx = 163;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (k > foldx && map[j][k] == '#')
			{
				map[j][k - 2 * (k - foldx)] = '#';
			}
			if (k >= foldx)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE Y = 111
	foldy = 111;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//VERTICAL FOLD ON LiNE X = 81
	foldx = 81;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (k > foldx && map[j][k] == '#')
			{
				map[j][k - 2 * (k - foldx)] = '#';
			}
			if (k >= foldx)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE Y = 55
	foldy = 55;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//VERTICAL FOLD ON LiNE X = 40
	foldx = 40;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (k > foldx && map[j][k] == '#')
			{
				map[j][k - 2 * (k - foldx)] = '#';
			}
			if (k >= foldx)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE Y = 27
	foldy = 27;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE Y = 13
	foldy = 13;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//HORIZONTAL FOLD ON LiNE Y = 6
	foldy = 6;
	j = 0;
	while (j < height)
	{
		k = 0;
		while (k < width)
		{
			if (j > foldy && map[j][k] == '#')
			{
				map[j - 2 * (j - foldy)][k] = '#';
			}
			if (j >= foldy)
				map[j][k] = 'x';
			k++;
		}
		j++;
	}
	count(map, width, height);
	//PRINT 
	printf("\n\n\n");
	j = 0;
	while (j < 10)
	{
		k = 0;
		while (k < 45)
		{
			printf("%c ", map[j][k]);
			k++;
		}
		printf("\n");
		j++;
	}
	exit(0);

}
