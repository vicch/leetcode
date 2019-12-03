#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main()
{
    char* strs[3];

    strs[0] = "Test";
    strs[1] = "Tes";
    strs[2] = "Test1";

    printf("%s\n", longestCommonPrefix(strs, 3));
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
    int i, j;
    char c;
    char* common = malloc(1000);

    if (strsSize <= 0)
        return "";

    if (strsSize == 1)
        return strs[0];

    for (i = 0; (c = strs[0][i]) != '\0'; i++) {
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                common[i] = '\0';
                return common;
            }
        }
        common[i] = c;
    }
    common[i] = '\0';

    return common;    
}