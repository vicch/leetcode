#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseVowels(char* s);

int main()
{
    char* str1 = malloc(sizeof(char) * 6);
    strcpy(str1, "hello");
    printf("%s\n", reverseVowels(str1));

    char* str2 = malloc(sizeof(char) * 9);
    strcpy(str2, "leetcode");
    printf("%s\n", reverseVowels(str2));

    char* str3 = malloc(sizeof(char) * 9);
    strcpy(str3, "aeiouaei");
    printf("%s\n", reverseVowels(str3));

    char* str4 = malloc(sizeof(char) * 9);
    strcpy(str4, "hfjncidf");
    printf("%s\n", reverseVowels(str4));

    char* str5 = malloc(sizeof(char) * 3);
    strcpy(str5, "Aa");
    printf("%s\n", reverseVowels(str5));

    return 0;
}

char* reverseVowels(char* s)
{
    int sl = strlen(s), vl, i;
    char** vowels = malloc(sizeof(char*) * sl);
    char tmp;

    // Get vowel pointers
    for (i = 0, vl = 0; i < sl; i++) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels[vl++] = s + i;
        }
    }

    // Swap vowels
    for (i = 0; i < vl / 2; i++) {
        tmp = *vowels[i];
        *vowels[i] = *vowels[vl-i-1];
        *vowels[vl-i-1] = tmp;
    }

    return s;
}