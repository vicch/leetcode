// Problem:
// Given an integer array with all positive numbers and no duplicates, find the
// number of possible combinations that add up to a positive integer target.
// Different sequences are counted as different combinations.
// 
// Example:
// Input: [1, 2, 3], 4
// Output: 7, possible combinations:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

#include <stdio.h>
#include <string.h>

int combinationSum4(int* nums, int numsSize, int target);

int main()
{
    // int n1[] = {1, 2, 3};
    // printf("%d\n", combinationSum4(n1, 3, 6));

    int n2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    printf("%d\n", combinationSum4(n2, 100, 31));

    int n3[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    printf("%d\n", combinationSum4(n3, 100, 999));

    int n4[] = {154,34,208,358,427,52,328,493,304,346,118,325,7,226,169,178,499,460,349,430,259,172,400,43,451,82,409,313,175,91,289,40,205,391,343,214,307,28,418,199,241,310,238,268,244,319,1,457,124,265,496,490,130,49,181,148,316,448,397,88,337,424,136,160,229,25,100,112,46,76,166,211,94,247,142,334,322,271,352,70,367,232,58,379,133,361,394,292,4,115,286,13,64,472,16,364,196,466,433,22,415,193,445,421,301,220,31,250,340,277,145,184,382,262,202,121,373,190,388,475,478,223,163,454,370,481,109,19,73,10,376,217,487,283,151,187,439,295,67,355,385,106,463,139,37,298,253,61,442,127,103,403,97,274,484,469,412,280,235,256,406,436,157,79,85,55};
    printf("%d\n", combinationSum4(n4, 166, 50));

    return 0;
}

/********** Solution **********/

int combinationSub(int* nums, int nsize, int nindex, int target, int* solution, int sindex, int* cache);
int arrangement(int* nums, int size);
int cmpNum(const void * a, const void * b);

int combinationSum4(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmpNum);

    // Ignore numbers greater than target
    for (; numsSize > 0 && nums[numsSize - 1] > target; numsSize--)
        ;

    if (numsSize == 0 || target == 0)
        return 0;
    
    // Need to know the maximum number of solutions without hash map
    int solution[numsSize * 7000];
    int cache[(target + 1) * numsSize];
    int scount, total, i;

    memset(solution, 0, sizeof(solution));
    memset(cache, -1, sizeof(cache));

    scount = combinationSub(nums, numsSize, 0, target, solution, 0, cache);

    for (total = i = 0; i < scount; i++)
        total += arrangement(solution + numsSize * i, numsSize);

    return total;
}

int combinationSub(int* nums, int nsize, int nindex, int target, int* solution, int sindex, int* cache)
{
    if (cache[target * nsize + nindex] == 0)
        return 0;

    if (nindex == nsize || nums[nindex] > target)
        return cache[target * nsize + nindex] = (target == 0);

    int scount, soffset, i, j;

    for (scount = soffset = i = 0; nums[nindex] * i <= target; i++) {
        scount += combinationSub(nums, nsize, nindex + 1, target - nums[nindex] * i, solution, sindex + soffset, cache);
        for (j = soffset; j < scount; j++)
            solution[(sindex + j) * nsize + nindex] = i;
        soffset = scount;
    }

    return cache[target * nsize + nindex] = scount;
}

int arrangement(int* nums, int size)
{
    int sum, total, i, j;

    for (sum = i = 0, total = 1; i < size; i++) {
        for (j = 1; j <= nums[i]; j++) {
            total *= sum + j;
            total /= j;
        }
        sum += nums[i];
    }

    return total;
}

int cmpNum(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}