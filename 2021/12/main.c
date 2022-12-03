#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//SEE MAIN.PY

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

int try_all(char s, char A[10], char b[10], char c[10], char smallCaves[10], int smallcount)
{
    int l = 0;
    int output = 0;

    if (s == 'A')
    {
        while (A[l] != '\0')
        {
            printf("%c ", A[l]);
            if (A[l] > 96 && !(done_smallcave(A[l], smallCaves)) && A[l] != 'e')
            {
                smallCaves[smallcount] = A[l];
                smallCaves[smallcount + 1] = '\0';
                smallcount++;
                output += try_all(A[l], A, b, c, smallCaves, smallcount);
            }
            else if (A[l] < 96)
            {
                output += try_all(A[l], A, b, c, smallCaves, smallcount);
            }
            else if (A[l] == 'e')
            {
                printf("found one! A\n");
                output++;
                return (output);
            }
            l++;
        }
    }
    else if (s == 'b')
    {
        while (b[l] != '\0')
        {
            printf("%c ", b[l]);
            if (b[l] > 96 && !(done_smallcave(b[l], smallCaves)) && b[l] != 'e')
            {
                smallCaves[smallcount] = b[l];
                smallCaves[smallcount + 1] = '\0';
                smallcount++;
                output += try_all(b[l], A, b, c, smallCaves, smallcount);
            }
            else if (b[l] < 96)
                output += try_all(b[l], A, b, c, smallCaves, smallcount);
            else if (b[l] == 'e')
            {
                printf("found one! b\n");
                output++;
                return (output);
            }
            l++;
        }
    }
    else if (s == 'c')
    {
        while (c[l] != '\0')
        {
            printf("%c ", c[l]);
            if (c[l] > 96 && !(done_smallcave(c[l], smallCaves)) && c[l] != 'e')
            {
                smallCaves[smallcount] = c[l];
                smallCaves[smallcount + 1] = '\0';
                smallcount++;
                output += try_all(c[l], A, b, c, smallCaves, smallcount);
            }
            else if (c[l] < 96)
                output += try_all(c[l], A, b, c, smallCaves, smallcount);
            else if (c[l] == 'e')
            {
                printf("found one! c\n");
                output++;
                return (output);
            }   
            l++;
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
    char smallCaves[10];

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
    // while (j < tries)
    // {
        k = 0;
        int smallcount = 0;
        smallCaves[0] = '\0';
        while (k < startlen)
        {
            if (s[k] > 96)
            {
                smallCaves[smallcount] = s[k];
                smallCaves[smallcount + 1] = '\0';
                smallcount++;

            }
            printf("k = %d: %d\n", k, try_all(s[k], A, b, c, smallCaves, smallcount));
            k++;
        }
       // j++;

    // }

    exit(0);
}