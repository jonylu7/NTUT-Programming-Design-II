#include <stdio.h>
int guessNum(char target[4], char num)
{

    for (int i = 0; i < 4; i++)
    {

        if (num == target[i])
        {

            return i;
        }
    }
    return -1;
}
void guessResult(char target[4], char guess[4], char (*result)[4])
{

    // printf("gg%cgg\n", target[0]);
    for (int i = 0; i < 4; i++)
    {

        int guessResult = guessNum(target, guess[i]);
        // printf("%d %c %d\n", guessResult, guess[i], i);
        if (guessResult != -1)
        {

            if (guessResult == i)
            {
                (*result)[0] = (char)((int)(*result)[0] + 1);
            }
            else
            {
                (*result)[2] = (char)((int)(*result)[2] + 1);
            }
        }
    }
    // printf("%c%c%c%c\n", (*result)[0], (*result)[1], (*result)[2], (*result)[3]);
}
int main()
{
    char target[4] = {'0', '0', '0', '0'};
    scanf("%s\n", target);
    char guess[4] = {'0', '0', '0', '0'};
    // printf("ss%c%c%c%css\n", target[0], target[1], target[2], target[3]);
    int count = 1;
    while (scanf("%s", guess) && count <= 6)
    {
        char result[4] = {'0', 'A', '0', 'B'};
        // printf("rr%c%c%c%css\n", guess[0], guess[1], guess[2], guess[3]);
        guessResult(target, guess, &result);
        if (result[0] == '4')
        {
            printf("win");
            break;
        }
        else
        {
            printf("%c%c%c%c\n", result[0], result[1], result[2], result[3]);
        }
        count++;
    }

    if (count > 6)
    {
        printf("loss");
    }
}