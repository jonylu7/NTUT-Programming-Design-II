#include <stdio.h>
#define ARRAYWIDTH 2
#define ARRAYLENGTH 4

int ctoi(char a)
{
    return a - '0';
}
char itoc(int a)
{
    return a + '0';
}

int printDice(char *dice)
{
    printf("%c ", dice[ARRAYLENGTH + 1]);
    printf("%c ", dice[ARRAYLENGTH]);
    printf("%c ", dice[ARRAYLENGTH + 3]);
    printf("%c ", dice[ARRAYLENGTH + 2]);
    printf("%c ", dice[1]);
    printf("%c\n", dice[3]);
}

int arrayShiftBack(char *array, int widthLoc)
{
    int i = widthLoc * ARRAYLENGTH;
    char lastElement = array[i + ARRAYLENGTH - 1];
    for (int j = ARRAYLENGTH - 1; j > 0; j--)
    {
        array[i + j] = array[i + j - 1];
    }
    array[i] = lastElement;
}

int arrayShiftForward(char *array, int widthLoc)
{
    int i = widthLoc * ARRAYLENGTH;
    char firstElement = array[i];

    for (int j = 0; j < ARRAYLENGTH - 1; j++)
    {
        array[i + j] = array[i + j + 1];
    }
    array[i + ARRAYLENGTH - 1] = firstElement;
}

int goMove(char operation, char *actorArray)
{
    int widthLoc;
    if (operation == '1')
    {
        widthLoc = 1;
        arrayShiftBack(actorArray, widthLoc);
        actorArray[0] = actorArray[widthLoc * ARRAYLENGTH + 0];
        actorArray[2] = actorArray[widthLoc * ARRAYLENGTH + 2];
    }
    else if (operation == '3')
    {
        widthLoc = 0;
        arrayShiftBack(actorArray, widthLoc);
        actorArray[ARRAYLENGTH + 0] = actorArray[0];
        actorArray[ARRAYLENGTH + 2] = actorArray[2];
    }
    else
    {
        widthLoc = 0;
        arrayShiftForward(actorArray, widthLoc);
        actorArray[ARRAYLENGTH + 0] = actorArray[0];
        actorArray[ARRAYLENGTH + 2] = actorArray[2];
    }
}

int move(char actor, char operation, char *R, char *M, char *L)
{
    if (actor == 'R')
    {
        goMove(operation, R);
    }
    else if (actor == 'L')
    {
        goMove(operation, L);
    }
    else
    {
        goMove(operation, M);
    }
}

int replace(char *givenTo, char *from)
{
    for (int i = 0; i < ARRAYWIDTH; i++)
    {
        for (int j = 0; j < ARRAYLENGTH; j++)
        {
            givenTo[i * ARRAYLENGTH + j] = from[i * ARRAYLENGTH + j];
        }
    }
}

int swap(char actor, char target, char *R, char *M, char *L)
{

    char temp[ARRAYWIDTH][ARRAYLENGTH];
    if ((actor == 'L' && target == 'R') || (actor == 'R' && target == 'L'))
    {
        replace(&temp, R);
        // temp=r
        replace(R, L);
        // r = l
        replace(L, temp);
        // l=temp
    }
    else if ((actor == 'M' && target == 'R') || (actor == 'R' && target == 'M'))
    {
        replace(&temp, R);
        // temp=r
        replace(R, M);
        // r = m
        replace(M, temp);
        // m=temp
    }
    else if ((actor == 'L' && target == 'M') || (actor == 'M' && target == 'L'))
    {
        replace(&temp, L);
        // temp=l
        replace(L, M);
        // l = m
        replace(M, temp);
        // m=temp
    }
}

int main()
{

    char Right[2][4] = {"1265", "1463"};
    char Middle[2][4] = {"1265", "1463"};
    char Left[2][4] = {"1265", "1463"};

    int inputCount = 0;
    scanf("%d\n", &inputCount);
    for (int i = 0; i < inputCount; i++)
    {
        char mainActor, Operation;
        scanf("%c %c", &mainActor, &Operation);
        if (Operation == 'L' || Operation == 'R' || Operation == 'M')
        {

            swap(mainActor, Operation, &Right, &Middle, &Left);
        }
        else
        {

            move(mainActor, Operation, &Right, &Middle, &Left);
        }
        if (i < inputCount - 1)
        {
            scanf("\n");
        }
    }
    printDice(&Left);
    printDice(&Middle);
    printDice(&Right);
}