#include <stdio.h>

int maxProfit(int* prices, int pricesSize);

int main()
{
    int seq1[] = {1,3,2,4,3,5,4,6};
    int pro1 = maxProfit(seq1, 8);
    printf("%d\n", pro1);

    return 0;
}

/**
 * When outside of transaction, keep looking for lower price to buy
 * When inside transaction, keep looking for higher price to sell
 * Keep record of profit so far
 */
int maxProfit(int* prices, int pricesSize)
{
    if (!pricesSize) return 0;

    int i, state = 0, buy = prices[0], profit = 0;

    for (i = 1; i < pricesSize; i++) {
        if (state) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
                // printf("Keep selling: i=%d, price=%d, profit=%d\n", i, prices[i], profit);
            } else {
                state = 0;
                buy = prices[i];
                // printf("Stop selling: i=%d, price=%d, profit=%d\n", i, prices[i], profit);
            }
        } else {
            if (prices[i] < prices[i-1]) {
                buy = prices[i];
                // printf("New buy point: i=%d, price=%d, profit=%d\n", i, prices[i], profit);
            } else {
                state = 1;
                profit += prices[i] - buy;
                // printf("Start selling: i=%d, price=%d, profit=%d\n", i, prices[i], profit);
            }
        }
    }

    return profit;
}