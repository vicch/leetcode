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
// Sort points by end position first. The strategy is to shoot at the end of
// the first ballon to cover as many ballons as possible. When the first arrow
// cannot cover the next ballon (its start position > current arrow position),
// shoot at next ballon's end position and continue.

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

    int count, arrow, i;

    for (i = count = 1, arrow = points[0][1]; i < pointsRowSize; i++) {
        if (arrow < points[i][0]) {
            count++;
            arrow = points[i][1];
        }
    }

    return count;
}

int cmpPoint(const void* a, const void* b)
{
    if ((*(int**)a)[1] == (*(int**)b)[1])
        return (*(int**)a)[0] - (*(int**)b)[0];
    else
        return (*(int**)a)[1] - (*(int**)b)[1];
}