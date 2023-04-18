#include <stdio.h>
void printHastag(n, row, m)
{
    if (n == 2)
    {
        for (int i = 0; i < (m - row) * 2; i++)
        {
            printf("*");
        }
    }
    else if (n == 1)
    {
        for (int i = 0; i < m - (row + 1); i++)
        {
            printf("#");
        }
    }
}

void printAplhabet(row, m)
{
    char currentAlphaBet;
    if (row > 0)
    {
        currentAlphaBet = 'A' + ((row - 1) % 3);
        for (int i = 0; i < row; i++)
        {

            printf("%s%c", "*", currentAlphaBet);
        }
    }

    printf("*");
}

void printnum(start, end)
{
    int step = 1;
    if (start > end)
    {
        step = -1;
    }

    while (start != end + step)
    {
        printf("%d", start);
        start += step;
    }
}

void mainPrint(n, m)
{
    for (int i = 0; i < m; i++)
    {
        if (n == 1)
        {
            printHastag(n, i, m);
            printAplhabet(i, m);
            printHastag(n, i, m);
        }
        else
        {
            printnum(1, i + 1);
            printHastag(n, i, m);
            printnum(i + 1, 1);
        }
        printf("\n");
    }
}

int check(n, m)
{
    if (n<1 | n> 2 | m<2 | m> 9)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    if (check(n, m) == 0)
    {
        printf("%s", "error");
    }
    else
    {
        mainPrint(n, m);
    }
}