#include <stdio.h>
#include <stdlib.h>

int changeInput(char Userinput, int state, int *outcount)
{

    int run;
    int ocount = *outcount;
    if (Userinput == 'O')
    {
        ocount++;
        printf("oo%doo", ocount);
        if (ocount == 3)
        {
            state = state & ~(7);
            ocount = 0;
        }
    }
    else
    {
        if (Userinput == 'H')
        {
            run = 4;
        }
        else
        {
            run = Userinput - '0';
        }
        state = state << run | (1 << (run - 1));
    }
    *outcount = ocount;
    return state;
}

int countScore(int state)
{
    printf("ss%dss", state);
    int score = 0;
    state = state >> 3;
    for (int i = 0; i < 50; i++)
    {
        if ((state & 1) == 1)
        {
            score++;
        }
        state = state >> 1;
    }
    return score;
}

int main()
{
    int state = 0;
    int outcount = 0;

    char UserInput;
    int k = 0;

    printf("%d", k);
    scanf("%s", &UserInput);
    state = changeInput(UserInput, state, &outcount);
    printf("k%dk", outcount);
    scanf("%s", &UserInput);
    state = changeInput(UserInput, state, &outcount);
    printf("k%dk", outcount);
    scanf("%s", &UserInput);
    state = changeInput(UserInput, state, &outcount);
    printf("k%dk", outcount);
    scanf("%s", &UserInput);
    state = changeInput(UserInput, state, &outcount);
    printf("%d", outcount);
    scanf("%s", &UserInput);
    state = changeInput(UserInput, state, &outcount);
    int score = countScore(state);
    printf("%d\n", score);
    printf("%d %d %d\n", state & 1, (state >> 1) & 1, (state >> 2) & 1);

    return 0;
}
