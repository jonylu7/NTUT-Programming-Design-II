#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define START 0
#define VH 1
#define VB 2
#define VARIABLE 3
#define ZH 4
#define INTEGER 5
#define FB 6
#define FI 7
#define FLOAT 8
#define IH 9
#define AFH 11
#define AFB 12
#define AFH2 13
#define AFB2 14
#define AFE 15
#define ALG_FRACTION 16
#define PFH 17
#define PFB 18
#define PROP_FRACTION 19
#define FALSE 20
#define DOT 21

int getState(int state, char key)
{
    // VAR
    if (state == START && (isalpha(key) || key == '_'))
    {
        return VH;
    }
    else if (state == VH && (isalpha(key) || isdigit(key) || key == '_'))
    {
        return VB;
    }
    else if (state == VB && (isalpha(key) || isdigit(key) || key == '_'))
    {
        return VB;
    }
    else if ((state == VB || state == VH) && key == '\0')
    {
        return VARIABLE;
    }

    // INT
    else if (state == START && key >= '1' && key <= '9')
    {
        return IH;
    }
    else if (state == IH && isdigit(key))
    {
        return IH;
    }
    else if (state == IH && key == '\0')
    {
        return INTEGER;
    }

    // PROP FRAC
    else if (state == IH && key == '/')
    {
        return PFH;
    }
    else if (state == PFH && key >= '1' && key <= '9')
    {
        return PFB;
    }
    else if (state == PFB && isdigit(key))
    {
        return PFB;
    }
    else if (state == PFB && key == '\0')
    {
        return PROP_FRACTION;
    }

    // ALG_FRAC
    else if (state == IH && key == '(')
    {
        return AFH;
    }
    else if (state == AFH && key >= '0' && key <= '9')
    {
        return AFB;
    }
    else if (state == AFB && isdigit(key))
    {
        return AFB;
    }
    else if (state == AFB && key == '/')
    {
        return AFH2;
    }
    else if (state == AFH2 && key >= '0' && key <= '9')
    {
        return AFB2;
    }
    else if (state == AFB2 && isdigit(key))
    {
        return AFB2;
    }
    else if (state == AFB2 && key == ')')
    {
        return AFE;
    }
    else if (state == AFE && key == '\0')
    {
        return ALG_FRACTION;
    }

    // ZH to INT
    else if (state == START && key == '0')
    {
        return ZH;
    }
    else if (state == ZH && key == '\0')
    {
        return INTEGER;
    }

    // ZH to F
    else if (state == ZH && key == '.')
    {
        return DOT;
    }
    // IH to F
    else if (state == IH && key == '.')
    {
        return DOT;
    }
    // F
    else if (state == DOT && isdigit(key))
    {
        return FB;
    }
    else if (state == FB && isdigit(key))
    {
        return FB;
    }
    else if (state == FB && key == '\0')
    {
        return FLOAT;
    }

    else
    {
        return FALSE;
    }
}

void printState(int state)
{
    if (state == VARIABLE)
    {
        printf("variable\n");
    }
    else if (state == INTEGER)
    {
        printf("integer\n");
    }
    else if (state == FLOAT)
    {
        printf("float\n");
    }
    else if (state == ALG_FRACTION)
    {
        printf("algebraic fraction\n");
    }
    else if (state == PROP_FRACTION)
    {
        printf("proper fraction\n");
    }
}

int checkDivided(char strInput[], int Loc)
{
    int mother = 0;
    int son = 0;
    int i = Loc + 1;
    while (isdigit(strInput[i]) && strInput[i] != "\0")
    {

        mother *= 10;
        // printf("m%c", strInput[i]);
        mother += (int)(strInput[i] - '0');
        i++;
    }
    // printf("\n");
    i = Loc - 1;
    while (isdigit(strInput[i]) && i >= 0)
    {

        // printf("s%c", strInput[i]);
        son += (int)(strInput[i] - '0') * (int)pow(10, Loc - 1 - i);
        i--;
    }
    // printf("sm%d %d", son, mother);
    return (son < mother) ? 1 : 0;
}

void printFloat(char strInput[], int Loc)
{
    int w = -1;
    // printf("ss");
    do
    {
        w++;
        if (w == Loc)
        {
            printf("\n");
            w++;
        }
        if (isdigit(strInput[w]))
        {
            printf("%c", strInput[w]);
        }

    } while (strInput[w] != '\0');

    printf("\n");
}

int main()
{
    int inputCount = 0;

    scanf("%d", &inputCount);

    for (int i = 0; i < inputCount; i++)
    {
        char strInput[3000];
        scanf("%s", &strInput);
        // printf("\n", &strInput);
        // printf("%.*s", (int)sizeof(strInput), strInput);

        int state = START;
        int Loc = 0;
        int i = -1;
        do
        {
            i++;
            state = getState(state, strInput[i]);
            // printf("ss%d location:%d rr%c\n", state, i, strInput[i]);
            if (state == FALSE)
            {
                printf("error\n");
                break;
            }
            if (state == DOT)
            {
                Loc = i;
            }
            if (state == AFH2 || state == PFH)
            {
                Loc = i;
            }

        } while (strInput[i] != '\0');

        if (state != FALSE)
        {

            if (state == PROP_FRACTION || state == ALG_FRACTION)
            {
                if (!checkDivided(strInput, Loc))
                {
                    printf("error\n");
                    continue;
                };
            }

            printState(state);
            if (state == FLOAT)
            {
                printFloat(strInput, Loc);
            }
        }
    }
}