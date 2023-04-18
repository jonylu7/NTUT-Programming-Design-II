#include <stdio.h>
#include <string.h>
int ctoi(char num)
{
    return num - '0';
}
int scanWithoutSpace(char (*aString)[])
{
    char temp;
    int i = 0;
    do
    {
        scanf("%c", &temp);
        if (temp != ' ')
        {
            (*aString)[i] = temp;
            i++;
        }

    } while (temp != '\n');
    (*aString)[i - 1] = '\0';
}

int findNumInArray(char num, char array[], int stop)
{
    for (int i = 0; i < stop; i++)
    {
        if (array[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int generateSequence(char *start, char *end, char(*returnBit))
{
    int i = 1;
    *returnBit = *start;
    start++;

    while (start <= end)
    {
        if (findNumInArray(*start, returnBit, i) == 0)
        {
            *(returnBit + i) = *start;
        }
        else
        {
            return 0;
        }
        i++;
        start++;
    }
    return 1;
}

int printArray(char array[])
{
    for (int i = 0; i < strlen(array); i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");
}

int assignArray(char *allNum, int row, char array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        allNum[row * 11 + i] = array[i];
    }
}

int findSameArray(char *allNum, int Endrow, char array[], int size)
{
    int state;
    for (int i = 0; i < Endrow; i++)
    {
        state = 0;
        for (int j = 0; j < size; j++)
        {
            if (*(allNum + i * 11 + j) != array[j])
            {
                state = 1;
                break;
            };
        }
        if (state == 0)
        {
            return 0;
        }
    }
}

int checkArrayGreater(char A[], char B[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] > B[i])
        {
            return 0;
        }
        else if (A[i] < B[i])
        {
            return 1;
        }
    }
    return 1;
}

int givenValue(char *array, int rowA, int rowB, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[rowA * 11 + i] = array[rowB * 11 + i];
    }
}

int givenTemp(char *array, int row, char tempArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[row * 11 + i] = tempArray[i];
    }
}

int defineTemp(char *array, int row, char *temp, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(temp + i) = *(array + row * 11 + i);
    }
}

int sortAndPrint(char *array, int m, int total)
{
    int row = 1;
    int i = 0;

    while (row < total)
    {
        int tempRow = row - 1;
        char tempArray[100];
        defineTemp(array, row, &tempArray, m);
        while (checkArrayGreater(&array[tempRow * 11], tempArray, m) == 0 && tempRow >= 0)
        {
            givenValue(array, tempRow + 1, tempRow, m);
            tempRow--;
        };
        givenTemp(array, tempRow + 1, tempArray, m);
        row++;
    }

    int printRow = 0;
    while (printRow < total)
    {
        for (int w = 0; w < m; w++)
        {
            printf("%c ", array[printRow * 11 + w]);
        }
        printf("\n");
        printRow++;
    }
}

int main()
{
    int m;

    scanf("%d\n", &m);
    char aString[21];
    scanWithoutSpace(&aString);
    // printf("%d", (int)strlen(aString));
    char allNum[100][11];
    int w = 0;

    int j = 0;
    for (int i = 0; i < ((int)strlen(aString) - m) + 1; i++)
    {
        char thisNUm[m];
        if (generateSequence(aString + i, aString + i + m - 1, &thisNUm) == 1)
        {

            if (findSameArray(allNum, w, thisNUm, m) == 1)
            {
                assignArray(&allNum, w, thisNUm, m);

                w++;
            };
            j++;
        }
    }

    printf("%d\n", j);
    sortAndPrint(allNum, m, w);
}
