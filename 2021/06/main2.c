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

int arrlen(int inputNums[300])
{
	int i = 0;
	while (inputNums[i] != -1)
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
	int		inputNums[300];
	int		day = 0;
	unsigned long long		i;
	int		new;
	int		tmp;
	unsigned long long		j;
	int		startAmount;
	

	unsigned long long countedNums[10];

	len = 9;

	//READ INPUT, CONVERT TO INT AND LOAD IT INTO AN ARRAY CALLED INPUTNUMS
	stream = fopen("input2.txt", "r");
	getline(&line, &len, stream);
	inputs = ft_split(line, ',');

	i = 0;
	printf("Day 0 inputs: ");
	startAmount = ft_strlen(inputs);
	while (i < 300)
	{
		j = 0;
		inputNums[i] = atoi(inputs[i]);
		printf("%d ", inputNums[i]);
		while (j < 10)
		{
			if (j == inputNums[i])
				countedNums[j]++;
			j++;
		}
		i++;
	}
	printf("\n");

	i = 0;
	while (i < 10)
	{
		printf("%d ", countedNums[i]);
		i++;
	}

	printf("\n");
	day++;

	
	while (day < 256 + 1)
	{
		printf("After %d days: ", day);
		i = 0;
		tmp = countedNums[0];
		while (i < 9)
		{
			countedNums[i] = countedNums[i + 1];
			i++;
		}
		countedNums[9] = tmp;

		if (countedNums[0] != 0)
		{
			countedNums[9] = countedNums[0];	
		}
		if (countedNums[8] != 0)
		{
			countedNums[6] += countedNums[8];
		}
		if (countedNums[0] == 0)
			countedNums[9] = 0;
	

		//SHOW IN TERMINAL AFTER CREATING NEW FISH
		j = 0;
		while (j < 10)
		{
			printf("%llu ", countedNums[j]);
			j++;
		}
		printf("Totalfishcount: %llu\n", countedNums[0] + countedNums[1] + countedNums[2] + countedNums[3] + countedNums[4] + countedNums[5] + countedNums[6] + countedNums[7] + countedNums[8]);

		day++;
	}
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
	