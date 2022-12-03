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
	int		last = 0;
	int		current = 0;
	int		count = 0;

	len = 5;
	i = 0;
	stream = fopen("input2.txt", "r");
	while (i < 2000)
	{
		getline(&line, &len, stream);
		current = ft_atoi(line);
		if (last != NULL)
		{
			if (current > last)
				count++;
		}
		last = current;
		i++;
	}
	printf("%d", count);
	close(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
