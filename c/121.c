#include <stdio.h>
#include <stdlib.h>

// struct Price {
//     int value;
//     int index;
// };

int maxProfit(int* prices, int pricesSize);
// int cmpPrice(const void* a, const void* b);

int main()
{
    // int seq[] = {7,1,5,3,6,4};
    // int seq[] = {2,4,1};
    int seq[] = {7,11,1,2,4};
    int max = maxProfit(seq, 5);

    printf("%d\n", max);

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

// int maxProfit(int* prices, int pricesSize)
// {
//     struct Price** plist = malloc(sizeof(struct Price*) * pricesSize);
//     int i, j, max;

//     for (i = 0; i < pricesSize; i++) {
//         plist[i] = malloc(sizeof(struct Price));
//         plist[i]->value = prices[i];
//         plist[i]->index = i;
//     }

//     qsort(plist, pricesSize, sizeof(struct Price*), cmpPrice);

//     // for (i = 0; i < pricesSize; i++) {
//     //     printf("%d:%d\n", plist[i]->value, plist[i]->index);
//     // }

//     max = 0;
//     for (i = 0; i < pricesSize - 1; i++) {
//         for (j = pricesSize - 1; j > i; j--) {
//             if (plist[j]->index < plist[i]->index)
//                 continue;
//             // Current max less than overall max, no need to continue inner loop
//             else if (plist[j]->value - plist[i]->value <= max)
//                 break;
//             else
//                 max = plist[j]->value - plist[i]->value;
//         }
//     }

//     return max;
// }

// int cmpPrice(const void* a, const void* b)
// {
//     return (*(struct Price**)a)->value - (*(struct Price**)b)->value;
// }