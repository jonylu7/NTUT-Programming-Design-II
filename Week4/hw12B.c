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

    int carry = ctoi((*array)[loc - 1]) + (int)(c / 10);
    int this = ctoi((*array)[loc]) + (int)(c % 10);

    if (this >= 10)
    {
        carry += this / 10;
        this %= 10;
    }

    (*array)[loc - 1] = itoc(carry);
    (*array)[loc] = itoc(this);
    // printf("%c\t", (*array)[loc]);
}

int preDifine(char (*result)[], int size)
{
    for (int i = 0; i < size; i++)
    {
        (*result)[i] = '0';
    }
}

int goMinus(char numA[], char numB[], char (*result)[])
{
    int aLast = strlen(numA) - 1;
    int bLast = strlen(numB) - 1;
    int rFirst = 299;
    while (aLast >= 0)
    {
        if (bLast < 0)
        {
            (*result)[rFirst] = numA[aLast];
            rFirst--;
            aLast--;
            continue;
        }
        int a = ctoi(numA[aLast]);
        int b = ctoi(numB[bLast]);
        int c = a - b;
        if (c < 0)
        {
            int i = aLast - 1;
            while (i >= 0)
            {
                int thisA = ctoi(numA[i]);
                if (thisA >= 1)
                {
                    numA[i] = itoc(thisA - 1);
                    break;
                }
                else if (thisA == 0)
                {
                    numA[i] = '9';
                }
                i--;
            }

            (*result)[rFirst] = itoc(c + 10);
        }
        else
        {
            (*result)[rFirst] = itoc(c);
        }

        aLast--;
        bLast--;
        rFirst--;
    }
    return rFirst;
}

int add(char numA[], char numB[], char (*result)[])
{
    int aLen = strlen(numA);
    int bLen = strlen(numB);
    int r = 299;
    while ((aLen != 0 || bLen != 0))
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
    return r;
}

int printArray(char result[], int rStart)
{
    for (int i = rStart; i < 300; i++)
    {
        if (i == rStart && result[i] == '0')
        {
            continue;
        }
        printf("%c", result[i]);
    }
    printf("\n");
}

int mult(char numA[], char numB[], char (*result)[])
{
    int aLen = strlen(numA);
    int bLen = strlen(numB) - 1;
    int rBegin = 299;
    int r = rBegin;
    while (!(aLen == 0 && bLen == 0))
    {
        int a = 0, c = 0;
        if (aLen == 0 && bLen > 0)
        {
            // printArray(*result, r);
            bLen--;
            aLen = strlen(numA);
            rBegin--;
            r = rBegin;
        }
        int b = ctoi(numB[bLen]);
        if (aLen > 0)
        {
            aLen--;
            a = ctoi(numA[aLen]);
        }
        c = a * b;

        sumAndcarry(&(*result), r, c);

        r--;
    }
    return r;
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
        int whoGreater = checkGreater(numA, numB);
        if (whoGreater == 2)
        {
            rStart = -1;
        }
        else if (whoGreater == 1)
        {
            rStart = goMinus(numB, numA, &(result));
            result[rStart] = '-';
        }
        else
        {
            rStart = goMinus(numA, numB, &(result));
        }
    }
    else if (sign == '*')
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