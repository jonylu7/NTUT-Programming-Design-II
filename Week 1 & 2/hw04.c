#include <stdio.h>

void checkBelongOG(int s2, int s0)
{
    if (((s2 & s0) == s2))
    {
        printf("Y\n");
    }
    else
    {
        printf("N\n");
    }
}

int main()
{
    int s0, s1, s2;
    int r[3], a[3];
    scanf("%d", &s0);
    scanf("%d", &s1);
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d %d %d", &r[0], &r[1], &r[2]);
    s2 = s1;
    for (int i = 0; i < 3; i++)
    {
        s2 = s2 | (1 << a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        s2 = s2 & ~(1 << r[i]);
    }
    checkBelongOG(s2, s0);

    printf("%d\n", s2 & s1);
    printf("%d\n", s2 | s1);
}
