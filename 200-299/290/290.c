#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

bool wordPattern(char* pattern, char* str);
char* getWord(char** str);

int main()
{
    printf("%d\n", wordPattern("abab", "cat dog cat dog"));
    printf("%d\n", wordPattern("abba", "dog cat cat fish"));
    printf("%d\n", wordPattern("a", "dog"));
    printf("%d\n", wordPattern("ab", "dog"));
    printf("%d\n", wordPattern("abba", "dog dog dog dog"));
    printf("%d\n", wordPattern("aaa", "dog dog dog dog"));

    return 0;
}

bool wordPattern(char* pattern, char* str)
{
    char** map = malloc(sizeof(char*) * 26);
    char* word;
    int i;

    // Init mapping
    for (i = 0; i < 26; i++) map[i] = NULL;

    while (*pattern != '\0') {
        word = getWord(&str);

        // String reaches end before pattern does
        if (*word == '\0') return 0;

        if (map[*pattern - 'a'] != NULL) {
            // Compare mapping
            if (strcmp(map[*pattern - 'a'], word)) return 0;

        } else {
            // Fail if mapping for this word already exists
            for (i = 0; i < 26; i++)
                if (map[i] != NULL && !strcmp(map[i], word)) return 0;

            // Set mapping
            map[*pattern - 'a'] = word;
        }

        pattern++;
    }

    // Fail if pattern has not reached end
    return *str == '\0';
}

/**
 * Get word from string, set string pointer to the start of next word
 */
char* getWord(char** str)
{
    char* word = malloc(sizeof(char) * 50);
    int i;

    for (i = 0; **str != ' ' && **str != '\0'; (*str)++, i++)
        word[i] = **str;

    if (**str == ' ') (*str)++;
    word[i] = '\0';

    return word;
}