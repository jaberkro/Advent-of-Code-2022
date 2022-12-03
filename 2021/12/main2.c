#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// SEE MAIN.PY

int done_smallcave(char s, char smallCaves[10])
{
    int i = 0;
    while (smallCaves[i])
    {
        if (smallCaves[i] == s)
            return (1);
        i++;
    }
    return (0);
}

int try_all(char s, char A[10], char b[10], char c[10], char path[10], int count)
{
    int l = 0;
    int m = 0;
    int n = 0;
    int output = 0;

    if (s == 'A')
    {
        while (A[l] != '\0')
        {
            if (A[l] > 96 && !(strchr(path, A[l])) && A[l] != 'e')
            {
                path[count] = s;
                count++;
                output += try_all(A[l], A, b, c, path, count);
            }
            else if (A[l] < 96)
            {
                path[count] = s;
                count++;
                output += try_all(A[l], A, b, c, path, count);
            }
            else if (A[l] == 'e')
            {
                path[count] = s;
                printf("found one! %s\n", path);
                output++;
            }
            l++;
        }

    }
    else if (s == 'b')
    {
        while (b[m] != '\0')
        {
            if (b[m] > 96 && !(strchr(path, b[l])) && b[m] != 'e')
            {
                path[count] = s;
                count++;
                output += try_all(b[m], A, b, c, path, count);
            }
            else if (b[m] < 96)
            {
                path[count] = s;
                count++;
                output += try_all(b[m], A, b, c, path, count);
            }
            else if (b[m] == 'e')
            {
                path[count] = s;
                printf("found one! %s\n", path);
                output++;
                }   
            m++;
        }
    }
    else if (s == 'c')
    {
        while (c[n] != '\0')
        {
            if (c[n] > 96 && !(strchr(path, c[n])) && c[n] != 'e')
            {
                path[count] = s;
                count++;
                output += try_all(c[n], A, b, c, path, count);
            }
            else if (c[n] < 96)
            {
                path[count] = s;
                count++;
                output += try_all(c[n], A, b, c, path, count);
            }
            else if (c[n] == 'e')
            {
                path[count] = s;
                printf("found one! %s\n", path);
                output++;
            }    
            n++;
        }
    }
    return (output);
}

int main(void)
{
    FILE	*stream;
	char	*line;
	size_t	len = 100;

    int lines = 6;
    int i = 0;

    char s[10];
    char A[10];
    char b[10];
    char c[10];
    char path[20];
    int count = 0;

    int scount = 0;
    int Acount = 0;
    int bcount = 0;
    int ccount = 0;

    int tries = 2;
    int startlen = 2;
    
    stream = fopen("input.txt", "r");
    while (i < lines)
    {
        getline(&line, &len, stream);
        if (line[0] == 's')
        {
            s[scount] = line[2];
            scount ++;
        }
        else if (line[2] == 's')
        {
            s[scount] = line[0];
            scount ++;
        }
        if (line[0] == 'A' && line[2] != 's')
        {
            A[Acount] = line[2];
            Acount ++;
        }
        else if (line[2] == 'A' && line[0] != 's')
        {
            A[Acount] = line[0];
            Acount ++;
        }
        if (line[0] == 'b' && line[2] != 's')
        {
            b[bcount] = line[2];
            bcount ++;
        }
        else if (line[2] == 'b' && line[0] != 's')
        {
            b[bcount] = line[0];
            bcount ++;
        }
        if (line[0] == 'c' && line[2] != 's')
        {
            c[ccount] = line[2];
            ccount ++;
        }
        else if (line[2] == 'c' && line[0] != 's')
        {
            c[ccount] = line[0];
            ccount ++;
        }      
        i++;
    }
    s[scount] = '\0';          
    A[Acount] = '\0';          
    b[bcount] = '\0';          
    c[ccount] = '\0';  
    printf("start: %s, Acount: %s, bcount: %s, ccount: %s\n", s, A, b, c);

    int j = 0;
    int k;
    k = 0;
    path[0] = '\0';
    while (k < startlen)
    {
        printf("k = %d: %d\n", k, try_all(s[k], A, b, c, path, count));
        k++;
    }
    exit(0);
}