#include <stdio.h>
#include <math.h>
int c(int m, int(*count), int (*numArray)[3000])
{
    *count += 1;
    if (m <= 1)
    {
        return 0;
    }
    else if (m % 2 == 0)
    {
        (*numArray)[*count] = m / 2;
        // printf("%d\n", (*numArray)[*count]);
        c(m / 2, &(*count), &(*numArray));
    }
    else if (m % 2 == 1)
    {
        (*numArray)[*count] = (m + 1) / 2;
        c((m + 1) / 2, &(*count), &(*numArray));
    }
}

int printIntToBit(int num)
{
    for (int i = 0; i < 14; i++)
    {
        printf("%c", (num >> (13 - i) & 1) == 1 ? '1' : '0');
        // printf("ssss%dssss", num);
    }
    printf("\n");
}

int turnBitToInt(char userInput[3000])
{
    int powNum = 9;
    int i = 0;
    int ans = 0;
    while (userInput[i] != '\0')
    {
        if (userInput[i] == '1')
        {
            ans += pow(2, powNum);
        }

        powNum--;
        i++;
    }
    return ans;
}

int t(int count)
{
    int total = 0;
    for (int i = 0; i <= count; i++)
    {
        int numArray[3000];
        int cNum = 0;
        c(i, &cNum, &numArray);
        total += cNum - 1;
    }
    return total;
}

int main()
{
    char userInput[3000];
    while (scanf("%s\n", userInput))
    {
        if (userInput[0] == '-')
        {
            break;
        }
        int num = turnBitToInt(userInput);
        int count = t(num);
        // printf("%d\n", count);
        printIntToBit(count);
    }
}