#include <stdio.h>

void printbf(float f)
{
    // float, intどちらも32bit
    union
    {
        float f;
        int i
    } a;
    int i;

    a.f = f;

    for (i = 31; i >= 0; i--)
    {
        printf("%d", (a.i >> i) & 1);
        if (i == 31 || i == 23)
            printf(" ");
    }
}

int main(void)
{
    float a = 1.0;
    int i;
    for (i = 0; i < 130; i++)
    {
        printf("\n\n2^%d   : %lf\n1/2^%d : %.60lf\n", i, a, i, (float)1.0 / a);
        printbf(a);
        printf("\n");
        printbf((float)1.0 / a);
        a *= 2;
    }
    printf("\n\n");
}