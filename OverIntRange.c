#include <stdio.h>
#include <limits.h>
#define UI unsigned int

void printb(UI v)
{
    UI mask = (UI)1 << (sizeof(v) * CHAR_BIT - 1);
    do
        putchar(mask & v ? '1' : '0');
    while (mask >>= 1);
}

int main(void)
{
    unsigned int numI = 1, i;
    unsigned long long numL = 1;

    for (i = 2; i <= 40; i += 1)
    {
        printf("\n%2u   int:%13u  ", i - 1, numI);
        printb(numI);
        //   	 printf("\n INT_MAX:%13ld",INT_MAX);
        numI = numI * i;
        numL = numL * (unsigned long long)i;
    }
    printf("\n\n");
}
