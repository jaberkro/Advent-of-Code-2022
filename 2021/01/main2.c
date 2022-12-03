#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF 50000

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\f' || c == '\v' || \
		c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	out;
	int	counter;

	sign = 1;
	out = 0;
	counter = 0;
	while (isspace(str[counter]))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			sign = -1;
		counter++;
	}
	while (ft_isdigit(str[counter]))
	{
		out = out * 10 + str[counter] - 48;
		counter++;
	}
	return (out * sign);
}

void	ft_read_line(void)
{
	FILE	*stream;
	char	*line;
	size_t	len;
	int		i;
	int		last[8];
	int		current = 0;
	int		count = 0;

	len = 5;
	i = 0;
	stream = fopen("input2.txt", "r");
	for (int j = 0; j < 8; j++)
	{
		last[j] = 0;
	}
	while (i < 2000)
	{
		getline(&line, &len, stream);
		current = ft_atoi(line);
		last[i % 8] = current;
		if (i >= 3)
		{
			if ((last[i % 8] + last[(i - 1) % 8] + last[(i - 2) % 8]) > \
			(last[(i - 1) % 8] + last[(i - 2) % 8] + last[(i - 3) % 8]))
				count++;
		}
		i++;
	}
	printf("%d", count);
	fclose(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
