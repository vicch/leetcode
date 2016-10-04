#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize);

int main()
{
    int seq[] = {7,11,1,2,4};
    printf("%d\n", maxProfit(seq, 5));

    return 0;
}

int maxProfit(int* prices, int pricesSize)
{
    int minpri = *prices;
    int maxpro = 0;

    prices++;
    while (pricesSize-- > 1) {
        if (*prices < minpri)
            minpri = *prices;
        if (*prices - minpri > maxpro)
            maxpro = *prices - minpri;
        prices++;
    }

    return maxpro;
}