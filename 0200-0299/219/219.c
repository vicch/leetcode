#include <stdio.h>
#include <stdlib.h>

typedef int bool;

struct Node {
    int val;
    int idx;
};

int cmpNode(const void * a, const void * b);
bool containsNearbyDuplicate(int* nums, int numsSize, int k);

int main()
{
    int nums[] = {1,2,1};
    printf("%d\n", containsNearbyDuplicate(nums, 3, 2));

    return 0;
}

int cmpNode(const void * a, const void * b)
{
    if (((struct Node*)a)->val != ((struct Node*)b)->val)
        return ((struct Node*)a)->val - ((struct Node*)b)->val;
    else
        return ((struct Node*)a)->idx - ((struct Node*)b)->idx;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    if (numsSize < 2 || k < 1)
        return 0;

    struct Node* lst = malloc(sizeof(struct Node) * numsSize);
    int i;

    for (i = 0; i < numsSize; i++) {
        lst[i].val = nums[i];
        lst[i].idx = i;
    }

    qsort(lst, numsSize, sizeof(struct Node), cmpNode);

    while (numsSize-- > 0) {
        if (lst->val == (lst + 1)->val && (lst + 1)->idx - lst->idx <= k)
            return 1;
        lst++;
    }

    return 0;
}