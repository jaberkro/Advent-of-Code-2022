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
    fptr2 = fopen("output.txt", "w");
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
	int 	k;
	int		l;
	int 	m;
	int 	o;
	int 	p;
	int 	q;
	char	***inputs;
	int 	total = 100;

	len = 14;
	stream = fopen("input.txt", "r");
	i = 0;
	while (i < 500)
	{
		getline(&line, &len, stream);
		inputs[i] = ft_split(line, ' ');
		i++;
	}	
	printf("inputs: %s, %s, %s, %s, %s\n\n", inputs[i][0], inputs[i][1], inputs[i][2], inputs[i][3], inputs[i][4]);
	close(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
	