#include <stdio.h>
#include <math.h>
int main()
{
    float w, h, bmi;
    scanf("%f", &w);
    scanf("%f", &h);

    bmi = w / ((h / 100) * (h / 100));
    printf("%.1f\n", bmi);
}