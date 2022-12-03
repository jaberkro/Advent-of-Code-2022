#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	FILE	*stream;
	char	*line;
	size_t	len = 100;

	int	ymax = 110;

	int x = 0;
	int y = 0;
	int i = 0;

	char lastOpen[100];

	int	totalCount = 0;

	stream = fopen("input2.txt", "r");
	y = 0;
	printf("After round %d the totalCount is: %d\n", y, totalCount);
	while (y < ymax)
	{
		getline(&line, &len, stream);
		printf("line: %s\n", line);
		x = 0;
		i = 0;
		while (line[x] != '\n')
		{
			if (line[x] == '(' || line[x] == '[' || line[x] == '{' || line[x] == '<')
			{
				lastOpen[i] = line[x];
				i++;
			}
			else if ((lastOpen[i - 1] == '(' && line[x] == ')') || (lastOpen[i - 1] == '[' && line[x] == ']') || \
					(lastOpen[i - 1] == '{' && line[x] == '}') || (lastOpen[i - 1] == '<' && line[x] == '>'))
			{
				i--;
			}
			else if (line[x] == ')')
			{
				totalCount += 3;
				printf("problem: %c\n", line[x]);
				break ;
			}
			else if (line[x] == ']')
			{
				totalCount += 57;
				printf("problem: %c\n", line[x]);
				break ;
			}
			else if (line[x] == '}')
			{
				totalCount += 1197;
				printf("problem: %c\n", line[x]);
				break ;
			}
			else if (line[x] == '>')
			{
				totalCount += 25137;
				printf("problem: %c\n", line[x]);
				break ;
			}
			x++;
		}
		printf("After line %d the totalCount is: %d\n", y + 1, totalCount);
		y++;
	}
	 fclose(stream);
	 exit(0);
}
