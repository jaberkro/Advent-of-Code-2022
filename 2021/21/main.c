#include <stdio.h>

int minof(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

int main(void)
{
    int place1 = 3; // 3 for real, 4 for example
    int place2 = 10; // 10 for real, 8 for example

    int score1 = 0;
    int score2 = 0;

    int dicenumber = 1;
    int dicerolled = 0;

    int first;
    int second;
    int third;

    int win = 1000;
    while (score1 < win && score2 < win)
    {
        //PLAYER 1
        first = dicenumber++;
        if (dicenumber == 101)
            dicenumber -= 100;
        dicerolled++;
        place1 += first;
        if (place1 > 10)
            place1 = place1 % 10;
        if (place1 == 0)
            place1 = 10;
        second = dicenumber++;
        if (dicenumber == 101)
            dicenumber -= 100;
        dicerolled++;
        place1 += second;
        if (place1 > 10)
            place1 = place1 % 10;
        if (place1 == 0)
            place1 = 10;
        third = dicenumber++;
        if (dicenumber == 101)
            dicenumber -= 100;
        dicerolled++;
        place1 += third;
        if (place1 > 10)
            place1 = place1 % 10;
        if (place1 == 0)
            place1 = 10;
        score1 += place1;

        if (score1 >= win)
            break ;

        //place 2
        first = dicenumber++;
        if (dicenumber == 101)
            dicenumber -= 100;
        dicerolled++;
        place2 += first;
        if (place2 > 10)
            place2 = place2 % 10;
        if (place2 == 0)
            place2 = 10;
        second = dicenumber++;
        if (dicenumber == 101)
            dicenumber -= 100;
        dicerolled++;
        place2 += second;  
        if (place2 > 10)
            place2 = place2 % 10;
        if (place2 == 0)
            place2 = 10;
        third = dicenumber++;
        if (dicenumber == 101)
            dicenumber -= 100;
        dicerolled++;
        place2 += third;
        if (place2 > 10)
            place2 = place2 % 10;
        if (place2 == 0)
            place2 = 10;
        score2 += place2;

        printf("place 1: %d, place 2: %d\n", place1, place2);
    }
    printf("score 1: %d, score 2: %d, total amount dice rolled: %d\n", score1, score2, dicerolled);
    printf("answer: %d * %d = %d\n", minof(score1, score2), dicerolled, minof(score1, score2) * dicerolled);

}
