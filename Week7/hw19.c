#include <stdio.h>
#define SIZE 16
int fraction(int f)
{
    int result = 1;
    for (int i = f; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

int countPairOutcome(int n)
{

    if (n == 0 || n == 1)
    {
        return 0;
    }
    return fraction(n) / (2 * fraction(n - 2));
}

int findCross(char *table, int n)
{
    int final = 0;
    // left to right
    int i = n - 1;
    int j = 0;
    while (i >= 0 && j >= 0 && i < n && j < n)
    {
        int crossPair = 0;
        int tempi = i;
        int tempj = j;
        // printf("%d %d\n", i, j);
        while (tempj >= 0 && tempi >= 0 && tempi < n && tempj < n)
        {
            // printf("s%c ", (*(table + tempi * SIZE + tempj)));
            if (*(table + tempi * SIZE + tempj) == '1')
            {
                crossPair += 1;
            }
            tempi++;
            tempj++;
        }
        // printf("\n");
        final += countPairOutcome(crossPair);
        i--;
        if (i < 0)
        {
            i = 0;
            j++;
        }
    }
    // printf("WWW\n");
    //  right to left

    i = 0;
    j = 0;
    while (i >= 0 && j >= 0 && i < n && j < n)
    {
        int crossPair = 0;
        int tempi = i;
        int tempj = j;
        // printf("%d %d\n", i, j);
        while (tempj >= 0 && tempi >= 0 && tempi < n && tempj < n)
        {
            // printf("s%c ", (*(table + tempi * SIZE + tempj)));
            if (*(table + tempi * SIZE + tempj) == '1')
            {
                crossPair += 1;
            }
            tempi++;
            tempj--;
        }
        // printf("\n");
        final += countPairOutcome(crossPair);
        j++;
        if (j >= n)
        {
            j = n - 1;
            i++;
        }
    }

    return final;
}

int findRow(char *table, int n)
{
    int final = 0;
    for (int i = 0; i < n; i++)
    {
        int rowPair = 0;
        for (int j = 0; j < n; j++)
        {
            if (table[i * SIZE + j] == '1')
            {
                rowPair += 1;
            }
        }
        // printf("%d\n", rowPair);
        final += countPairOutcome(rowPair);
    }
    return final;
}

int findColumn(char *table, int n)
{
    int final = 0;
    for (int j = 0; j < n; j++)
    {
        int columnPair = 0;
        for (int i = 0; i < n; i++)
        {
            // printf("%c ", table[i * SIZE + j]);
            if (table[i * SIZE + j] == '1')
            {
                columnPair += 1;
            }
        }
        // printf("s%d", columnPair);
        final += countPairOutcome(columnPair);
    }
    return final;
}

int scan(char *table, int n)
{
    int i = 0;
    int j = 0;
    char temp;
    while (i < n)
    {

        scanf("%c", &temp);
        if (temp == '\n')
        {
            i++;
            j = 0;
            continue;
        }
        if (temp == ' ')
        {
            continue;
        }

        *(table + i * SIZE + j) = temp;
        j++;
    };
}

int main()
{
    int n = 0;
    scanf("%d\n", &n);
    char table[SIZE][SIZE];

    scan(table, n);

    int count = findColumn(table, n) + findCross(table, n) + findRow(table, n);
    /*printf("%d\n", findColumn(table, n));
    printf("%d\n", findCross(table, n));
    printf("%d\n", findRow(table, n));*/

    if (count == 0)
    {
        printf("There is no attack.");
    }
    else
    {
        printf("%d\n", count);
    }
}