#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    float x1, x2;
    x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
    printf("%.1f\n", x1);
    printf("%.1f\n", x2);
}