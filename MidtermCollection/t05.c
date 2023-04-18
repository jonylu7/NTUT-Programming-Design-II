#include <stdio.h>
#include <string.h>

#define PLYAERCOUNT 9
#define INPUTCOLUMN 10
#define TOTALGAMECOUNT 5
#define PLAYERSTATEARRAYSIZE 3
#define OutPerRound 3
#define boardSize 3
// playerState codename,hitcount,returnToBase
int processInput(int *plyaer, char *playerPerformance)
{
    char tempInput = '0';

    for (int i = 0; i < PLYAERCOUNT; i++)
    {

        int count = 0;
        scanf("%d", &count);

        int j = 0;

        do
        {

            if (tempInput == '1' || tempInput == '2' || tempInput == '3' || tempInput == 'H' || tempInput == 'O')
            {
                *(playerPerformance + INPUTCOLUMN * i + j) = tempInput;
                j++;
            }
            scanf("%c", &tempInput);
        } while (tempInput != '\n');
        *(plyaer + PLAYERSTATEARRAYSIZE * i) = i + 1;
        *(plyaer + PLAYERSTATEARRAYSIZE * i + 1) = 0;
        *(plyaer + PLAYERSTATEARRAYSIZE * i + 2) = 0;
    }
}

int hit(int *playerState, char hitResult, int playerCodeName, int *board)
{
    int hitNum = 0;
    int returnToBaseCount = 0;
    if (hitResult == 'H')
    {
        hitNum = 4;
        returnToBaseCount++;
    }
    else
    {
        hitNum = hitResult - '0';
    }

    for (int i = 0; i < hitNum; i++)
    {
        *board <<= 1;
        if ((*board >> boardSize) & 1 == 1)
        {
            returnToBaseCount++;
        }
        *board &= 7;
    }
    if (hitNum < 4)
    {
        *board |= (1 << (hitNum - 1));
    }

    playerState[playerCodeName * PLAYERSTATEARRAYSIZE + 1] += 1;
    playerState[playerCodeName * PLAYERSTATEARRAYSIZE + 2] += returnToBaseCount;

    return returnToBaseCount;
}

int clearBoard(int *board)
{
    *board &= 0;
}

int play(int *playerState, char *playerPef)
{
    int outCount = 0;
    int i = 0;
    int j = 0;
    int board = 0;
    int end = 0;
    int totalScore = 0;
    while (end < TOTALGAMECOUNT)
    {

        if (i == PLYAERCOUNT)
        {
            i = 0;
            j++;
        }
        // printf("%d %d ", i, j);
        char hitResult = playerPef[i * INPUTCOLUMN + j];
        // printf("%c ", hitResult);
        if (hitResult == 'O')
        {
            outCount++;
        }
        else
        {
            int plusScore = hit(playerState, hitResult, i, &board);
            totalScore += plusScore;
        }

        if (outCount == 3)
        {
            outCount = 0;
            clearBoard(&board);
            end++;
            // printf("e\n");
        }

        i++;
    }
    return totalScore;
}

int compareState(int *a, int *b)
{
    if (a[2] > b[2])
    {
        return 0;
    }
    else if (a[2] < b[2])
    {
        return 1;
    }
    else
    {
        if (a[1] > b[1])
        {
            return 0;
        }
        else if (a[1] < b[1])
        {
            return 1;
        }
        else
        {
            if (a[0] > b[0])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int given(int *a, int *b)
{
    for (int i = 0; i < PLAYERSTATEARRAYSIZE; i++)
    {
        *(a + i) = *(b + i);
    }
}

int sortAndPrintPlayerState(int *playerState)
{

    for (int i = 1; i < PLYAERCOUNT; i++)
    {
        int temp[PLAYERSTATEARRAYSIZE];
        given(&temp, &playerState[i * PLAYERSTATEARRAYSIZE]);
        int tempi = i - 1;
        while (compareState(&playerState[tempi * PLAYERSTATEARRAYSIZE], &temp) == 1 && tempi >= 0)
        {

            given(&playerState[(tempi + 1) * PLAYERSTATEARRAYSIZE], &playerState[tempi * PLAYERSTATEARRAYSIZE]);

            tempi--;
        }
        given(&playerState[(tempi + 1) * PLAYERSTATEARRAYSIZE], &temp);
    }

    for (int i = 0; i < PLYAERCOUNT; i++)
    {
        printf("%d ", playerState[i * PLAYERSTATEARRAYSIZE]);
        printf("%d ", playerState[i * PLAYERSTATEARRAYSIZE + 1]);
        printf("%d\n", playerState[i * PLAYERSTATEARRAYSIZE + 2]);
    }
}

int main()
{
    int playerState[PLYAERCOUNT][PLAYERSTATEARRAYSIZE];
    char playerPerformance[PLYAERCOUNT][INPUTCOLUMN];
    processInput(&playerState, &playerPerformance);
    int score = play(&playerState, &playerPerformance);
    printf("%d\n", score);
    sortAndPrintPlayerState(&playerState);
}