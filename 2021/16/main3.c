#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

unsigned long long	bin_to_dec(char *input)
{
	unsigned long long j = 1;
	int x = strlen(input) - 1;
	unsigned long long out = 0;

	while (x >= 0)
	{
		if (input[x] == '1')
			out += j;
		j *= 2;
		x--;
	}
	return (out);
}

unsigned long long make_number(char *binline, int *x)
{
	char input[800000];
	int	count = 0;
    unsigned long long result = 0;

	input[0] = '\0';
	while (binline[*x] != '0')
	{
		(*x) += 1;
		strncat(input, &binline[*x], 4);
		(*x) += 4;
		count += 5;
	}
	(*x) += 1;
	strncat(input, &binline[*x], 4);
	(*x) += 4;
	count += 5;
	input[count] = '\0';
	if (input[0] != '\0')
		result = bin_to_dec(input);
	else
		printf("TRYING TO MAKE A DEC FROM NOTHING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("result make_number: %llu\n", result);
	return (result);
}

unsigned long long len_checker(char *binline, int x, int len)
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

unsigned long long type_checker(char *binline, int i)
{
	char	output[4];
	output[0] = binline[i];
	output[1] = binline[i + 1];
	output[2] = binline[i + 2];
	output[3] = '\0';
	return (bin_to_dec(output));
}

unsigned long long version_checker(char *binline, int i)
{
	char	output[4];
	output[0] = binline[i];
	output[1] = binline[i + 1];
	output[2] = binline[i + 2];
	output[3] = '\0';
	return (bin_to_dec(output));
}

unsigned long long go_through_input(char *binline, int *x)
{
    int t = 0;
    int i = 0;
    unsigned long long start;
    unsigned long long tmp = 0;
    unsigned long long tmp2 = 0;
    unsigned long long len = 0;
    unsigned long long sub = 0;
    unsigned long long result = 0;

    (*x) += 3;
	t = type_checker(binline, *x);
	(*x) += 3;
    if (t == 4)
        return(make_number(binline, x));
    i = binline[*x] - 48;
    (*x)++;
    if (i == 0)
    {
        len = len_checker(binline, (*x), 15);
        *x += 15;
        start = *x;
    }
    else
    {
        sub = len_checker(binline, (*x), 11);
        *x += 11;
        start = *x;
    }
    if (result == 0 && t == 1)
        result = 1;
    while ((i == 0 && *x - start < len) || (i == 1 && sub > 0 && *x < (int)strlen(binline)))
    {
        if (t == 0)
        {
            printf("plus %llu\n", result);
            result += go_through_input(binline, x);
        }
        else if (t == 1)
        {
            result *= go_through_input(binline, x);
            printf("product %llu\n", result);
        }
        else if (t == 2)
        {
            tmp = go_through_input(binline, x);
            if (result == 0 || tmp < result)
                result = tmp;
            printf("minimal %llu\n", result);
        }
        else if (t == 3)
        {
            tmp = go_through_input(binline, x);
            if (result == 0 || tmp > result)
                result = tmp;
            printf("maximal %llu\n", result);
        }
        else if (t == 5)
        {
            tmp = go_through_input(binline, x);
            tmp2 = go_through_input(binline, x);
            printf("greater than tmp: %llu, tmp2: %llu\n", tmp, tmp2);
            return (tmp > tmp2);
        }
        else if (t == 6)
        {
            tmp = go_through_input(binline, x);
            tmp2 = go_through_input(binline, x);
            printf("smaller than tmp: %llu, tmp2: %llu\n", tmp, tmp2);
            return (tmp < tmp2);
        }
        else if (t == 7)
        {
            tmp = go_through_input(binline, x);
            tmp2 = go_through_input(binline, x);
            printf("equal to tmp: %llu, tmp2: %llu\n", tmp, tmp2);
            return (tmp == tmp2);
        }
        sub--;
    }
    return (result);
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
	unsigned long long 	output = 0;
	int 	x = 0;

	stream = fopen("input.txt", "r");
	getline(&line, &len, stream);
	char	*binline = hex_to_bin(line);
	printf("binline: %s\n", binline);
	output = go_through_input(binline, &x);
	printf("output: %llu x: %d\n", output, x);
	return (0);
}
