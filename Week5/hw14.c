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
int printArray(char result[], int rStart)
{
    for (int i = rStart; i < strlen(result); i++)
    {
        if (i == rStart && result[i] == '0')
        {
            continue;
        }
        if (result[i] == '\0')
        {
            break;
        }
        printf("%c", result[i]);
    }
    printf("\n");
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
            printf("k%c %c", numA[a], numB[b]);
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

int preDifine(char (*result)[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        (*result)[i] = '0';
    }
    (*result)[size - 1] = '\0';
}

char slice(char dividend[], int start, int end, char (*partDvidend)[])
{

    for (int i = start; i < end; i++)
    {
        (*partDvidend)[i - start] = dividend[i];
    }
    (*partDvidend)[end] = '\0';
}

int givenValue(char (*target)[], int start, int end, char value[])
{

    for (int i = start; i < end; i++)
    {
        (*target)[i] = value[i - start];
    };
}

int goMinus(char numA[], char numB[], char (*result)[])
{
    int aLast = strlen(numA) - 1;
    int bLast = strlen(numB) - 1;
    int rFirst = strlen((*result)) - 1;
    printArray((*result), 0);
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

int divid(char (*dividend)[], char divisor[], char (*result)[])
{
    int dLen = strlen((*dividend));
    int sLen = strlen(divisor);
    int dStart = 0, dEnd = sLen, r = 0;
    int resultLoc = dLen - sLen;
    while (dStart < dEnd)
    {
        printf("w%d %d %d\n", dStart, dEnd, r);
        if ((*dividend)[dStart] == '0')
        {
            dStart += 1;
            continue;
        }

        char partDvidend[dEnd - dStart];

        slice((*dividend), dStart, dEnd, &partDvidend);

        int greaterResult = checkGreater(partDvidend, divisor);

        if (greaterResult == 1)
        {
            dEnd += 1;
            r += 1;
        }
        else
        {
            char dAfter[sLen + 1];
            preDifine(&dAfter, sLen + 1);

            goMinus(partDvidend, divisor, &dAfter);

            givenValue(&(*dividend), dStart, dEnd, dAfter);

            (*result)[r] += 1;
            printArray((*dividend), 0);
        }
    }
    return 0;
}

int main()
{
    char sign, numA[50], numB[50], result[300];
    int rStart = 0;
    scanf("%s\n", numA);
    scanf("%s", numB);
    preDifine(&result, strlen(numA));

    int greaterResult = checkGreater(numA, numB);

    if (greaterResult == 0)
    {
        rStart = divid(&numA, numB, &result);

        printArray(result, rStart);
        printArray(numA, 0);
    }
    else if (greaterResult == 1)
    {
        printf("0\n");
        printArray(numA, 0);
    }
    else if (greaterResult == 2)
    {
        printf("1\n");
        printf("0");
    }
}