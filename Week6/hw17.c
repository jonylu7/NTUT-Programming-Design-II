#include <stdio.h>
#include <string.h>

int printArray(char array[])
{
    int i = 0;
    while (array[i] != '\0')
    {
        printf("%c", array[i]);
        i++;
    }
    printf("\n");
}

int S(char X[], char Y[])
{
    int count = 0;
    if (strlen(X) == 0)
    {
        return 0;
    }
    for (int i = 0; i < strlen(Y); i++)
    {
        if (*X > *(Y + i))
        {
            // printf("%c %c\n", *X, *(Y + i));
            count++;
        }
    }
    X = X + 1;
    return count + S(X, Y);
}

int W(char X[])
{
    int count = 0;
    if (strlen(X) == 1)
    {
        return 0;
    }
    for (int i = 1; i < strlen(X); i++)
    {
        if (*X > *(X + i))
        {
            // printf("%c %c\n", *X, *(X + i));
            count++;
        }
    }
    X = X + 1;
    return count + W(X);
}
int main()
{
    // input
    int lengthOfInput = 0;
    scanf("%d\n", &lengthOfInput);
    char X[lengthOfInput / 2];
    for (int i = 0; i < lengthOfInput / 2; i++)
    {
        scanf("%c ", &X[i]);
    }
    X[lengthOfInput / 2] = '\0';

    // printArray(X);
    char Y[lengthOfInput - (lengthOfInput / 2)];
    for (int i = 0; i < lengthOfInput - (lengthOfInput / 2); i++)
    {
        scanf("%c ", &Y[i]);
    }
    Y[lengthOfInput - (lengthOfInput / 2)] = '\0';
    // printArray(Y);
    // printf("\n");
    // printf("%d\n", W(X));
    // printf("%d\n", W(Y));
    // printf("%d\n", S(X, Y));
    printf("%d", W(X) + W(Y) + S(X, Y));
}