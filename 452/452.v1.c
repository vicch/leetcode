// Problem:
// There are a number of balloons. For each balloon, provided input is the
// start and end coordinates of the horizontal diameter. Start is always
// smaller than end. An arrow can be shot up from different points along the
// x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
// xstart <= x <= xend. An arrow once shot keeps travelling up infinitely. Find
// the minimum number of arrows that must be shot to burst all balloons. There
// will be at most 10^4 balloons.
// 
// Example:
// Input: [[10,16], [2,8], [1,6], [7,12]]
// Output: 2 (Shoot one arrow at x = 6 (bursting the balloons [2,8] and [1,6])
// and another arrow at x = 11 (bursting the other two balloons).)
// 
// Solution:
// Sort points ascendingly first by start then by end. Compare the start of a
// ballon with a previous ballon's end, it the start is before the end, they
// can share one arrow, otherwise another arrow is needed. Also when one ballon
// is contained in another, ignore the bigger one.

#include <stdio.h>

int main()
{
    return 0;
}

/********** Solution **********/

int cmpPoint(const void* a, const void* b);

int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize)
{
    if (pointsRowSize < 2)
        return pointsRowSize;

    qsort(points, pointsRowSize, sizeof(int) * 2, cmpPoint);

    int s, e, count;

    s = count = 1, e = 0;

    while (s < pointsRowSize) {
        // Ballon s is contained in ballon e
        if (points[s][0] >= points[e][0] && points[s][1] <= points[e][1])
            e = s;
        // Can share one arrow
        if (points[s][0] <= points[e][1])
            s++;
        // Need another arrow
        else
            e = s++, count++;
    }

    return count;
}

int cmpPoint(const void* a, const void* b)
{
    if ((*(int**)a)[0] == (*(int**)b)[0])
        return (*(int**)a)[1] - (*(int**)b)[1];
    else
        return (*(int**)a)[0] - (*(int**)b)[0];
}