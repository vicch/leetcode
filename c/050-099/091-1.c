#include <stdio.h>

#define INRANGE(n, a, b) ((n) >= (a) && (n) <= (b))

int numDecodings(char* s);
int numDecodingsSub(char* s);

int main()
{
    printf("%d\n", numDecodings("0"));
    printf("%d\n", numDecodings("10"));
    printf("%d\n", numDecodings("101"));
    printf("%d\n", numDecodings("12304"));
    printf("%d\n", numDecodings("12345"));
    printf("%d\n", numDecodings("7893749912342187894921836847319981199844151766195952528631828655978178193192959793156142441128167383"));

    return 0;
}

int numDecodings(char* s)
{
    if (s[0] == '\0') return 0;
    return numDecodingsSub(s);
}

int numDecodingsSub(char* s)
{
    // Skip "3" to "9" because they don't contribute to decoding possibilities
    for (; INRANGE(s[0], '3', '9'); s++);

    if (s[0] == '\0') return 1;
    if (!INRANGE(s[0], '1', '9')) return 0;

    int num = numDecodingsSub(s+1);
    if ((s[0] == '1' && INRANGE(s[1], '0', '9')) || (s[0] == '2' && INRANGE(s[1], '0', '6')))
        num += numDecodingsSub(s+2);

    return num;
}