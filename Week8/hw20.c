#include <stdio.h>
#define DICEFACE 5
#define DICECOMB 6
int ctoi(char a)
{
    return a - '0';
}
char itoc(int a)
{
    return a + '0';
}

int printDice(char *dice, int whichDice)
{
    printf("%c ", *(dice + (whichDice - 1) * DICEFACE));
    printf("%c ", itoc(whichDice));
    printf("%c ", *(dice + (whichDice - 1) * DICEFACE + 1));
    printf("%c ", *(dice + (whichDice - 1) * DICEFACE + 4));
    printf("%c ", *(dice + (whichDice - 1) * DICEFACE + 3));
    printf("%c\n", *(dice + (whichDice - 1) * DICEFACE + 2));
}

int transLateDice(char actor)
{
    int whichDice = 0;
    if (actor == 'L')
    {
        whichDice = 0;
    }
    else if (actor == 'M')
    {
        whichDice = 1;
    }
    else if (actor == 'R')
    {
        whichDice = 2;
    }
    return whichDice;
}
int move(char *dice, int *diceUp, char actor, char operation)
{
    int whichDice = transLateDice(actor);
    if (operation == '1')
    {
        *(diceUp + whichDice) = ctoi(*(dice + DICEFACE * (*(diceUp + whichDice) - 1) + 1));
    }
    else if (operation == '2')
    {
        *(diceUp + whichDice) = ctoi(*(dice + DICEFACE * (*(diceUp + whichDice) - 1) + 3));
    }
    else if (operation == '3')
    {
        *(diceUp + whichDice) = ctoi(*(dice + DICEFACE * (*(diceUp + whichDice) - 1) + 2));
    }
}

int swap(char actor, char target, int *diceUp)
{

    int whichDiceA = transLateDice(actor);
    int whichDiceB = transLateDice(target);
    int temp = diceUp[whichDiceA];
    diceUp[whichDiceA] = diceUp[whichDiceB];
    diceUp[whichDiceB] = temp;
}

int main()
{
    char dice[DICECOMB][DICEFACE] = {
        "43526",
        "43165",
        "16524",
        "61523",
        "43612",
        "43251"};

    int dicUp[3] = {1, 1, 1};

    int inputCount = 0;
    scanf("%d\n", &inputCount);
    for (int i = 0; i < inputCount; i++)
    {
        char mainActor, Operation;
        scanf("%c %c", &mainActor, &Operation);
        if (Operation == 'L' || Operation == 'R' || Operation == 'M')
        {
            swap(mainActor, Operation, &dicUp);
        }
        else
        {

            move(&dice, &dicUp, mainActor, Operation);
        }
        if (i < inputCount - 1)
        {
            scanf("\n");
        }
    }

    printDice(&dice, dicUp[0]);
    printDice(&dice, dicUp[1]);
    printDice(&dice, dicUp[2]);
}