#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize);

int main()
{
    int gas1[] = {6,1,4,3,5};
    int cost1[] = {3,8,2,4,2};
    printf("%d\n", canCompleteCircuit(gas1, 5, cost1, 5));

    int gas2[] = {1,2,3,4,5};
    int cost2[] = {3,4,5,1,2};
    printf("%d\n", canCompleteCircuit(gas2, 5, cost2, 5));

    int gas3[] = {2,3,1};
    int cost3[] = {3,1,2};
    printf("%d\n", canCompleteCircuit(gas3, 3, cost3, 3));

    return 0;
}

/**
 * First loop: find station X with the biggest "cost-gas" value
 * Second loop: find the first station after station X where "gas-cost>=0"
 */
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int maxDecr, maxIndex, gasTotal, costTotal, i;
    maxDecr = maxIndex = gasTotal = costTotal = 0;
    for (i = 0; i < gasSize; i++) {
        gasTotal += gas[i];
        costTotal += cost[i];
        // Keep record of station X
        if (maxDecr <= cost[i] - gas[i]) {
            maxDecr = cost[i] - gas[i];
            maxIndex = i;
        }
    }
    // If can complete the circuit
    if (gasTotal >= costTotal) {
        for (i = maxIndex + 1; ; i++) {
            // Loop back to first station
            if (i == gasSize) i = 0;
            if (gas[i] >= cost[i]) return i;
        }
    }
    return -1;
}