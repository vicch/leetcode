#include <stdio.h>

void sortColors(int* nums, int numsSize);

int main()
{

}

/**
 * Head pointer expects 0, if 1 or 2 shows, fetch a 0 from tail to overwrite,
 * and count the numbers of 1s and 2s encountered. When head and tail meets,
 * write the rest with 1s and 2s.
 */
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