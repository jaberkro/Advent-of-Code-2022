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

unsigned long long countup(unsigned long long i)
{
	unsigned long long output = 0;
	while (i > 0)
	{
		output += i;
		i--;
	}
	return (output);
}

void	ft_read_line(void)
{
	FILE	*stream;
	char	*line;
	size_t	len;

	int possibleLines = 200;
	
	int i;
	int j;
	int last;
	int lineCounter;
	int totalCounter = 0;
	int wordlen;

	len = 4;

	//READ INPUT, CONVERT TO INT AND LOAD IT INTO AN ARRAY CALLED INPUTNUMS
	stream = fopen("input3.txt", "r");
	i = 0;
	while (i < possibleLines)
	{
		j = 0;
		getline(&line, &len, stream);
		line += 60;
		while (line[j])
		{
			if (line[j] != ' ' && line[j])
			{
				lineCounter = 0;
				last = 1;
				wordlen = 0;
				while (line[j + wordlen] != ' ' && line[j + wordlen] != '\n')
					wordlen++;
				if (wordlen == 2 || wordlen == 3 || wordlen == 4 || wordlen == 7)
				{
					totalCounter++;
				}
				j += wordlen;
				if (!line[j])
					break ;
			}
			j++;
		}
		i++;
		printf("input: %s \n", line - 60);
		printf("totalCounter: %d\n", totalCounter);
	}
	
	fclose(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
