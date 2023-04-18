#include <math.h>
#include <stdio.h>
#include <string.h>

int printArray(char array[]);

char itoc(int a)
{
    return a + '0';
}

int ctoi(char a)
{
    return a - '0';
}

int checkGreater(char *Astart, char *Astop, char numB[])
{
    while (*Astart == '0' && Astart < Astop)
    {
        Astart++;
    }

    if ((Astop - Astart) < strlen(numB) - 1)
    {
        return 1;
    }
    else if ((Astop - Astart) > strlen(numB) - 1)
    {
        return 0;
    }

    int i = 0;

    while (Astart <= Astop && i < strlen(numB))
    {
        if (numB[i] > *Astart)
        {
            return 1;
        }
        else if (numB[i] < *Astart)
        {
            return 0;
        }
        Astart++;
        i++;
    }
    return 0;
}

int goMinus(char *Astart, char *Astop, char numB[])
{

    int i = strlen(numB) - 1;
    while (Astop >= Astart && i >= 0)
    {
        char showB = numB[i];
        if (ctoi(*Astop) - ctoi(numB[i]) < 0)
        {
            char *tempBorrow = Astop - 1;
            // find borrow num and given 9
            while (*tempBorrow == '0')
            {
                *tempBorrow = ctoi(itoc(*tempBorrow) + 9);
                tempBorrow--;
            }
            *tempBorrow = itoc(ctoi(*tempBorrow) - 1);
            // given value
            *Astop = itoc(ctoi(*Astop) - ctoi(numB[i]) + 10);

            if (*Astart == '0')
            {
                Astart++;
            }
        }
        else
        {
            *Astop = itoc(ctoi(*Astop) - ctoi(numB[i]));
        }
        Astop--;
        i--;
    }
}

int minus(char *Astart, char *Astop, char numB[])
{
    int result = 0;
    while (checkGreater(Astart, Astop, numB) == 0)
    {
        goMinus(Astart, Astop, numB);
        result++;
    }
    return result;
}

int divid(char *numA, char numB[], char *result)
{
    char *Astart = numA;
    char *Aend = numA + strlen(numA) - 1;
    char *Astop = numA + strlen(numB) - 1;
    // printf("%c", *Aend);
    int r = 0;
    while (checkGreater(Astart, Aend, numB) == 0 && Astop <= Aend && Astart <= Aend)
    {
        if (*Astart == '0')
        {
            Astart++;
            continue;
        }
        if (Astop - Astart < strlen(numB) - 1)
        {
            r++;
            Astop++;
            continue;
        }

        int resultPerTurn = 0;

        resultPerTurn = minus(Astart, Astop, numB);
        *(result + r) = itoc(ctoi(*(result + r)) + resultPerTurn);

        Astop++;
        r++;
    }
}

int printArray(char array[])
{

    int i = 0;
    while (i < strlen(array) - 1 && array[i] == '0')
    {
        i++;
    }

    while (array[i] != '\0')
    {
        printf("%c", array[i]);
        i++;
    }
    printf("\n");
}

int predfine(char *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        *(array + i) = '0';
    }
    *(array + size - 1) = '\0';
}
int main()
{
    char numA[50], numB[50], result[300];
    scanf("%s\n", numA);
    scanf("%s", numB);
    predfine(&result, strlen(numA) - strlen(numB) + 2);
    divid(&numA, numB, &result);
    printArray(result);
    printArray(numA);
}