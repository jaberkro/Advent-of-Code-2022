#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void print_grid(int width, int height, int input[height][width])
{
    //PRINT WHOLE GRID INCLUDING INFINITY
    int j;
    int i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            printf("%d ", input[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
    printf("\n");
}


int find_lowest(int lines, int linelen, int temp[lines][linelen])
{
    int out = 1000;
    int i;
    int j;

    i = 0;
    while (i < lines)
    {
        j = 0;
        while (j < linelen)
        {
            if (temp[i][j] < out && temp[i][j] != 0)
            {
                out = temp[i][j];
                printf("temp: %d", temp[i][j]);
            }
            j++;
        }
        i++;
    }
    return (out);
}

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

    int lines = 100;
    int linelen = 100;
    int done[lines][linelen];
    int temp[lines][linelen];
    int dist[lines][linelen];

    int i;
    int j;
    int k;
    int t;
    stream = fopen("input2.txt", "r");

    i = 0;
    while (i < lines)
    {
        j = 0;
        getline(&line, &len, stream);
        while (j < linelen)
        {
            dist[i][j] = line[j] - 48;
            done[i][j] = 0;
            temp[i][j] = 0;
            j++;
        }
        i++;
    }

    k = 0;
    temp[0][1] = dist[0][1];
    temp[1][0] = dist[1][0];
    int finish = 0;
    while (finish != 1)
    {
        t = find_lowest(lines, linelen, temp);
        printf("t: %d\n", t);
        i = 0;
        while (i < lines)
        {
            j = 0;
            while (j < linelen)
            {
                if (i == 0 && j == 0)
                    temp[i][j] = 0;
                else if (temp[i][j] == t)
                {
                    if ((temp[i - 1][j] == 0 || temp[i - 1][j] > temp[i][j] + dist[i - 1][j]) && i != 0 && done[i - 1][j] == 0)
                        temp[i - 1][j] = temp[i][j] + dist[i - 1][j];
                    if ((temp[i + 1][j] == 0 || temp[i + 1][j] > temp[i][j] + dist[i + 1][j]) && i != lines - 1 && done[i + 1][j] == 0)
                        temp[i + 1][j] = temp[i][j] + dist[i + 1][j];
                    if ((temp[i][j - 1] == 0 || temp[i][j - 1] > temp[i][j] + dist[i][j - 1]) && j != 0 && done[i][j - 1] == 0) 
                        temp[i][j - 1] = temp[i][j] + dist[i][j - 1];
                    if ((temp[i][j + 1] == 0 || temp[i][j + 1] > temp[i][j] + dist[i][j + 1]) && j != linelen - 1 && done[i][j + 1] == 0)
                        temp[i][j + 1] = temp[i][j] + dist[i][j + 1];
                    done[i][j] = temp[i][j];
                    temp[i][j] = 0;
                    printf("i: %d j: %d\n", i, j);
                }
                temp[0][0] = 0;
                if (done[lines - 1][linelen - 1] > 0)
                    finish = 1;
                j++;
            }
            i++;
        }
        k++;
    }


    print_grid(linelen, lines, done);
    printf("shortest path: %d\n", done[lines - 1][linelen - 1]);   
}
