#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void swap(unsigned long long* xp, unsigned long long* yp)
{
    unsigned long long temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(unsigned long long arr[], int n)
{
    unsigned long long i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(void)
{
	FILE	*stream;
	char	*line;
	size_t	len = 100;

	int	ymax = 55;

	int x = 0;
	int y = 0;
	int i = 0;

	char lastOpen[100];

	unsigned long long totalCount = 0;
	unsigned long long totalCounts[ymax];

	int j = 0;
	while (j < ymax)
	{
		totalCounts[j] = 0;
		j++;
	}

	stream = fopen("input3.txt", "r");
	y = 0;
	while (y < ymax)
	{
		getline(&line, &len, stream);
		printf("line: %s\n", line);
		x = 0;
		i = 0;
		totalCount = 0;
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
			x++;
		}
		while (i > 0)
		{
			totalCount *= 5;
			if (lastOpen[i - 1] == '(')
			{
				printf(")");
				totalCount += 1;
			}
			else if (lastOpen[i - 1] == '[')
			{
				printf("]");
				totalCount += 2;
			}
			else if (lastOpen[i - 1] == '{')
			{
				printf("}");
				totalCount += 3;
			}
			else if (lastOpen[i - 1] == '<')
			{
				printf(">");
				totalCount += 4;
			}
			i--;
		}
		totalCounts[y] = totalCount;
		printf("totalCount: %llu\n", totalCount);
		y++;
	}
	j = 0;
	printf("totalCounts before sorting: ");
	while (j < ymax)
	{
		printf("%llu ", totalCounts[j]);
		j++;
	}
	printf("\n");
	selectionSort(totalCounts, ymax);
	printf("totalCounts after sorting: ");
	j = 0;
	while (j < ymax)
	{
		printf("%llu ", totalCounts[j]);
		j++;
	}
	printf("\n");
	printf("middle one: %llu\n", totalCounts[ymax / 2]);
	fclose(stream);
	exit(0);
}
