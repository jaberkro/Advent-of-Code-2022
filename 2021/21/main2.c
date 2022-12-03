#include <stdio.h>

int minof(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

void durac_dice(int place1, int place2, int score1, int score2, int win, unsigned long long *total1, unsigned long long *total2)
{
    int a = 1;
    int b = 1;
    int res1;
    int res2;
    while (a < 4)
    {
        b = 1;
        while (b < 4)
        {
            res1 = place1 + a;
            if (res1 > 10)
                res1 = res1 % 10;
            if (res1 == 0)
                res1 = 10;
            res2 = place2 + b;
            if (res2 > 10)
                res2 = res2 % 10;
            if (res2 == 0)
                res2 = 10;
            if (score1 + res1 >= win && score1 + res1 > score2)
            {
                *total1 += 1;
                return ;
            }
            if (score2 + res2 >= win && score2 + res2 > score1 + res1)
            {
                *total2 += 1;
                return ;
            }
            durac_dice(res1, res2, score1 + res1, score2 + res2, win, total1, total2);
            b++;
        }
        a++;
    }
    return ;
}

int main(void)
{
    int place1 = 4; // 3 for real, 4 for example
    int place2 = 8; // 10 for real, 8 for example

    int score1 = 0;
    int score2 = 0;

    unsigned long long total1 = 0;
    unsigned long long total2 = 0;

    int win = 21;

    durac_dice(place1, place2, score1, score2, win, &total1, &total2);
    printf("total 1: %llu, total 2: %llu\n", total1, total2);
}
