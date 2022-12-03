#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF 50000

void 	ft_copy_to_file()
{
	FILE *fptr1, *fptr2;
    char filename[100], c;
  
    // Open one file for reading
    fptr1 = fopen("input.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", "input.txt");
        exit(0);
    }
  
    // Open another file for writing
    fptr2 = fopen("output.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", "output.txt");
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
  
    printf("\nContents copied to %s", "output.txt");
  
    fclose(fptr1);
    fclose(fptr2);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_read_line(void)
{
	FILE	*stream;
	char	*line;
	size_t	len;
	int		i;
	int		j = 0;
	int		count;
	char	gamma[13] = "------------\0";
	char	elipson[13] = "------------\0";

	len = 14;
	while (j < 12)
	{
		stream = fopen("input2.txt", "r");
		count = 0;
		i = 0;
		while (i < 1000)
		{
			getline(&line, &len, stream);
			if (line[j] == '1')
			{
				count++;
			}
			i++;
		}
		if (count > 500)
		{
			gamma[j] = '1';
			elipson[j] = '0';
		}
		else
		{
			gamma[j] = '0';
			elipson[j] = '1';
		}
		printf("gamma:   %s int: %d\nelipson: %s int: %d\ncount: %d\n", gamma, strtol(gamma, 0, 2), elipson, strtol(elipson, 0, 2), count);
		j++;
		close(stream);
		ft_copy_to_file();
	}
	printf("total: %d\n", strtol(gamma, 0, 2) * strtol(elipson, 0, 2));
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
