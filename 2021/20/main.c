#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	bin_to_dec(char *input)
{
	int j = 1;
	int x = strlen(input) - 1;
	int out = 0;

	while (x >= 0)
	{
		if (input[x] == '1')
			out += j;
		j *= 2;
		x--;
	}
	return (out);
}

int makedec(char a, char b, char c, char d, char e, char f, char g, char h, char l)
{
    char out[10];

    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = d;
    out[4] = e;
    out[5] = f;
    out[6] = g;
    out[7] = h;
    out[8] = l;
    out[9] = '\0';
    return (bin_to_dec(out));
}

void print_grid(int width, int height, int border, char input[height + border * 2][width + border * 2])
{
    //PRINT WHOLE GRID INCLUDING INFINITY
    int j;
    int i = 0;
    while (i < height + border * 2)
    {
        j = 0;
        while (j < width + border * 2)
        {
            printf("%c", input[i][j]);
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

    char onoff[513];

    int height = 100; // 5 for example, 100 for real input
    int width = 100;  // 5 for example, 100 for real input
    int border = 150; // 5 for example, 150 for real input

    char input[height + border * 2][width + border * 2];
    char output[height + border * 2][width + border * 2];

    int i;
    int j;
    int k;
    int total = 0;
	stream = fopen("input2.txt", "r");
	getline(&line, &len, stream);
    i = 0;
    while (i < 512)
    {
        onoff[i] = line[i];
        i++;
    }
    onoff[i] = '\0';
    i = 0;
    while (i < height + border * 2)
    {
        j = 0;
        while (j < width + border * 2)
        {
            input[i][j] = '0';
            output[i][j] = '0';
            j++;
        }
        i++;
    }
    i = 0;
    while (i < height)
    {
        getline(&line, &len, stream);
        j = 0;
        while (j < width)
        {
            input[border + i][border + j] = line[j];
            j++;
        }
        i++;
    }
    print_grid(width, height, border, input);

    //UPDATE GRID
    k = 0;
    while (k < 50)
    {
        i = 0;
        while (i < height + border * 2)
        {
            j = 0;
            while (j < width + border * 2)
            {
                if (i > 0 && j > 0 && i < height + border * 2 - 1 && j < width + border * 2 - 1)
                    output[i][j] = onoff[makedec(   input[i - 1][j - 1], input[i - 1][j],   input[i - 1][j + 1], \
                                                    input[i][j - 1],     input[i][j],       input[i][j + 1], \
                                                    input[i + 1][j - 1], input[i + 1][j],   input[i + 1][j + 1])];
                else
                    output[i][j] = onoff[output[i][j]];
                j++;
            }
            i++;
        }
        i = 0;
        while (i < height + border * 2)
        {
            j = 0;
            while (j < width + border * 2)
            {
                input[i][j] = output[i][j];
                j++;
            }
            i++;
        }
        k++;
        print_grid(width, height, border, input);
    }

    i = 0;
    while (i < height + border * 2 - 200)
    {
        j = 0;
        while (j < width + border * 2 - 200)
        {
            total += input[i + 100][j + 100] - 48;
            j++;
        }
        i++;
    }
    printf("total: %d\n", total);
}
