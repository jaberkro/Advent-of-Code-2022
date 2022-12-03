#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

    int width = 139;
    int height = 137;
    int x;
    int y;
    int moved = 1;
    int count = 0;
    char input[height][width];
    char newinput[height][width];

    stream = fopen("input.txt", "r");

    //COPY TEXT TO INPUT
    y = 0;
    while (y < height)
    {
        x = 0;
        getline(&line, &len, stream);
        while (x < width)
        {
            input[y][x] = line[x];
            printf("%c", input[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
    printf("\n");      

    while (moved > 0)
    {
        moved = 0;
        count++;
        //FILL NEWINPUT WITH ......
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                newinput[y][x] = '.'; 
                x++;
            }                  
            y++;
        }

        //MOVE EAST
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                if (input[y][x] == '>' && input[y][x + 1] == '.' && x < width - 1)
                {
                    newinput[y][x + 1] = '>'; 
                    moved++;
                }
                else if (input[y][x] == '>' && input[y][0] == '.' && x == width - 1)
                {
                    newinput[y][0] = '>'; 
                    moved++;
                }
                else if (input[y][x] == '>')
                    newinput[y][x] = '>';
                else if (input[y][x] == 'v')
                    newinput[y][x] = 'v';
                x++;
            }
            y++;
        }

        //COPY NEWINPUT TO INPUT
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                input[y][x] = newinput[y][x];
                x++;
            }                  
            y++;
        }
        printf("moved to east: %d", moved);

        //FILL NEWINPUT WITH ......
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                newinput[y][x] = '.'; 
                x++;
            }                  
            y++;
        }

        //MOVE SOUTH
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                if (input[y][x] == 'v' && input[y + 1][x] == '.' && y < height - 1)
                {
                    newinput[y + 1][x] = 'v'; 
                    moved++;
                }
                else if (input[y][x] == 'v' && input[0][x] == '.' && y == height - 1)
                {
                    newinput[0][x] = 'v';
                    moved++;
                }
                else if (input[y][x] == 'v')
                    newinput[y][x] = 'v';
                else if (input[y][x] == '>')
                    newinput[y][x] = '>';
                x++;
            }
            y++;
        }

        //COPY NEWINPUT TO INPUT
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                input[y][x] = newinput[y][x];
                x++;
            }                  
            y++;
        }
        printf(", moved in total: %d\n", moved);
        //PRINT INPUT AFTER BOTH MOVEMENTS
        y = 0;
        while (y < height)
        {
            x = 0;
            while (x < width)
            {
                printf("%c", input[y][x]);
                x++;
            }   
            printf("\n");               
            y++;
        }
        printf("\n");               
    }
    printf("totalcount: %d\n", count);
}
