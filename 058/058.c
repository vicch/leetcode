#include <stdio.h>

int lengthOfLastWord(char* s);

int main()
{
    printf("%d\n", lengthOfLastWord("b   a    "));

    return 0;
}

int lengthOfLastWord(char* s)
{
    int i, len, llen;

    len = llen = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            if (len > 0) {
                llen = len;
            }
            len = 0;
        } else {
            len++;
        }
    }

    return (len == 0) ? llen : len;
}