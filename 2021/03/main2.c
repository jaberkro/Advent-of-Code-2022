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
    fptr1 = fopen("output.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", "output.txt");
        exit(0);
    }
  
    // Open another file for writing
    fptr2 = fopen("input3.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", "input3.txt");
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
  
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
	FILE	*output;
	char	*line;
	size_t	len;
	int		i;
	int		j = 0;
	int		count0;
	int		count1;
	int		lineCount;
	int 	total = 1000;

	len = 14;
	while (j < 13)
	{
		output = fopen("output.txt", "w");
		stream = fopen("input3.txt", "r");
		count0 = 0;
		count1 = 0;
		i = 0;
		lineCount = 0;
		while (i < total)
		{
			getline(&line, &len, stream);
			if (ft_strlen(line) < 2)
				break;
			printf("line: %s\n", line);
			if (line[j] == '1')
			{
				count1++;
				lineCount++;
			}
			else if (line[j] == '0' && line[j] != '\n')
			{
				count0++;
				lineCount++;
			}
			i++;
		}
		close(stream);
		printf("count0: %d, count1: %d linecount: %d\n", count0, count1, lineCount);
		stream = fopen("input3.txt", "r");
		i = 0;
		while (i < total)
		{
			getline(&line, &len, stream);
			if (count1 == count0 && line[j] == '1')
				fputs(line, output);
			else if (line[j] == '1' && count1 > count0)
				fputs(line, output);
			else if (line[j] == '0' && count0 > count1)
				fputs(line, output);
			i++;
		}
		total = lineCount;
		fclose(output);
		ft_copy_to_file();
		close(stream);
		if (lineCount == 1)
			break ;
		j++;
	}
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
