#include <stdio.h>
#include <stdlib.h>

void printArray(int* seq, int count);
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);

int main()
{
    printf("%d\n", computeArea(-3,0,3,4,0,-1,9,2));
    printf("%d\n", computeArea(0,0,0,0,-1,-1,1,1));
    printf("%d\n", computeArea(-2,-2,2,2,3,3,4,4));
    printf("%d\n", computeArea(0,0,50000,40000,0,0,50000,40000));

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    }
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s = (C - A) * (D - B) + (G - E) * (H - F);

    if (A >= G || E >= C || B >= H || F >= D)
        return s;

    int x1 = A > E ? A : E;
    int x2 = C < G ? C : G;
    int y1 = B > F ? B : F;
    int y2 = D < H ? D : H;

    return s - (x2 - x1) * (y2 - y1);
}