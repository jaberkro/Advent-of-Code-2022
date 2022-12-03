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
int len_checker(char *binline, int x, int len)
{
	char *todec = malloc(len + 1);
	todec[0] = '\0';
	strlcpy(todec, binline + x, len + 1);
	return (bin_to_dec(todec));
}

int id_checker(char *binline, int i)
{
	return (binline[i]);
}

int type_checker(char *binline, int i)
{
	char	output[4];
	output[0] = binline[i];
	output[1] = binline[i + 1];
	output[2] = binline[i + 2];
	output[3] = '\0';
	return (bin_to_dec(output));
}

int version_checker(char *binline, int i)
{
	char	output[4];
	output[0] = binline[i];
	output[1] = binline[i + 1];
	output[2] = binline[i + 2];
	output[3] = '\0';
	return (bin_to_dec(output));
}

int go_through_input(char *binline, int *x)
{
	int v = 0;
	int t = 0;
	int i = 0;
	int len = 0;
	int totlen = 0;
	int subpack = 0;
	int orx = 0;
	v += version_checker(binline, *x);
	(*x) += 3;
	t = type_checker(binline, *x);
	printf("v: %d t: %d x: %d\n", v, t, *x);
	(*x) += 3;
	if (t != 4)
	{
		printf("operator! x right now: %d\n", *x);
		(*x)++;
		if (binline[(*x) - 1] == '0')
		{
			len = 15;
			totlen = len_checker(binline, (*x), len);
			printf("totlen: %d\n", totlen);
			(*x) += 15;
			orx = *x;
			while ((*x) - orx < totlen)
			{
				v += go_through_input(binline, x);
			}
			return (v);
		}
		else
		{
			len = 11;
			subpack = len_checker(binline, (*x), len);
			printf("amount of subpacks: %d\n", subpack);
			(*x) += 11;
			while (subpack > 0 && *x < strlen(binline))
			{
				v += go_through_input(binline, x);
				subpack--;
				if (subpack == 0)
					break ;
			}
			return (v);
		}
		
	}
	else if (t == 4)
	{
		while (binline[*x] != '0')
		{
			printf("magic happens\n");
			(*x) += 5;
		}
		(*x) += 5;
		return (v);
	}
	printf("v: %d t: %d x: %d\n", v, t, *x);
	return (v);
}


char	*hex_to_bin(char *line)
{
	int i = 0;
	char *binline = malloc(4 * strlen(line) + 1);
	binline[0] = '\0';
	while (line[i] != '\n')
	{
		if (line[i] == '0')
			strcat(binline, "0000");
		else if (line[i] == '1')
			strcat(binline, "0001");
		else if (line[i] == '2')
			strcat(binline, "0010");
		else if (line[i] == '3')
			strcat(binline, "0011");
		else if (line[i] == '4')
			strcat(binline, "0100");
		else if (line[i] == '5')
			strcat(binline, "0101");
		else if (line[i] == '6')
			strcat(binline, "0110");
		else if (line[i] == '7')
			strcat(binline, "0111");
		else if (line[i] == '8')
			strcat(binline, "1000");
		else if (line[i] == '9')
			strcat(binline, "1001");
		else if (line[i] == 'A')
			strcat(binline, "1010");
		else if (line[i] == 'B')
			strcat(binline, "1011");
		else if (line[i] == 'C')
			strcat(binline, "1100");
		else if (line[i] == 'D')
			strcat(binline, "1101");
		else if (line[i] == 'E')
			strcat(binline, "1110");
		else if (line[i] == 'F')
			strcat(binline, "1111");
		i++;
	}
	return (binline);
}

int main(void)
{
	FILE	*stream;
	char	*line;
	size_t	len = 100;
	int 	output = 0;
	int 	x = 0;

	stream = fopen("input.txt", "r");
	getline(&line, &len, stream);
	char	*binline = hex_to_bin(line);
	printf("binline: %s\n", binline);
	output = go_through_input(binline, &x);
	printf("output: %d x: %d\n", output, x);
	return (0);
}

// type checken
// if type = 0 --> '+' meesturen in recursion
// if type = 1 --> '*' meesturen in recursion
// if type = 2 --> 'l' meesturen in recursion
// if type = 3 --> 'h' meesturen in recursion
// if type = 5 --> '>' meesturen in recursion
// if type = 6 --> '<' meesturen in recursion
// if type = 7 --> '=' meesturen in recursion

// if type = 4 --> som uitvoeren, resultaat terugsturen