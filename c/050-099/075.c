#include <stdio.h>

void sortColors(int* nums, int numsSize);

int main()
{

}

void sortColors(int* nums, int numsSize)
{
    int h = 0, t = numsSize - 1;
    int cnt[] = {0, 0, 0};

    while (h <= t) {
        if (nums[h] == 0)
            h++;
        else if (nums[t] == 0) {
            cnt[nums[h]]++;
            nums[h++] = 0;
            t--;
        } else
            cnt[nums[t--]]++;
    }

    while (cnt[1]-- > 0) nums[h++] = 1;
    while (cnt[2]-- > 0) nums[h++] = 2;

    return;
}