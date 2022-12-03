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

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

    int count = 100;
    int lines = count * 5;
    int linelen = count * 5;
    int done[lines][linelen];
    int temp[lines][linelen];
    int dist[lines][linelen];

    int i;
    int j;
    int k;
    int t;
    int o;
    int p;

    o = 0;
    while (o < 5)
    {
        p = 0;
        while (p < 5)
        {
            stream = fopen("input2.txt", "r");
            i = 0;
            while (i < lines / 5)
            {
                j = 0;
                getline(&line, &len, stream);
                while (j < linelen / 5)
                {
                    dist[i + o * count][j + p * count] = line[j] - 48 + o + p;
                    if (dist[i + o * count][j + p * count] > 9)
                        dist[i + o * count][j + p * count] = (line[j] - 48 + o + p) % 9;
                    done[i + o * count][j + p * count] = 0;
                    temp[i + o * count][j + p * count] = 0;
                    j++;
                }
                i++;
            }
            fclose(stream);
            p++;
        }
        o++;
    }
    k = 0;
    temp[0][1] = dist[0][1];
    temp[1][0] = dist[1][0];
    int finish = 0;
    t = 1;
    while (finish != 1)
    {
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
                }
                temp[0][0] = 0;
                if (done[lines - 1][linelen - 1] > 0)
                    finish = 1;
                j++;
            }
            i++;
        }
        t++;
    }
    printf("shortest path: %d\n", done[lines - 1][linelen - 1]);  
}
