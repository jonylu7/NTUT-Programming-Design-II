#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int simp(int *son, int *mother)
{
    int d = gcd(*son, *mother);

    *son = *son / d;
    *mother = *mother / d;

    if (*mother < 0)
    {
        *mother = abs(*mother);
        *son *= -1;
    }
}

int allDivided(float *a, float *b, float *c, float d)
{
    *a /= d;
    *b /= d;
    *c /= d;
}
int rowOperation(float *at, float *bt, float *ct, float a, float b, float c, float d)
{
    *at += a * d;
    *bt += b * d;
    *ct += c * d;
}

int findCross(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y)
{
    b1 *= -1;
    b2 *= -1;

    allDivided(&a1, &b1, &c1, a1);

    if (a2 / a1 > 0)
    {
        rowOperation(&a2, &b2, &c2, a1, b1, c1, fabs(a2) * -1);
    }
    else if (a2 / a1 < 0)
    {
        rowOperation(&a2, &b2, &c2, a1, b1, c1, fabs(a2));
    }
    // printf("f1fff%f %f %f %f %f %f\n", a1, b1, c1, a2, b2, c2);
    allDivided(&a2, &b2, &c2, b2);
    if (b1 / b2 > 0)
    {
        // printf("abs%f", b1);
        rowOperation(&a1, &b1, &c1, a2, b2, c2, fabs(b1) * -1);
    }
    else if (b1 / b2 < 0)
    {
        rowOperation(&a1, &b1, &c1, a2, b2, c2, fabs(b1));
    }

    *x = c2;
    *y = c1;
    // printf("f2fff%f %f %f %f %f %f\n", a1, b1, c1, a2, b2, c2);
}
int swap(float (*a)[2], float (*b)[2])
{
    float temp[2] = {(*a)[0], (*a)[1]};
    (*a)[0] = (*b)[0];
    (*a)[1] = (*b)[1];

    (*b)[0] = temp[0];
    (*b)[1] = temp[1];
}
int sortNum(float (*one)[2], float (*two)[2], float (*three)[2])
{
    if ((*one)[0] > (*three)[0])
        swap(&(*one), &(*three));
    else if ((*one)[0] == (*three)[0])
    {
        if ((*one)[1] > (*three)[1])
        {
            swap(&(*one), &(*three));
        }
    }
    if ((*one)[0] > (*two)[0])
        swap(&(*one), &(*two));
    else if ((*one)[0] == (*two)[0])
    {
        if ((*one)[1] > (*two)[1])
        {
            swap(&(*one), &(*two));
        }
    }

    // Now the smallest element is the 1st one. Just check the 2nd and 3rd

    if ((*two)[0] > (*three)[0])
        swap(&(*two), &(*three));
    else if ((*two)[0] == (*three)[0])
    {
        if ((*two)[1] > (*three)[1])
        {
            swap(&(*two), &(*three));
        }
    }
}
int two()
{

    float a1, b1, c1, a2, b2, c2, a3, b3, c3;

    scanf("%f %f %f", &a1, &b1, &c1);
    scanf("%f %f %f", &a2, &b2, &c2);
    scanf("%f %f %f", &a3, &b3, &c3);
    // printf("z");
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    findCross(a1, b1, c1, a2, b2, c2, &x1, &y1);
    findCross(a2, b2, c2, a3, b3, c3, &x2, &y2);
    findCross(a3, b3, c3, a1, b1, c1, &x3, &y3);
    float one[2] = {x1, y1};
    float two[2] = {x2, y2};
    float three[2] = {x3, y3};
    sortNum(&one, &two, &three);
    printf("(%.2f, %.2f)\n", one[0], one[1]);
    printf("(%.2f, %.2f)\n", two[0], two[1]);
    printf("(%.2f, %.2f)\n", three[0], three[1]);
}
int one(int loop)
{

    for (int i = 0; i < loop; i++)
    {
        int x1, y1, x2, y2;

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int mSon = y1 - y2;
        int mMother = x1 - x2;

        int bSon = x2 * y1 - x1 * y2;
        int bMother = x2 - x1;

        printf("y = ");

        if (mSon != 0)
        {
            simp(&mSon, &mMother);
            if (mSon * mMother == 1 || mSon * mMother == -1)
            {
                if (mSon == -1)
                {
                    printf("-");
                }
            }

            else
            {
                printf("%d", mSon);
                if (mMother != 1)
                {
                    printf("/%d", mMother);
                }
            }
            printf("x ");

            if (bSon != 0)
            {
                simp(&bSon, &bMother);
                if (bSon < 0)
                {
                    printf("- ");
                }
                else
                {
                    printf("+ ");
                }
                printf("%d", abs(bSon));
                if (bMother != 1)
                {
                    printf("/%d", bMother);
                }
            }
        }
        else
        {
            simp(&bSon, &bMother);
            printf("%d", bSon);
            if (bMother != 1)
            {
                printf("/%d", bMother);
            }
        }
        printf("\n");
    }
}

int main()
{

    int n = 0;
    int loop = 0;
    scanf("%d", &n);

    if (n == 1)
    {
        scanf("%d", &loop);
        one(loop);
    }
    else
    {
        two();
    }
}