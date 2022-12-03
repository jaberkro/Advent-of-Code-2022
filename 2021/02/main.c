#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF 50000

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}

void	ft_read_line(void)
{
	FILE	*stream;
	char	*line;
	size_t	len;
	int		i;
	int		x = 0;
	int		y = 0;

	len = 5;
	i = 0;
	stream = fopen("input2.txt", "r");
	while (i < 1000)
	{
		getline(&line, &len, stream);
		if (line[0] == 'f')
		{
			x += line[ft_strlen(line) - 2] - 48;
		}
		else if (line[0] == 'd')
			y += line[ft_strlen(line) - 2] - 48;
		else if (line[0] == 'u')
			y -= line[ft_strlen(line) - 2] - 48;
		i++;
	}
	printf("Result: x: %d, y: %d\n", x, y);
	close(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
