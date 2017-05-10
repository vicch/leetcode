// Problem:
// Given a collection of intervals, merge all overlapping intervals.
// 
// Example:
// Input: [1,3], [2,6], [8,10], [15,18]
// Output: [1,6], [8,10], [15,18]
// 
// Solution:
// Sort intervals ascendingly by start and end. By iterating the intervals,
// compare its start and the last merged interval's end to decide if they can
// be merged.

#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int main()
{
    return 0;
}

/********** Solution **********/

int cmpinterval(const void* a, const void* b);

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize)
{
    *returnSize = 0;

    if (intervalsSize == 0)
        return NULL;

    int i;
    struct Interval* ret = malloc(sizeof(struct Interval) * intervalsSize);

    qsort(intervals, intervalsSize, sizeof(struct Interval), cmpinterval);

    for (i = 0; i < intervalsSize; i++) {
        // Add new interval
        if (i == 0 || intervals[i].start > ret[*returnSize - 1].end) {
            (*returnSize)++;
            ret[*returnSize - 1].start = intervals[i].start;
            ret[*returnSize - 1].end   = intervals[i].end;
        // Merge interval
        } else if (intervals[i].end > ret[*returnSize - 1].end) {
            ret[*returnSize - 1].end = intervals[i].end;
        }
    }

    return ret;
}

int cmpinterval(const void* a, const void* b)
{
    if (((struct Interval*)a)->start != ((struct Interval*)b)->start)
        return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
    else
        return ((struct Interval*)a)->end - ((struct Interval*)b)->end;
}