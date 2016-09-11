#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char* multiply(char* num1, char* num2);
char* multiplySingle(char* n, int t);
char* addStrings(char* a, char* b, int d);

int main()
{
    printf("%s\n", multiply("11", "11"));
    printf("%s\n", multiply("9369162965141127216164882458728854782080715827760307787224298083754", "7204554941577564438"));
    printf("%s\n", multiply("1292903509936727404199686220192411623085", "9996190433341303536650999221082973702747291324607482481306424831201698419742124862320482024"));

    return 0;
}

char* multiply(char* num1, char* num2)
{
    char* r = malloc(sizeof(char) * 2);
    strcpy(r, "0");

    if (num1[0] != '0' && num2[0] != '0') {
        int l1 = strlen(num1), l2 = strlen(num2), i;

        char** prods = malloc(sizeof(char*) * 10);
        for (i = 0; i < 10; i++) {
            prods[i] = multiplySingle(num1, i);
        }

        char* rtmp = NULL;
        for (i = l2 - 1; i >= 0; i--) {
            rtmp = r;
            r = addStrings(rtmp, prods[num2[i] - '0'], l2 - i - 1);
            if (rtmp && sizeof(rtmp)) free(rtmp);
        }

        while (*r == '0') r++;
    }

    return r;
}

char* multiplySingle(char* n, int t)
{
    char* r;

    if (t == 0) {
        r = malloc(sizeof(char) * 2);
        strcpy(r, "0");

    } else {
        int l = strlen(n) + 1, d = 0, c = 0, i;
        r = malloc(sizeof(char) * (l + 1));

        for (i = l - 1; i > 0; i--) {
            d = (n[i - 1] - '0') * t + c;
            r[i] = (d % 10) + '0';
            c = d / 10;
        }
        r[0] = c + '0';
        r[l] = '\0';
    }

     return r;
}

/**
 * 1234 + 123 * 10 = addStrings("1234", "123", 1)
 */
char* addStrings(char* a, char* b, int d)
{
    int al = strlen(a), bl = strlen(b), sl = MAX(al, bl + d) + 1;
    char* sum = malloc(sizeof(char) * (sl + 1));
    int ad, bd, sd = 0, c = 0;

    sum[sl] = '\0';
    for (al--, sl--; d > 0; d--, al--, sl--) {
        sum[sl] = (al >= 0) ? a[al] : '0';
    }
    for (bl--; sl >= 0; al--, bl--, sl--) {
        ad = (al >= 0) ? a[al] - '0' : 0;
        bd = (bl >= 0) ? b[bl] - '0' : 0;
        sd = ad + bd + c;
        c = sd / 10;
        sd %= 10;
        sum[sl] = sd + '0';
    }

    return sum;
}