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
 * If it cannot reach B from A, then it cannot reach B from any station between
 * A and B, so if the circuit can be completed, it must start from B+1, and the
 * gas left in the end must be able to cover all the previous shortages
 */
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int start, gasNeed, gasTank, i;
    for (i = start = gasNeed = gasTank = 0; i < gasSize; i++) {
        if ((gasTank += gas[i] - cost[i]) < 0) {
            start = i + 1;
            gasNeed += gasTank;
            gasTank = 0;
        }
    }
    return (gasNeed + gasTank < 0) ? -1 : start;
}