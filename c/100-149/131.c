#include <stdio.h>
#include <stdlib.h>

void printStrGroups(char*** groups, int* colSizes, int size);

char*** partition(char* s, int** columnSizes, int* returnSize);
char* copyChars(char* s, int n);

int main()
{
    char* str1 = "aab";
    int* cols1;
    int size1;
    char*** pars1 = partition(str1, &cols1, &size1);
    printf("Partitions:\n");
    printStrGroups(pars1, cols1, size1);

    return 0;
}

void printStrGroups(char*** groups, int* colSizes, int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        printf("[");
        for (j = 0; j < colSizes[i]; j++) {
            printf((j < colSizes[i]-1) ? "\"%s\"," : "\"%s\"", groups[i][j]);
        }
        printf("]\n");
    }
}

/**
 * If first N characters are palindrome, recursively find partitions for the rest
 * of the string, and join first N characters with partitions
 */
char*** partition(char* s, int** columnSizes, int* returnSize)
{
    if (s[0] == '\0') return NULL;

    int i, j, k;

    char*** parts = NULL;
    *columnSizes = NULL;
    *returnSize = 0;

    char* base = NULL;
    char*** subParts;
    int* subColumnSizes;
    int subReturnSize;

    for (i = 0; s[i] != '\0'; i++) {
        // Check if first i+1 characters are palindrome
        for (j = 0; j < (i+1) / 2 && s[j] == s[i-j]; j++);
        if (j != (i+1) / 2) continue;

        base = copyChars(s, i+1);

        // s[i] is last character
        if (s[i+1] == '\0') {
            *columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize + 1));
            parts = realloc(parts, sizeof(char**) * (*returnSize + 1));

            (*columnSizes)[*returnSize] = 1;
            parts[*returnSize] = malloc(sizeof(char*));
            parts[*returnSize][0] = base;
            (*returnSize)++;

        } else {
            subColumnSizes = NULL;
            subReturnSize = 0;
            subParts = partition(s+i+1, &subColumnSizes, &subReturnSize);

            if (subReturnSize) {
                *columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize + subReturnSize));
                parts = realloc(parts, sizeof(char**) * (*returnSize + subReturnSize));

                for (j = 0; j < subReturnSize; j++) {
                    (*columnSizes)[*returnSize] = subColumnSizes[j]+1;
                    parts[*returnSize] = malloc(sizeof(char*) * (*columnSizes)[*returnSize]);
                    parts[*returnSize][0] = base;
                    for (k = 0; k < subColumnSizes[j]; k++)
                        parts[*returnSize][k+1] = subParts[j][k];
                    (*returnSize)++;

                    free(subParts[j]);
                }

                free(subParts);
                free(subColumnSizes);
            }
        }
    }

    return parts;
}

/**
 * Create a copy of the first N characters of a string
 */
char* copyChars(char* s, int n)
{
    char* str = malloc(sizeof(char) * (n+1));
    str[n] = '\0';
    for (n -= 1; n >= 0; n--)
        str[n] = s[n];
    return str;
}