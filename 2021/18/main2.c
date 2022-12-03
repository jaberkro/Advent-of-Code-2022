#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int count_result(char *currentline)
{
    int magnitude = 0;
    int calculations[100];
    char newline[200];
    int i = 0;
    char *add[2];
    int count = 0;
    while (currentline[i] != '\0')
    {
        newline[0] = '\0';
        if (currentline[i] == ',' && currentline[i - 1] >= '0' && currentline[i - 1] <= '9' && \
            currentline[i + 1] >= '0' && currentline[i + 1] <= '9')
        {
            calculations[count] = (currentline[i - 1] - 48) * 3 + (currentline[i + 1] - 48) * 2;
            strlcpy(newline, currentline, i - 1);
            add[0] = 'A' + count;
            add[1] = '\0';
            strcat(newline, add);
            strcat(newline, currentline + i + 3);
            strcpy(currentline, newline);
            count++;
            i = 0;
        }
        if (currentline[i] == ',' && currentline[i - 1] >= '0' && currentline[i - 1] <= '9' && \
            currentline[i + 1] >= 'A' && currentline[i + 1] <= 'Z')
        {
            calculations[count] = (currentline[i - 1] - 48) * 3 + calculations[(currentline[i + 1] - 65)] * 2;
            strlcpy(newline, currentline, i - 1);
            add[0] = 'A' + count;
            add[1] = '\0';
            strcat(newline, add);
            strcat(newline, currentline + i + 3);
            strcpy(currentline, newline);
            count++;
            i = 0;
        }
        if (currentline[i] == ',' && currentline[i + 1] >= '0' && currentline[i + 1] <= '9' && \
            currentline[i - 1] >= 'A' && currentline[i - 1] <= 'Z')
        {
            calculations[count] = calculations[(currentline[i - 1] - 65)] * 3 + (currentline[i + 1] - 48) * 2;
            strlcpy(newline, currentline, i - 1);
            add[0] = 'A' + count;
            add[1] = '\0';
            strcat(newline, add);
            strcat(newline, currentline + i + 3);
            strcpy(currentline, newline);
            count++;
            i = 0;
        }
        if (currentline[i] == ',' && currentline[i + 1] >= 'A' && currentline[i + 1] <= 'Z' && \
            currentline[i - 1] >= 'A' && currentline[i - 1] <= 'Z')
        {
            calculations[count] = calculations[(currentline[i - 1] - 65)] * 3 + calculations[(currentline[i + 1] - 65)] * 2;
            strlcpy(newline, currentline, i - 1);
            add[0] = 'A' + count;
            add[1] = '\0';
            strcat(newline, add);
            strcat(newline, currentline + i + 3);
            strcpy(currentline, newline);
            count++;
            i = 0;
        }
        if (strlen(currentline) == 1)
            return (calculations[(currentline[0] - 65)]);
        i++;
    }
    return (magnitude);
}

char *splitting(char *currentline)
{
    char newline[1000];
    char new[6];
    int i = 0;
    int count = 0;
    int len = strlen(currentline);
    int f = 0;
    int l = 0;
    int lp = 0;
    int rp = 0;
    int r = 0;
    int n = 0;
    while (i < len)
    {
        if (currentline[i] > '9')
        {
            f = i;
            break ;
        }    
        i++;
    }
    new[0] = '(';
    new[1] = (currentline[f] - 48 ) / 2 + 48;
    new[2] = ',';
    new[3] = currentline[f] - new[1] + 48;
    new[4] = ')';
    new[5] = '\0';
    newline[0] = '\0';
    strlcpy(newline, currentline, f + 1);
    strcat(newline, new);
    strcat(newline, currentline + f + 1);
    return (newline);

}

char *explode(char *currentline)
{
    char newline[1000];
    int i = 0;
    int count = 0;
    int len = strlen(currentline);
    int f = 0;
    int l = 0;
    int lp = 0;
    int rp = 0;
    int r = 0;
    int n = 0;
    while (i < len)
    {
        if (currentline[i] == '(')
            count++;
        else if (currentline[i] == ')')
            count--;
        else if (currentline[i] >= '0' && f == 0)
            l = i;
        else if (currentline[i] >= '0' && f != 0 && r == 0 && n == 0)
        {  
            lp = currentline[i] - 48; 
            n++;   
        }
        else if (currentline[i] >= '0' && f != 0 && r == 0 && n == 1)
        {   
            rp = currentline[i] - 48; 
            n++;   
        }
        else if (currentline[i] >= '0' && f != 0 && r == 0 && n == 2)
            r = i;
        if (count > 4 && f == 0)
            f = i;  
        i++;
    }
    if (l != 0)
        currentline[l] += lp;
    if (r != 0)
        currentline[r] += rp;
    newline[0] = '\0';
    strlcpy(newline, currentline, f + 1);
    strcat(newline, "0");
    strcat(newline, currentline + f + 5);
    return (newline);
}

int check_nums(char *currentline)
{
    int i = 0;
    int len = strlen(currentline);
    while (i < len)
    {
        if (currentline[i] > '9')
        {
            return (1);    
        }
        i++;
    }
    return (0);
}

int count_brackets(char *currentline)
{
    int i = 0;
    int count = 0;
    int len = strlen(currentline);
    while (i < len)
    {
        if (currentline[i] == '(')
            count++;
        else if (currentline[i] == ')')
            count--;
        if (count > 4)
            return (1);    
        i++;
    }
    return (0);
}

char *reduce(char currentline[1000])
{
    int reduced;
    int i = 0;
    while (i < 1 || reduced > 0)
    {
        reduced = 0;
        while (count_brackets(currentline))
        {
            strcpy(currentline, explode(currentline));
            reduced = 1;
        }
        while (check_nums(currentline) && reduced == 0)
        {
            strcpy(currentline, splitting(currentline));
            reduced = 1;
        }
        if (reduced == 0)
            break;
        i++;
    }
    return (currentline);
}

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

    char    line1[200];
    char    newline[200];
    char    currentline[200];
    int i;
    int j;
    int k;
    int biggest = 0;
    int magnitude = 0;
    j = 0;
    while (j < 100)
    {
        currentline[0] = '\0';
        stream = fopen("input4.txt", "r");
        i = 0;
        while (i <= j)
        {
            getline(&line, &len, stream);
            i++;
        }
        line[strlen(line) - 1] = '\0';
        line1[0] = '\0';
        strcpy(line1, line);
        fclose(stream);
        i = 0;
        while (i < 100)
        {   
            stream = fopen("input4.txt", "r");
            if (i == j && j == 99)
                break ;
            else if (i == j)
                i++;
            k = 0;
            while (k <= i)
            {
                getline(&line, &len, stream);
                k++;
            }
            line[strlen(line) - 1] = '\0';
            newline[0] = '(';
            newline[1] = '\0';
            strcat(newline, line1);
            strcat(newline, ",");
            strcat(newline, line);
            strcat(newline, ")");
            strcpy(currentline, reduce(newline));
            magnitude = count_result(currentline);
            if (magnitude > biggest)
                biggest = magnitude;
            fclose(stream);
            i++;
        }
        j++;
        printf("biggest magnitude so far: %d\n", biggest);
    }
    printf("biggest magnitude: %d\n", biggest);
}
