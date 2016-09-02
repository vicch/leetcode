#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b);

int main()
{
    printf("%s\n", addBinary("10000011", "111000"));

    return 0;
}

char* addBinary(char* a, char* b)
{
    int al = strlen(a);
    int bl = strlen(b);
    int rl = (al > bl ? al : bl) + 2;
    int sum = 0, i;
    char* r = malloc(sizeof(char) * rl);

    int getBinary(char* s, int i);

    for (i = 0; i < rl - 1; i++) {
        r[i] = '0';
    }
    r[--rl] = '\0';
    
    for (al--, bl--, rl--; (al >= 0) || (bl >= 0); al--, bl--, rl--) {
        sum = getBinary(a, al) + getBinary(b, bl) + getBinary(r, rl);
        r[rl-1] = (sum / 2) + '0';
        r[rl]   = (sum % 2) + '0';
    }

    return (r[0] == '1') ? r : &r[1];
}

int getBinary(char* s, int i)
{
    if (i < 0 || s[i] == 0) {
        return 0;
    } else {
        return s[i] - '0';
    }
}