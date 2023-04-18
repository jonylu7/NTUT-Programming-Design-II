#include <stdio.h>
#include <stdio.h>

int main()
{
    char userInput[10];
    int i = 0;
    while (scanf("%s", &userInput[i]) != 1)
    {
        i += 1;
    }
    printf("\n");
    for (int i = 0; i < sizeof(userInput); i++)
    {
        printf("%c", userInput[i]);
    }

    return 0;
}