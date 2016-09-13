#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* seq, int count);

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize);
int* getCounts(char* str);
int countsMatch(int* a, int* b);

int main()
{
    // char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // int* csizes;
    // int size;
    // char*** anas = groupAnagrams(strs, 6, &csizes, &size);

    // char* strs[] = {"ape", "pea", "tax"};
    // int* csizes;
    // int size;
    // char*** anas = groupAnagrams(strs, 3, &csizes, &size);

    char* strs[] = {"tea", "and", "ace", "ad", "eat", "dans"};
    int* csizes;
    int size;
    char*** anas = groupAnagrams(strs, 6, &csizes, &size);

    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < csizes[i]; j++) {
            printf("%s,", anas[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void printArray(int* seq, int count)
{
    printf("[");
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d]\n", *seq++);
    return;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize)
{
    int i, j, match, len;

    // Size of each anagram
    int* sizes = malloc(sizeof(int));

    // [ [0,0,...], ... ] // Letters count of each anagram
    int** counts = malloc(sizeof(int*));
    int* curCount;

    char*** groups = malloc(sizeof(char**) * strsSize);
    for (i = 0; i < strsSize; i++)
        groups[i] = malloc(sizeof(char*));

    *columnSizes = malloc(sizeof(int));
    (*columnSizes)[0] = 0;
    *returnSize = 0;
    
    for (i = 0; i < strsSize; i++) {
        match = 0;
        len = strlen(strs[i]);
        curCount = getCounts(strs[i]);
        if (*returnSize > 0) {
            for (j = 0; j < *returnSize; j++) {
                if (len == sizes[j] && countsMatch(counts[j], curCount)) {
                    match = 1;
                    break;
                }
            }
        }
        if (match == 1) {
            free(curCount);
            // Add word to existing group
            groups[j] = (char**)realloc(groups[j], sizeof(char*) * ((*columnSizes)[j] + 1));
            groups[j][(*columnSizes)[j]] = strs[i];
            (*columnSizes)[j]++;
        } else {
            // Add new anagram
            counts = (int**)realloc(counts, sizeof(int*) * (*returnSize + 1));
            counts[*returnSize] = curCount;
            sizes = (int*)realloc(sizes, sizeof(int) * (*returnSize + 1));
            sizes[*returnSize] = len;
            // Add word to new anagram group
            
            groups[*returnSize][0] = strs[i];
            *columnSizes = (int*)realloc(*columnSizes, sizeof(int) * (*returnSize + 1));
            (*columnSizes)[*returnSize] = 1;
            (*returnSize)++;
        }
    }

    free(sizes);
    for (i = 0; i < *returnSize; i++)
        free(counts[i]);
    free(counts);

    return groups;
}

int* getCounts(char* str)
{
    int* counts = malloc(sizeof(int) * 26);
    int i;
    for (i = 0; i < 26; i++)
        counts[i] = 0;
    for (; *str != '\0'; str++)
        counts[*str - 'a']++;
    return counts;
}

int countsMatch(int* a, int* b)
{
    int i;
    for (i = 0; i < 26; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}