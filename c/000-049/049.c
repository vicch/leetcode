#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize);
int* getCounts(char* str);
int countsMatch(int* a, int* b);

int main()
{
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int* csizes;
    int size;
    char*** anas = groupAnagrams(strs, 6, &csizes, &size);

    return 0;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize)
{
    int i, j;

    // [ [0,0,...], ... ] // Counts of 26 letters
    int** counts = malloc(sizeof(int*) * strsSize);

    char*** groups = malloc(sizeof(char**) * strsSize);
    for (i = 0; i < strsSize; i++)
        groups[i] = malloc(sizeof(char*) * strsSize);

    *columnSizes = malloc(sizeof(int*) * strsSize);
    memset(*columnSizes, 0, sizeof(*columnSizes));
    *returnSize = 0;

    int match;
    int* curCount;
    for (i = 0; i < strsSize; i++) {
        curCount = getCounts(strs[i]);
        match = 0;
        for (j = 0; j < *returnSize; j++) {
            if (countsMatch(counts[j], curCount)) {
                match = 1;
                break;
            }
        }
        if (match == 1) {
            free(curCount);
            // Add word to existing group
            groups[j][*columnSizes[j]] = malloc(sizeof(char) * strlen(strs[i]));
            strcpy(groups[j][*columnSizes[j]], strs[i]);
            (*columnSizes[j])++;
        } else {
            // Add new counts
            counts[*returnSize] = curCount;
            // Add word to new group
            groups[*returnSize][0] = malloc(sizeof(char) * strlen(strs[i]));
            strcpy(groups[*returnSize][0], strs[i]);
            (*columnSizes[*returnSize])++;
            (*returnSize)++;
        }
    }

    for (i = 0; i < *returnSize; i++)
        free(counts[i]);
    free(counts);

    return groups;
}

int* getCounts(char* str)
{
    int* counts = malloc(sizeof(int) * 26);
    memset(counts, 0, sizeof(counts));
    for (; *str != '\0'; str++)
        counts[*str - '0']++;
    return counts;
}

int countsMatch(int* a, int* b)
{
    int i;
    for (i = 0; i < 26; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}