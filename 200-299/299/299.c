#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getHint(char* secret, char* guess);
int getInterCount(char* a, char* b, int n);
int cmpChar(const void * a, const void * b);
void printArray(char* seq, int count);

int main()
{
    printf("%s, %s: %s\n", "1807", "7810", getHint("1807", "7810"));
    printf("%s, %s: %s\n", "1123", "0111", getHint("1123", "0111"));
    printf("%s, %s: %s\n", "1111", "2222", getHint("1111", "2222"));
    printf("%s, %s: %s\n", "2222", "2222", getHint("2222", "2222"));
    printf("%s, %s: %s\n", "1234", "4321", getHint("1234", "4321"));

    return 0;
}

char* getHint(char* secret, char* guess)
{
    int l = strlen(secret);
    int bull = 0, cow = 0, seqc = 0;
    char* hint = malloc(sizeof(char) * 4);
    char* sseq = malloc(sizeof(char) * l);
    char* gseq = malloc(sizeof(char) * l);

    for (; *secret != '\0'; secret++, guess++) {
        if (*secret == *guess)
            bull++;
        else {
            sseq[seqc] = *secret;
            gseq[seqc] = *guess;
            seqc++;
        }
    }

    cow = getInterCount(sseq, gseq, seqc);
    sprintf(hint, "%dA%dB", bull, cow);

    return hint;
}

/* Get the count of intersection elements of two integer sequences */
int getInterCount(char* a, char* b, int n)
{
    qsort(a, n, sizeof(char), cmpChar);
    qsort(b, n, sizeof(char), cmpChar);

    char* ap = a;
    char* bp = b;
    int i = 0;

    while (ap < a + n && bp < b + n) {
        if (*ap < *bp) ap++;
        else if (*ap > *bp) bp++;
        else ap++, bp++, i++;
    }

    return i;
}

int cmpChar(const void * a, const void * b)
{
    return (*(char*)a - *(char*)b);
}

void printArray(char* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%c," : "%c", *seq++);
    }
    printf("\n");
}