#include <math.h>
#include <stdio.h>
#include <string.h>
char itoc(int num)
{
    return num + '0';
}

int ctoi(char num)
{
    return num - '0';
}

int borrow(char (*array)[], int loc)
{
    int i = loc;
    while (i >= 0)
    {
        int num = ctoi((*array)[i]);
        if (num >= 1)
        {
            (*array)[i] = itoc(num - 1);
            return 0;
        }
        else if (num == 0)
        {
            (*array)[i] = itoc(9);
        }
        i--;
    }
}

int checkGreater(char numA[], char numB[])
{
    int aLen = strlen(numA);
    int bLen = strlen(numB);
    if (aLen > bLen)
    {
        return 0;
    }
    else if (aLen < bLen)
    {
        return 1;
    }
    else
    {
        int a = 0;
        int b = 0;
        while (a < aLen && b < bLen)
        {
            if (numA[a] > numB[b])
            {
                return 0;
            }
            else if (numA[a] < numB[b])
            {
                return 1;
            }
            a++;
            b++;
        }
    }
    return 2;
}

int sumAndcarry(char (*array)[], int loc, int c)
{

    (*array)[loc - 1] = itoc(ctoi((*array)[loc - 1]) + (int)(c / 10));
    (*array)[loc] = itoc(ctoi((*array)[loc]) + (int)(c % 10));

    if (ctoi((*array)[loc]) >= 10)
    {
        (*array)[loc - 1] = itoc(ctoi((*array)[loc - 1]) + (int)(ctoi((*array)[loc]) / 10));
        (*array)[loc] = itoc(ctoi((*array)[loc]) + (int)(ctoi((*array)[loc]) % 10));
    }
    printf("%c\t", (*array)[loc]);
}

int mult(char numA[], char numB[], char (*result)[])
{
    int aLen = strlen(numA);
    int bLen = strlen(numB) - 1;
    int rBegin = 299;
    int r = rBegin;
    while (!(aLen == 0 && bLen == 0))
    {
        int a = 0, b = ctoi(numB[bLen]), c = 0;
        if (aLen == 0 && bLen > 0)
        {
            bLen--;
            aLen = strlen(numA);
            rBegin--;
            r = rBegin;
        }
        if (aLen > 0)
        {
            aLen--;
            a = ctoi(numA[aLen]);
        }

        c = a * b;
        printf("val%d %d %d\t", c, a, b);
        sumAndcarry(&(*result), r, c);
        r--;
    }
}

int minus(char numA[], char numB[], char (*result)[])
{
    int whoGreater = checkGreater(numA, numB);
    if (whoGreater == 2)
    {
        return -1;
    }
    else if (whoGreater == 1)
    {
        char temp[] = numA;
        numA = numB;
        numB = temp;
    }

    int aLast = strlen(numA) - 1;
    int bLast = strlen(numB) - 1;

    while (aLast >= 0)
    {
        if (bLast == -1)
        {
            (*result)[aLast] = numA[aLast];
            aLast--;
            continue;
        }
        int a = ctoi(numA[aLast]);
        int b = ctoi(numB[bLast]);

        if ((a - b) < 0)
        {
            borrow(&numA, aLast);
            (*result)[aLast] = itoc(a - b + 10);
        }
        else
        {
            (*result)[aLast] = itoc(a - b);
        }

        aLast--;
        bLast--;
    }
}

int preDifine(char (*result)[], int size)
{
    for (int i = 0; i < size; i++)
    {
        (*result)[i] = '0';
    }
}

int add(char numA[], char numB[], char (*result)[])
{
    int aLen = strlen(numA);
    int bLen = strlen(numB);
    int r = 299;
    while (aLen > 0 || aLen > 0)
    {
        int a = 0, b = 0, c = 0;
        if (aLen > 0)
        {
            aLen--;
            a = ctoi(numA[aLen]);
        }
        if (bLen > 0)
        {
            bLen--;
            b = ctoi(numB[bLen]);
        }

        c = a + b;
        sumAndcarry(&(*result), r, c);
        r--;
    }
}

int printArray(char result[], int rStart)
{
    for (int i = rStart; i < strlen(result); i++)
    {
        if (i == rStart && result[i] == '0')
        {
            continue;
        }
        printf("%c", result[i]);
    }
    printf("\n");
}

int main()
{
    char sign, numA[50], numB[50], result[300];
    int rStart = 0;
    scanf("%c", &sign);
    scanf("%s\n", numA);
    scanf("%s", numB);
    preDifine(&result, 300);

    if (sign == '+')
    {
        rStart = add(numA, numB, &result);
    }
    else if (sign == '-')
    {
        rStart = minus(numA, numB, &result);
    }
    else
    {
        rStart = mult(numA, numB, &result);
    }

    if (rStart == -1)
    {
        printf("0\n");
    }
    else
    {
        printArray(result, rStart);
    }
}