#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows);

int main()
{
    // char* str = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    // char* res = convert(str, 3);

    char* str = "ABCD";
    char* res = convert(str, 3);

    printf("%s\n", res);

    return 0;
}

char* convert(char* s, int numRows)
{
    if (numRows == 1) return s;

    int sl = strlen(s), nl = 0;
    int i, j;
    char* new = malloc(sizeof(char) * (sl + 1));

    // First row
    for (i = 0; i < sl; i += (numRows - 1) * 2)
        new[nl++] = s[i];

    // Middle rows
    for (i = 1; i < numRows - 1; i++) {
        for (j = 0; j - i < sl; j += (numRows - 1) * 2) {
            if (j > 0)      new[nl++] = s[j - i];
            if (j + i < sl) new[nl++] = s[j + i];
        }
    }

    // Last row
    for (i = numRows - 1; i < sl; i += (numRows - 1) * 2)
        new[nl++] = s[i];

    new[nl] = '\0';

    return new;
}