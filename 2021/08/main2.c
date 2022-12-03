#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#define BUF 50000

char ft_find_RU(char *rud, char RD)
{
	if (rud[0] == RD)
		return(rud[1]);
	return (rud[0]);	
}

char ft_find_RD(char **inputs, char *rud)
{
	int	i = 0;
	int	count = 0;
	int	pos = 0;
	char *opt1;
	char *opt2;
	char *opt3;

	while (i < 10)
	{
		if (ft_strlen(inputs[i]) == 6 && count == 0)
		{
			opt1 = inputs[i];
			count++;
		}
		else if (ft_strlen(inputs[i]) == 6 && count == 1)
		{
			opt2 = inputs[i];
			count++;
		}
		else if (ft_strlen(inputs[i]) == 6 && count == 2)
		{
			opt3 = inputs[i];
			count++;
		}
		i++;
	}

	if (ft_strchr(opt1, rud[0]) && ft_strchr(opt2, rud[0]) && ft_strchr(opt3, rud[0]))
		return(rud[0]);
	return (rud[1]);	
}

char ft_find_LD(char *rud, char T, char M, char B, char LU)
{
	int	j = 0;
	while (j < 7)
	{
		if (rud[0] != 'a' + j && rud[1] != 'a' + j && T != 'a' + j && M != 'a' + j && B != 'a' + j && LU != 'a' + j)
			return ('a' + j);
		j++;
	}
	return ('x');
}

char ft_find_LU(char *lum, char M)
{
	if (lum[0] == M)
		return (lum[1]);
	return (lum[0]);
}

char ft_find_B(char *tmb, char T, char M)
{
	int	i = 0;
	while (tmb[i] == T || tmb[i] == M)
		i++;
	return (tmb[i]);
}

char ft_find_M(char *tmb, char *lum)
{
	int		i = 0;
	while (i < 2)
	{
		if (ft_strchr(tmb, lum[i]))
			return (lum[i]);
		i++;
	}
	return ('x');
}

char	*ft_find_tmb(char **inputs)
{
	int	i = 0;
	int	j = 0;
	int	count = 0;
	int	pos = 0;
	char *tmb;
	char *opt1;
	char *opt2;
	char *opt3;

	tmb = ft_calloc(4, 0);
	while (i < 10)
	{
		if (ft_strlen(inputs[i]) == 5 && count == 0)
		{
			opt1 = inputs[i];
			count++;
		}
		else if (ft_strlen(inputs[i]) == 5 && count == 1)
		{
			opt2 = inputs[i];
			count++;
		}
		else if (ft_strlen(inputs[i]) == 5 && count == 2)
		{
			opt3 = inputs[i];
			count++;
		}
		i++;
	}
	while (j < 7 && pos < 3)
	{
		if (ft_strchr(opt1, ('a' + j))&& ft_strchr(opt2, ('a' + j)) && ft_strchr(opt3, ('a' + j)))
		{
			tmb[pos] = ('a' + j);
			pos++;
		}
		j++;
	}
	tmb[pos] = '\0';
	return (tmb);
}

char	*ft_find_lum(char **inputs, char *rud)
{
	int	i = 0;
	int	j;
	int pos = 0;
	char	*lum;

	lum = ft_calloc(3, 0);
	while (i < 10)
	{
		if (ft_strlen(inputs[i]) == 4)
		{
			j = 0;
			while (j < 4)
			{
				if (ft_strchr(rud, inputs[i][j]) == 0)
				{
					lum[pos] = inputs[i][j];
					pos++;
				}
				if (pos == 2)
				{
					lum[pos] = '\0';
					return (lum);
				}
				j++;
			}	
		}
		i++;
	}
	return ("not found");

}

char	ft_find_T(char **inputs, char *rud)
{
	int	i = 0;
	while (i < 10)
	{
		if (ft_strlen(inputs[i]) == 3)
		{
			if (ft_strchr(rud, inputs[i][0]) == 0)
				return (inputs[i][0]);
			else if (ft_strchr(rud, inputs[i][1]) == 0)
				return (inputs[i][1]);
			return (inputs[i][2]);
		}
		i++;
	}
	return ('x');
}

char	*ft_find_rud(char **inputs)
{
	int	i = 0;
	while (i < 10)
	{
		if (ft_strlen(inputs[i]) == 2)
			return(inputs[i]);
		i++;
	}
	return ("not found");
}

void	ft_read_line(void)
{
	FILE	*stream;
	char	*line;
	size_t	len;

	int possibleLines = 200;

	int i;
	int j;
	int	k;
	int last;
	int lineCounter;
	unsigned long long totalCount = 0;
	unsigned long long	count = 1;
	int wordlen;

	char **inputs;

	char	*rud;
	char	*lum;
	char	*tmb;
	char	T;
	char	M;
	char	B;
	char	LU;
	char	LD;
	char	RU;
	char	RD;

	char	num[5];

	len = 4;

	//READ INPUT, CONVERT TO INT AND LOAD IT INTO AN ARRAY CALLED INPUTNUMS
	stream = fopen("input3.txt", "r");
	i = 0;
	while (i < possibleLines)
	{
		getline(&line, &len, stream);
		inputs = ft_split(line, ' ');

		rud = ft_find_rud(inputs);
		T = ft_find_T(inputs, rud);
		lum = ft_find_lum(inputs, rud);
		tmb = ft_find_tmb(inputs);
		M = ft_find_M(tmb, lum);
		B = ft_find_B(tmb, T, M);
		LU = ft_find_LU(lum, M);
		LD = ft_find_LD(rud, T, M, B, LU);
		RD = ft_find_RD(inputs, rud);
		RU = ft_find_RU(rud, RD);

		k = 0;
		while (k < 4)
		{
			count = 1;
			j = 0;
			while (inputs[11 + k][j] != '\0')
			{
				if (inputs[11 + k][j] == T)
					count *= 2;
				if (inputs[11 + k][j] == LU)
					count *= 3;
				if (inputs[11 + k][j] == RU)
					count *= 5;
				if (inputs[11 + k][j] == M)
					count *= 7;
				if (inputs[11 + k][j] == LD)
					count *= 11;
				if (inputs[11 + k][j] == RD)
					count *= 13;
				if (inputs[11 + k][j] == B)
					count *= 17;
				j++;
			}
			
			if (count == 72930)
				num[k] = '0';
			if (count == 65)
				num[k] = '1';
			if (count == 13090)
				num[k] = '2';
			if (count == 15470)
				num[k] = '3';
			if (count == 1365)
				num[k] = '4';
			if (count == 9282)
				num[k] = '5';
			if (count == 102102)
				num[k] = '6';
			if (count == 130)
				num[k] = '7';
			if (count == 510510)
				num[k] = '8';
			if (count == 46410)
				num[k] = '9';
			
			k++;
		}
		num[4] = '\0';
		totalCount += atoi(num);
		printf("totalCount: %llu\n", totalCount);
		i++;
	}
	fclose(stream);
}

int	main(void)
{
	ft_read_line();
	exit(0);
}
