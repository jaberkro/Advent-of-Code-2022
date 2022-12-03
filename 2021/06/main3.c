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

unsigned int arrlen(unsigned int inputNums[2000])
{
	unsigned int i = 0;
	while (inputNums[i] != 11)
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
	int		inputNums[2000];
	int		day = 0;
	unsigned int		i;
	int		new;
	int		k;
	unsigned int		startAmount;
	
	int		inputlines = 500;
	int 	total = 1000;
	int		outputNums[total][total];
	int 	tmp;
	int		dist;
	int		endCount = 0;

	len = 600;

	//READ INPUT, CONVERT TO INT AND LOAD IT INTO AN ARRAY CALLED INPUTNUMS
	stream = fopen("input2.txt", "r");
	getline(&line, &len, stream);
	inputs = ft_split(line, ',');

	i = 0;
	while (i < 2000)
	{
		inputNums[i] = 11;
		i++;
	}

	i = 0;
	printf("Day 0 inputs: ");
	startAmount = ft_strlen(inputs);
	while (i < 300)
	{
		inputNums[i] = (unsigned int)(atoi(inputs[i]));
		printf("%d ", inputNums[i]);
		i++;
	}
	printf("\n");
	day++;
	while (day < 257) // days you want + 1
	{
		i = 0;
		new = 0;
		
		startAmount = arrlen(inputNums);
		printf("startAmount: %d  ", startAmount);
		printf("After %d days: ", day);
		while (i < startAmount)
		{
			if (inputNums[i] == 0)
			{
				inputNums[i] = 7;
			}
			inputNums[i] -= 1;
			if (inputNums[i] == 0)
			{
				inputNums[startAmount + new] = 9;
				new++;
			}
			i++;
		}
		while (inputNums[i] != 9 && inputNums[i] != 11)
		{
			i++;
		}
		printf("\n");
		day++;
	}
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
	