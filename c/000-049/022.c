#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStrings(char** strs, int count);
char** generateParenthesis(int n, int* returnSize);
int power(int b, int p);
char* convert(int n, int w);
char* concatStr(char* a, char* b, char* c);

int main()
{
    int size;
    char** res = generateParenthesis(4, &size);
    printStrings(res, size);

    return 0;
}

void printStrings(char** strs, int count)
{
    while (count-- > 0) {
        printf(count > 0 ? "%s, " : "%s\n", *(strs++));
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    int max = power(4, n - 1), i;
    char** ret = malloc(sizeof(char*) * max);
    char* sol;

    *returnSize = 0;

    for (i = 0; i < max; i++) {
        if ((sol = convert(i, 2 * (n - 1))) != NULL) {
            ret[(*returnSize)++] = concatStr("(", sol, ")");
        }
    }

    return ret;
}

int power(int b, int p)
{
    int i = 1;
    while (p-- > 0)
        i *= b;
    return i;
}

/**
 * Convert number to parenthese pattern
 * n=3,  w=4 -> 0011   -> (())
 * n=11, w=6 -> 001011 -> (()())
 * n=4,  w=4 -> 0100   -> NULL
 */
char* convert(int n, int w)
{
    int s = 0, i, j;
    char* str = malloc(sizeof(char) * (w + 1));

    for (j = w - 1; j >= 0 && s >= -1; j--, n >>= 1) {
        i = n % 2;
        if (i == 0) {
            str[j] = '(';
            s--;
        } else {
            str[j] = ')';
            s++;
        }
    }
    str[w] = '\0';

    return (s == 0 && j < 0) ? str : NULL;
}

char* concatStr(char* a, char* b, char* c)
{
    char* ret = malloc(sizeof(char) * (strlen(a) + strlen(b) + strlen(c) + 1));
    strcat(ret, a);
    strcat(ret, b);
    strcat(ret, c);
    return ret;
}