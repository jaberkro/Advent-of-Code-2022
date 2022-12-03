#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	len;

	counter = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (counter < dstsize - 1 && src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (dstsize != 0)
		dst[counter] = '\0';
	return (len);
}


static char	**free_all(char **out, int wcounter)
{
	int	counter;

	counter = 0;
	while (counter < wcounter)
	{
		free(out[counter]);
		counter++;
	}
	free(out);
	return (NULL);
}

static char	**out_filler(char const *s, char c, char **out)
{
	int	wcounter;
	int	last;
	int	wordlen;

	last = 0;
	wcounter = 0;
	while (*s != '\0')
	{
		if (*s != c && *s)
		{
			wordlen = 0;
			while (s[wordlen] != c && s[wordlen] != '\0')
				wordlen++;
			out[wcounter] = malloc(wordlen + 1);
			if (out[wcounter] == NULL)
				return (free_all(out, wcounter));
			ft_strlcpy(out[wcounter], s, wordlen + 1);
			wcounter++;
			s += wordlen;
			if (!*s)
				break ;
		}
		s++;
	}
	return (out);
}

static int	count_words(char const *s, char c)
{
	int	words;
	int	last;

	words = 0;
	last = 0;
	while (*s)
	{
		if (*s != c && last == 0)
		{
			last = 1;
			words++;
		}
		if (*s == c)
			last = 0;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**out;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	out = calloc(words + 1, sizeof(char *));
	if (out == NULL)
		return (NULL);
	return (out_filler(s, c, out));
}

int arrlen(int inputNums[1000])
{
	int i = 0;
	while (inputNums[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_read_line(void)
{
	FILE	*stream;
	char	*line;
	size_t	len;

	char	**inputs;
	int		inputNums[1000];
	unsigned long long countedNums[2000];

	
	int i;
	int j;
	unsigned long long		loc = 0;
	unsigned long long		fuel = 0;
	unsigned long long		bestfuel = 100000000;
	unsigned long long	 	bestloc = 0;
	
	len = 4;

	//READ INPUT, CONVERT TO INT AND LOAD IT INTO AN ARRAY CALLED INPUTNUMS
	stream = fopen("input2.txt", "r");
	getline(&line, &len, stream);
	inputs = ft_split(line, ',');

	i = 0;
	while (i < 2000)
	{
		countedNums[i] = 0;
		i++;
	}

	i = 0;
	printf("startlocations input: ");
	while (i < 1000)
	{
		j = 0;
		inputNums[i] = atoi(inputs[i]);
		printf("%llu ", inputNums[i]);
		while (j < 2000)
		{
			if (j == inputNums[i])
				countedNums[j]++;
			j++;
		}
		i++;
	}
	printf("\n");

	i = 0;
	while (i < 2000)
	{
		printf("%llu ", countedNums[i]);
		i++;
	}

	while (loc < 2000)
	{
		j = 0;
		fuel = 0;
		while (j < 1000)
		{
			fuel += abs(inputNums[j] - loc);
			j++;
		}
		if (fuel < bestfuel)
		{
			bestfuel = fuel;
			bestloc = loc;
			printf("Fuel needed on loc %d: %d\n", loc, fuel);
		}
		
		loc++;
		
	}
	// printf("Least fuel needed on loc %d: %d fuel needed\n", bestloc, bestfuel);	
	fclose(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
	