#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


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
    printf("%s\n", newline);
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
    printf("%s\n", newline);
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
    int i;
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

    int changed;
    char currentline[1000];
    char newline[1000];
    currentline[0] = '\0';
    stream = fopen("input4.txt", "r");
    int i = 0;
    getline(&line, &len, stream);
    line[strlen(line) - 1] = '\0';
    strcpy(currentline, line);
    while (i < 100 - 1)
    {
        changed = 0;
        getline(&line, &len, stream);
        line[strlen(line) - 1] = '\0';
        newline[0] = '(';
        newline[1] = '\0';
        strcat(newline, currentline);
        strcat(newline, ",");
        strcat(newline, line);
        strcat(newline, ")");
        printf("%s\n", newline);
        strcpy(currentline, reduce(newline));
        printf("%s\n", currentline);
        i++;
    }
}
