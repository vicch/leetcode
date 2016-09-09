#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStrings(char** strs, int count);
char** letterCombinations(char* digits, int* returnSize);
char** getCombinations(char* digits, int* returnSize);
char* getDigits(char c, int* size);

int main()
{
    char digits[] = "234";
    int size;
    char** res = letterCombinations(digits, &size);
    printStrings(res, size);

    return 0;
}

void printStrings(char** strs, int count)
{
    while (count-- > 0) {
        printf(count > 0 ? "%s, " : "%s\n", *(strs++));
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    if (digits == NULL || *digits == '\0') {
        *returnSize = 0;
        return NULL;
    } else if (
        strchr(digits, '1') != NULL ||
        strchr(digits, '0') != NULL ||
        strchr(digits, '*') != NULL ||
        strchr(digits, '#') != NULL
    ) {
        *returnSize = 0;
        return NULL;
    } else {
        return getCombinations(digits, returnSize);
    }
}

char** getCombinations(char* digits, int* returnSize)
{
    if (*digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int thisSize;
    char* this = getDigits(*digits, &thisSize);

    int subSize;
    char** sub = letterCombinations(++digits, &subSize);

    int i, j;
    char** r;

    if (subSize == 0) {
        *returnSize = thisSize;
        r = malloc(sizeof(char*) * *returnSize);
        for (i = 0; i < *returnSize; i++) {
            r[i] = malloc(sizeof(char) * 2);
            sprintf(r[i], "%c%c", this[i], '\0');
        }

    } else {
        *returnSize = thisSize * subSize;
        r = malloc(sizeof(char*) * *returnSize);
        for (i = 0; i < thisSize; i++) {
            for (j = 0; j < subSize; j++) {
                r[i * subSize + j] = malloc(sizeof(char) * (strlen(sub[j]) + 2));
                sprintf(r[i * subSize + j], "%c%s%c", this[i], sub[j], '\0');
            }
        }
    }

    return r;
}

char* getDigits(char c, int* size)
{
    char* digits = malloc(sizeof(char) * 4);

    switch (c) {
        case '2': *size = 3, digits[0] = 'a', digits[1] = 'b', digits[2] = 'c'; break;
        case '3': *size = 3, digits[0] = 'd', digits[1] = 'e', digits[2] = 'f'; break;
        case '4': *size = 3, digits[0] = 'g', digits[1] = 'h', digits[2] = 'i'; break;
        case '5': *size = 3, digits[0] = 'j', digits[1] = 'k', digits[2] = 'l'; break;
        case '6': *size = 3, digits[0] = 'm', digits[1] = 'n', digits[2] = 'o'; break;
        case '7': *size = 4, digits[0] = 'p', digits[1] = 'q', digits[2] = 'r', digits[3] = 's'; break;
        case '8': *size = 3, digits[0] = 't', digits[1] = 'u', digits[2] = 'v'; break;
        case '9': *size = 4, digits[0] = 'w', digits[1] = 'x', digits[2] = 'y', digits[3] = 'z'; break;
        default: break;
    }

    return digits;
}