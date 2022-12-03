#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int explode_done(char energy[10][10])
{
    int a = 0;
    int b;

    while (a < 10)
    {
        b = 0;
        while (b < 10)
        {
            if (energy[a][b] > '9')
                return (0);
            b++;
        }
        a++;
    }
    return (1);
}

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

	int	ymax = 10;
    int xmax = 10;

	int x = 0;
	int y = 0;
	int i = 0;

	char energy[10][10];

	unsigned long long totalCount = 0;

	stream = fopen("input2.txt", "r");
	y = 0;
	while (y < ymax)
	{
		getline(&line, &len, stream);
		x = 0;
		while (x < xmax)
		{
			energy[y][x] = line[x];
			x++;
		}
        y++;
    }
    while (i < 100)
    {
        y = 0;
        while (y < ymax)
	    {
            x = 0;
            while (x < xmax)
            {
                energy[y][x]++;
                x++;
            }
            y++;
        }
        while (!explode_done(energy))
        {
            y = 0;
            while (y < ymax)
            {
                x = 0;
                while (x < xmax)
                {
                    if (energy[y][x] > '9')
                    {
                        energy[y][x] = '#';
                        if (x == 0 && y == 0)
                        {
                            energy[y + 1][x]++;
                            energy[y][x + 1]++;
                            energy[y + 1][x + 1]++;
                        }
                        else if (x == 0 && y == ymax - 1)
                        {
                            energy[y - 1][x]++;
                            energy[y][x + 1]++;
                            energy[y - 1][x + 1]++;
                        }
                        else if (x == xmax - 1 && y == 0)
                        {
                            energy[y + 1][x]++;
                            energy[y][x - 1]++;
                            energy[y + 1][x - 1]++;
                        }
                        else if (x == xmax - 1 && y == ymax - 1)
                        {
                            energy[y - 1][x]++;
                            energy[y][x - 1]++;
                            energy[y - 1][x - 1]++;
                        }
                        else if (x == 0)
                        {
                            energy[y - 1][x]++;
                            energy[y - 1][x + 1]++;
                            energy[y][x + 1]++;
                            energy[y + 1][x + 1]++;
                            energy[y + 1][x]++;
                        }
                        else if (x == xmax - 1)
                        {
                            energy[y - 1][x]++;
                            energy[y - 1][x - 1]++;
                            energy[y][x - 1]++;
                            energy[y + 1][x - 1]++;
                            energy[y + 1][x]++;
                        }
                        else if (y == 0)
                        {
                            energy[y][x + 1]++;
                            energy[y + 1][x + 1]++;
                            energy[y + 1][x]++;
                            energy[y + 1][x - 1]++;
                            energy[y][x - 1]++;
                        }
                        else if (y == ymax - 1)
                        {
                            energy[y][x + 1]++;
                            energy[y - 1][x + 1]++;
                            energy[y - 1][x]++;
                            energy[y - 1][x - 1]++;
                            energy[y][x - 1]++;
                        }
                        else
                        {
                            energy[y][x + 1]++;
                            energy[y][x - 1]++;
                            energy[y - 1][x]++;
                            energy[y - 1][x + 1]++;
                            energy[y - 1][x - 1]++;
                            energy[y + 1][x]++;
                            energy[y + 1][x + 1]++;
                            energy[y + 1][x - 1]++;
                        }
                        

                    }
                    x++;
                }
                y++;
            }
        }
        y = 0;
        while (y < ymax)
	    {
            x = 0;
            while (x < xmax)
            {
                if (energy[y][x] < '0')
                {
                    energy[y][x] = '0';
                    totalCount++;
                }
                x++;
            }
            y++;
        }
        printf("totalCount after round %llu: %d\n", i + 1, totalCount);
        i++;

    }
    fclose(stream);
    exit(0);
}
