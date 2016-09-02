#include <stdio.h>

int romanToInt(char* s);
int romanValue(char c);

int main()
{
    printf("%s:%d\n", "III", romanToInt("III"));
    printf("%s:%d\n", "V", romanToInt("V"));
    printf("%s:%d\n", "VII", romanToInt("VII"));
    printf("%s:%d\n", "IX", romanToInt("IX"));
    printf("%s:%d\n", "XVI", romanToInt("XVI"));
    printf("%s:%d\n", "XXIV", romanToInt("XXIV"));
    printf("%s:%d\n", "MDCCC", romanToInt("MDCCC"));

    return 0;
}

int romanToInt(char* s)
{
    int  i, cur, next, group, total;

    cur = next = group = total = 0;
    for (i = 0; s[i] != '\0'; i++) {
        cur = (i > 0) ? next : romanValue(s[i]);
        next = romanValue(s[i+1]);

        group += cur;
        if (cur != next) {
            if (cur < next) {
                total -= group;
            } else {
                total += group;
            }
            group = 0;
        }
    }
    total += group;

    return total;
}

int romanValue(char c)
{
    switch (c) {
        case 'I':
        case 'i':
            return 1;
        case 'V':
        case 'v':
            return 5;
        case 'X':
        case 'x':
            return 10;
        case 'L':
        case 'l':
            return 50;
        case 'C':
        case 'c':
            return 100;
        case 'D':
        case 'd':
            return 500;
        case 'M':
        case 'm':
            return 1000;
        default:
            return 0;
    }
}