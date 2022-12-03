#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

    stream = fopen("input.txt", "r");
    int i = 0;
    char **inputs;
    int engine[100][100][100];
    int x;
    int xmax;
    int y;
    int ymax;
    int z;
    int zmax;
    int light;
    int totalcount = 0;
    z = 0;
    while (z < 100)
    {
        y = 0;
        while (y < 100)
        {
            x = 0;
            while (x < 100)
            {
                engine[z][y][x] = 0;
                x++;
            }
            y++;
        }
        z++;
    }

    while (i < 20)
    {
        getline(&line, &len, stream);
        inputs = ft_split(line, ',');
        light = ft_atoi(inputs[0]);
        xmax = ft_atoi(inputs[2]);
        ymax = ft_atoi(inputs[4]);
        zmax = ft_atoi(inputs[6]);
        z = ft_atoi(inputs[5]);
        while (z <= zmax)
        {
            y = ft_atoi(inputs[3]);
            while (y <= ymax)
            {
                x = ft_atoi(inputs[1]);
                while (x <= xmax)
                {
                    engine[50 + z][50 + y][50 + x] = light;
                    x++;
                }
                y++;
            }
            z++;
        }
        i++;
    }
    z = 0;
    while (z < 100)
    {
        y = 0;
        while (y < 100)
        {
            x = 0;
            while (x < 100)
            {
                if (engine[z][y][x] == 1)
                    totalcount++;
                x++;
            }
            y++;
        }
        z++;
    }



    printf("totalcount: %d\n", totalcount);
}
