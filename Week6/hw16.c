#include <stdio.h>
#include <string.h>

#define PLYAERCOUNT 9
#define INPUTCOLUMN 10
#define PLAYERARRAYSIZE 4
#define TOTALGAMECOUNT 5
#define BOARDSIZE 3
// board 110 pos 0 == board 1
// player={codename,hitCount,onboardCount,avaliable}
// playerPerformance={input}

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
        *(plyaer + PLAYERARRAYSIZE * i) = i + 1;
        *(plyaer + PLAYERARRAYSIZE * i + 1) = 0;
        *(plyaer + PLAYERARRAYSIZE * i + 2) = 0;
        *(plyaer + PLAYERARRAYSIZE * i + 3) = 1;
    }
}

int findWhosNext(char *player)
{
    for (int i = 0; i < PLYAERCOUNT; i++)
    {
        if (*(player + i * PLAYERARRAYSIZE + PLAYERARRAYSIZE - 1) == 1)
        {
            return i;
        }
    }
    // check all player , nothing found;
    return -1;
}

char findNextPlayerPerf(char *playerPerf, int nextPlayer, int perfSize)
{
    for (int i = 0; i < perfSize; i++)
    {
        if (*(playerPerf + nextPlayer * INPUTCOLUMN + i) != 'F')
        {
            char result = *(playerPerf + nextPlayer * INPUTCOLUMN + i);
            *(playerPerf + nextPlayer * INPUTCOLUMN + i) = 'F';
            return result;
        }
    }
}

int move(char *board, int *score, int moveCount)
{
    for (int i = BOARDSIZE - 1; i >= 0; i--)
    {
        board[i]
    }
}

int updatePlayerArray(char *player, int returnToBaseCount, int hitCount)
{
    int i = 0;
}

int play(char *player, int nextPlayer, char *playerPerf, char *board, int *score)
{
    // findNextPlayerPerf return it and turn to F and change player[3]='0'
    char result = findNextPlayerPerf(playerPerf, nextPlayer, strlen(playerPerf[nextPlayer]));
    player[nextPlayer * PLAYERARRAYSIZE + 3] = 0;

    int returnBaseCount;
    int hit = 0;
    if (result == 'O')
    {
        return 1;
    }
    else if (result == '1')
    {
        returnBaseCount = move(board, score, 1);
        hit = 1;
    }
    else if (result == '2')
    {
        returnBaseCount = move(board, score, 2);
        hit = 2;
    }
    else if (result == '3')
    {
        returnBaseCount = move(board, score, 3);
        hit = 3;
    }
    else if (result == 'H')
    {
        returnBaseCount = move(board, score, 4);
        hit = 4;
    }

    updatePlayerArray(player, returnBaseCount, hit);
    // update board and score
    // update return to base player
    // update playerArray
}
int playerIsFinYet(char *player, int nextPlayer, char *playerPerf)
{
    // run through player all remaining unread perf
    for (int i = 0; i < strlen(playerPerf[INPUTCOLUMN * nextPlayer + i]); i++)
    {
        if (*(playerPerf + INPUTCOLUMN * nextPlayer + i) != 'F')
        {
            return 0;
        }
    }
    // if still going then change its statue into -1
    player[nextPlayer * PLAYERARRAYSIZE + 3] = -1;
}

int game(char *player, char *playerPerf)
{
    int nextPlayer = 0;
    int score = 0;
    int gameCount = 0;
    int outCount = 0;

    while (nextPlayer = findWhosNext(player) != -1)
    {
        char board[3] = "\0\0\0";
        int isOut = play(player, nextPlayer, playerPerf, &board, &score);
        outCount += isOut;
        if (outCount == 3)
        {
            gameCount++;
            outCount = 0;
        }
        playerIsFinYet(player, nextPlayer, playerPerf);
        // if player all is F then turn that into -1(permentally finished);
        // failCount
        if (gameCount == TOTALGAMECOUNT)
        {
            return score;
        }
    }

    // game
    // findwho's next return codename-1
    // play read playerPerf ,codename ,update board finished?,update player

    // return score
    return score;
}

int main()
{
    int player[PLYAERCOUNT][PLAYERARRAYSIZE];
    char playerPerformance[PLYAERCOUNT][INPUTCOLUMN];

    processInput(&player, &playerPerformance);
    // game
    int score = game(&player, playerPerformance);
    // sort and output
}