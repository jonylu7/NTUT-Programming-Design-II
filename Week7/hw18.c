#include <stdio.h>
#include <string.h>
#define IMAGESIZE 20
int fillColor(char *a, char *d, char symbol, int n)
{
    int i = 0;
    int j = 0;
    while ((a + IMAGESIZE * i + j) < d)
    {
        if (j > n)
        {
            j = 0;
            i++;
        }
        *(a + IMAGESIZE * i + j) = symbol;
        j++;
    };
}

int dfRun(char df[], char *image, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (df[i] == '2')
        {
            dfRun(*(df + i + 1), image, n);
        }
    }
}

int main()
{
    char df[100];
    int n = 0;
    scanf("%s", df);
    scanf("%d", &n);
    char image[IMAGESIZE][IMAGESIZE];
    dfRun(df, image, n);
    //print array
}