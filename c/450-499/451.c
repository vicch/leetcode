// Problem:
// Sort a given string in decreasing order based on the frequency of characters.
// Letters are case-sensitive.

// Example:
// Input: tree
// Output: eetr

// Solution:
// - Array A contains characters to numbers of occurrences.
// - Array B contains distinct characters
// Sort characters in B by looking up its number of occurrence in A, then iterate
// B to make a new string by repeating each character A[c] times.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* frequencySort(char* s);
int cmpLetters(const void* a, const void* b);

int times[256];

int main()
{
    printf("%s\n", frequencySort("tree"));
    printf("%s\n", frequencySort("Aabb"));

    return 0;
}

char* frequencySort(char* s)
{
    char letters[256];
    int i, j, k, lnum;

    // Init occurrences as 0
    memset(times, 0, sizeof(times));

    for (i = lnum = 0; s[i] != '\0'; i++)
        if (times[s[i]]++ == 0)
            letters[lnum++] = s[i];

    // Sort letters by number of occurrences
    qsort(letters, lnum, sizeof(char), cmpLetters);

    char* new = malloc(sizeof(char) * (i + 1));

    for (j = k = 0; j < lnum; j++)
        for (i = 0; i < times[letters[j]]; i++)
            new[k++] = letters[j];
    new[k] = '\0';

    return new;
}

int cmpLetters(const void* a, const void* b)
{
    return times[*(char*)b] - times[*(char*)a];
}