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
	int o;
	int p;
	int q;
	char	**inputs;
	int 	total = 100;
	
	int 	card[5][5];
	char	bingo[6][6];
	char 	**tmp;
	int		wins = 0;
	int		winningCards[100];
	int		totalcount;

	len = 14;
	stream = fopen("input2.txt", "r");
	getline(&line, &len, stream);
	printf("line: %s", line);
	inputs = ft_split(line, ',');
	printf("inputs: %s, %s, %s, %s, %s\n\n", inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
	close(stream);
	q = 0;
	while (q < 100)
	{
		winningCards[q] = 1;
		q++;
	}
	while (j < 250) // amount of inputs you want to check
	{
		stream = fopen("input2.txt", "r");
		getline(&line, &len, stream);
		getline(&line, &len, stream);
		i = 0;
		
		while (i < total)
		{
			totalcount = 0;
			// FILL BINGOCHECKER WITH ZEROES
			k = 0;
			l = 0;
			while (k < 5)
			{
				l = 0;
				while (l < 5)
				{
					bingo[k][l] = '0';
					l++;
				}
				bingo[k][l] = '\0';
				k++;
			}
			bingo[k][l] = '\0';
			
			// FILL CURRENT CARD WITH NUMBERS
			k = 0;
			l = 0;
			while (k < 5)
			{
				l = 0;
				getline(&line, &len, stream);
				tmp = ft_split(line, ' ');
				while (l < 5)
				{
					card[k][l] = atoi(tmp[l]);
					l++;
				}
				k++;
			}
			getline(&line, &len, stream);

			// CHECK CURRENT CARD WITH INPUT NUMBERS FOR BINGO
			k = 0;
			l = 0;
			while (k < 5)
			{
				l = 0;
				while (l < 5)
				{
					m = 0;
					while (m < j + 1)
					{
						if (card[k][l] == atoi(inputs[m]))
							bingo[k][l] = '1';
						m++;
					}
					l++;
				}
				k++;
			}
/*
			// PRINT CARD
			printf("%i, %i, %i, %i, %i\n", card[0][0], card[0][1], card[0][2], card[0][3], card[0][4] );			
			printf("%i, %i, %i, %i, %i\n", card[1][0], card[1][1], card[1][2], card[1][3], card[1][4] );			
			printf("%i, %i, %i, %i, %i\n", card[2][0], card[2][1], card[2][2], card[2][3], card[2][4] );			
			printf("%i, %i, %i, %i, %i\n", card[3][0], card[3][1], card[3][2], card[3][3], card[3][4] );			
			printf("%i, %i, %i, %i, %i\n\n", card[4][0], card[4][1], card[4][2], card[4][3], card[4][4] );	

			// PRINT BINGO CHECK RESULT
			printf("%c, %c, %c, %c, %c\n", bingo[0][0], bingo[0][1], bingo[0][2], bingo[0][3], bingo[0][4] );			
			printf("%c, %c, %c, %c, %c\n", bingo[1][0], bingo[1][1], bingo[1][2], bingo[1][3], bingo[1][4] );			
			printf("%c, %c, %c, %c, %c\n", bingo[2][0], bingo[2][1], bingo[2][2], bingo[2][3], bingo[2][4] );			
			printf("%c, %c, %c, %c, %c\n", bingo[3][0], bingo[3][1], bingo[3][2], bingo[3][3], bingo[3][4] );			
			printf("%c, %c, %c, %c, %c\n\n", bingo[4][0], bingo[4][1], bingo[4][2], bingo[4][3], bingo[4][4] );		
*/
			//CHECK IF A BINGO WAS FOUND
			o = 0;
			p = 0;
			while (o < 5)
			{
				if (bingo[o][0] == '1' && bingo[o][1] == '1' && bingo[o][2] == '1' && \
					bingo[o][3] == '1' && bingo[o][4] == '1')
				{
					//printf("#%d bingo found! horizontal. card: %d at line %d\n", wins, i + 1, 2 + (i + 1) * 6 - 5);
					winningCards[i] = 0;
					wins++;
				}
				o++;
			}
			while (p < 5)
			{
				if (bingo[0][p] == '1' && bingo[1][p] == '1' && bingo[2][p] == '1' && \
					bingo[3][p] == '1' && bingo[4][p] == '1')
				{
					//printf("#%d bingo found! vertical. card: %d at line %d\n", wins, i + 1, 2 + ((i + 1) * 6 - 5));
					winningCards[i] = 0;
					wins++;
				}
				p++;
			}	
			q = 0;
			while (q < 100)
			{
				totalcount += winningCards[q];
				q++;
			}
			if (totalcount == 1)
			{
				q = 0;
				while (q < 100)
				{
					if (winningCards[q] == 1)
						printf("card: %d at line %d\n", q + 1, 2 + ((q + 1) * 6 - 5));
					q++;
				}
				return;
			}
			

			i++;
		}
		
		
		close(stream);
		j++;
	}
	
}

int	main(void)
{
	ft_read_line();
	exit(0);
}