#include <stdio.h>
int changeInput(char i)
{
    if (i == 'O')
    {
        return 0;
    }
    else if (i == 'H')
    {
        return 4;
    }
    else
    {
        return i - '0';
    }
}
int main()
{
    char userInput[5];
    scanf("%s", &userInput[0]);
    scanf("%s", &userInput[1]);
    scanf("%s", &userInput[2]);
    scanf("%s", &userInput[3]);
    scanf("%s", &userInput[4]);

    int state = 0;
    int outCount = 0;
    for (int i = 0; i < 5; i++)
    {

        int run = changeInput(userInput[i]);
        if (run == 0)
        {
            outCount += 1;
            if (outCount == 3)
            {
                outCount = 0;
                state = state & ~7;
            }
        }
        else
        {
            state = state << run | 1 << (run - 1);
        }
    }

    int tempState = state & ~7;
    int score = 0;
    for (int i = 0; i < 50; i++)
    {
        if (tempState >> 1 & 1 == 1)
        {
            score++;
        }
        tempState = tempState >> 1;
    }
    printf("%d\n", score);
    state = state & 7;
    printf("%d %d %d\n", state & 1, state >> 1 & 1, state >> 2 & 1);
}