#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

int formatAndPrint(int son, int mother)
{
    int neg = 1;
    if (son < 0)
    {
        son = abs(son);
        neg = -1;
    }
    if (son == 0)
    {
        printf("0\n");
        return 0;
    }
    int d = gcd(son, mother);

    son = son / d;
    mother = mother / d;

    if (son > mother && son % mother > 0)
    {
        printf("%d(%d/%d)\n", (int)(son / mother) * neg, son % mother, mother);
        return 0;
    }
    else if (son % mother == 0)
    {
        printf("%d\n", (int)(son / mother) * neg);
    }
    else
    {
        printf("%d/%d\n", (son % mother) * neg, mother);
        return 0;
    }
}

int checkAlgFraction(char a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == '(')
        {
            return i;
        }
        i++;
    }
    return 0;
}

int createSM(char a[], int *son, int *mother)
{
    // printf("SM%d %d", *son, *mother);
    int i = 0;
    int meetSlash = 0;
    while (a[i] != '\0' && a[i] != ')')
    { // printf("%c",a[i]);
        // printf("SM%c %d %d\n", a[i], *son, *mother);
        if (a[i] == '/')
        { // printf("y");
            meetSlash = 1;
        }

        if (meetSlash && isdigit(a[i]))
        {
            *mother *= 10;
            *mother += (int)(a[i] - '0');
        }
        else if (isdigit(a[i]))
        {
            *son *= 10;
            *son += (int)(a[i] - '0');
        }
        i++;
    }
}

int turnAlgToProp(char a[], int *son, int *mother, int upper)
{

    int alg = 0;
    int i = 0;

    while (i < upper)
    {

        alg *= 10;
        alg += (int)(a[i] - '0');
        a[i] = '0';
        i++;
    }
    a[i] = '0';

    createSM(a, &*son, &*mother);
    // printf("alg%d %d\n", *son, *mother);
    *son += *mother * alg;
}

int validAndProcess(char a[], int *son, int *mother)
{ // verify that mother is not zero
  // turn change every number into son and mother only

    int upper = checkAlgFraction(a);
    int neg = 1;

    if (a[0] == '-')
    {
        neg = -1;
        a[0] = '0';
    }

    if (upper != 0)
    {
        turnAlgToProp(a, &*son, &*mother, upper);
        // printf("t%d %d\n", *son, *mother);
    }
    else
    {
        createSM(a, &*son, &*mother);
        // printf("t%d %d\n", *son, *mother);
    }

    *son *= neg;

    if (*mother == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int mult(int *son1, int *mom1, int son2, int mom2)
{
    *son1 *= son2;
    *mom1 *= mom2;
    // printf("%d %d %d %d", *son1, *mom1, son2, mom2);
    if (*mom1 < 0)
    {
        *mom1 *= -1;
        *son1 *= -1;
    }
}

int add(int *son1, int *mom1, int son2, int mom2)
{
    *son1 = *son1 * mom2 + son2 * *mom1;
    *mom1 *= mom2;
    // printf("ss%d %d", *son1, *mom1);
}

int mainFunc(char a[], char b[], char sign)
{
    int son1 = 0, son2 = 0, mother1 = 0, mother2 = 0;

    if (validAndProcess(a, &son1, &mother1) && validAndProcess(b, &son2, &mother2))
    {
        // printf("One%d %d\n", son1, mother1);
        // printf("Two%d %d\n", son2, mother2);
        if (sign == '*')
        {
            mult(&son1, &mother1, son2, mother2);
        }
        else if (sign == '/')
        {
            mult(&son1, &mother1, mother2, son2);
        }
        else if (sign == '-')
        {
            add(&son1, &mother1, son2 * -1, mother2);
        }
        else if (sign == '+')
        {
            add(&son1, &mother1, son2, mother2);
        }

        // printf("ss%d %d\n", son1, mother1);
        formatAndPrint(son1, mother1);
    }
    else
    {
        printf("error\n");
        return 0;
    }
}

int main()
{
    char continueSign = 'y';
    while (continueSign == 'y')
    {
        char inputValue1[3000];
        char inputValue2[3000];
        char calSign;

        scanf("%s\n", inputValue1);
        scanf("%s\n", inputValue2);
        scanf("%c\n", &calSign);
        scanf("%c", &continueSign);

        mainFunc(inputValue1, inputValue2, calSign);
    }
}