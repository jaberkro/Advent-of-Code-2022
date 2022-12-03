#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    printf("starting!\n");
    FILE	*stream;
	char	*line;
	size_t	len = 100;
    int size = 250000;
    unsigned long long engine[250000 * 250000 * 250000];

    stream = fopen("input4.txt", "r");
    int i = 0;
    char **inputs;
    int x;
    int xmax;
    int y;
    int ymax;
    int z;
    int zmax;
    int light;
    unsigned long long totalcount = 0;
    printf("starting!\n");

    z = 0;
    while (z < size)
    {
        y = 0;
        while (y < size)
        {
            x = 0;
            while (x < size)
            {
                engine[z][y][x] = 0;
                x++;
            }
            y++;
        }
        z++;
    }
    while (i < 6)
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
                    engine[125000 + z][125000 + y][125000 + x] = light;
                    x++;
                }
                y++;
            }
            z++;
        }
        i++;
    }
    printf("done!\n");
    z = 0;
    while (z < size)
    {
        y = 0;
        while (y < size)
        {
            x = 0;
            while (x < size)
            {
                if (engine[z][y][x] == 1)
                    totalcount++;
                x++;
            }
            y++;
        }
        z++;
    }
    printf("totalcount: %llu\n", totalcount);
}
