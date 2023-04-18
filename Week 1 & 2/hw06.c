#include <stdio.h>
#include <ctype.h>
int changeInput(char i)
{

    if (i == 'H')
    {
        return 4;
    }
    else
    {
        return i - '0';
    }
}

int processInput()
{
    int table[5][5];
    for (int player = 0; player < 5; player++)
    {
        int hitCount = 0;
        char userInput[100];
        scanf("%d %[^\n]", &hitCount, &userInput);
        int i = 0;
        while (i < hitCount)
        {

            if (userInput[i] == 'H' || isdigit(userInput[i]) || userInput[i + 1] == 'O')
            {

                if (userInput[i + 1] == 'O')
                {
                    table[player][i] = 0;
                }
                else
                {
                    table[player][i] = changeInput(userInput[i]);
                }
            }
            i++;
        }
    }
    return table;
}

int getNextPlayer()
{

    // playerOnBase++
    // return playerNumber to use on table
    // avPlayer--
}

int makePlayerAvailble()
{

    // playerOnBase--
    // avPlayer++
}

int scoreCount(int state)
{
    int tempState = state & ~(7);
    int score = 0;
    for (int i = 0; i < 50; i++)
    {
        if (tempState >> 1 & 1 == 1)
        {
            score++;
        }
        tempState = tempState >> 1;
    }
    // make player availble

    return score;
}

int go()
{
    int table[5][5];
    table == processInput();

    int availblePlayer = 15;
    int playerOnBase = 7;
    int state = 0;
}

int main()
{ // team1
    go();
    // team2
    go();
}