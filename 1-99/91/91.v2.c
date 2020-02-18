#include <stdio.h>

int numDecodings(char* s);

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

/**
 * F(N) = Number of decoding ways till digit N
 * If digit N-1 and N can be decoded as a combination, F(N) = F(N-1) + F(N-2)
 * Else, F(N) = F(N-1)
 */
int numDecodings(char* s)
{
    if (*s == '\0' || *s == '0') return 0;

    int r1 = 1; // Decoding ways of N-1
    int r2 = 1; // Decoding ways of N-2

    for (; *s != '\0'; s++) {
        // 0 voids ways of N-1 because 0 cannot be decoded separately
        if (*s == '0') r1 = 0;

        // Possible 2-digit combination, new r1 is sum of both, new r2 is the old r1
        if (*(s-1) == '1' || *(s-1) == '2' && *s <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;

        // 1-digit, no new way added
        } else {
            r2 = r1;
        }
    }

    return r1;
}