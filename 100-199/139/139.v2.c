#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int

struct letter {
    bool end; // If a dict word ends on this letter
    struct letter* next[26];
};

void printTree(struct letter* head, int level);

bool wordBreak(char* s, char** wordDict, int wordDictSize);
bool wordBreakSub(char* s, struct letter* head);
void addWord(struct letter* head, char* word);
struct letter* newLetter(void);

int main()
{
    char s1[] = "leetcode";
    char* d1[2];
    d1[0] = "leet";
    d1[1] = "code";
    printf("%d\n", wordBreak(s1, d1, 2));

    char s2[] = "cars";
    char* d2[3];
    d2[0] = "car";
    d2[1] = "ca";
    d2[2] = "rs";
    printf("%d\n", wordBreak(s2, d2, 3));

    char s3[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char* d3[10];
    d3[0] = "a";
    d3[1] = "aa";
    d3[2] = "aaa";
    d3[3] = "aaaa";
    d3[4] = "aaaaa";
    d3[5] = "aaaaaa";
    d3[6] = "aaaaaaa";
    d3[7] = "aaaaaaaa";
    d3[8] = "aaaaaaaaa";
    d3[9] = "aaaaaaaaaa";
    printf("%d\n", wordBreak(s3, d3, 10));

    return 0;
}

void printTree(struct letter* head, int level)
{
    int i;
    for (i = 0; i < 26; i++) {
        if (head->next[i]) {
            printf("%*s", level, "");
            printf("%c(%d)\n", 'a'+i, head->next[i]->end);
            printTree(head->next[i], level+1);
        }
    }
    return;
}

/**
 * Build a letter tree of all dict words
 */
bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    if (*s == '\0' || wordDictSize == 0)
        return 0;

    int i;
    struct letter* head = newLetter();

    for (i = 0; i < wordDictSize; i++)
        if (!wordBreakSub(wordDict[i], head))
            addWord(head, wordDict[i]);

    // printTree(head, 0);

    return wordBreakSub(s, head);
}

bool wordBreakSub(char* s, struct letter* head)
{
    if (*s == '\0')
        return 1;

    // printf("string=%s\ntree=\n", s);
    // printTree(head, 0);

    int i;
    struct letter* p;
    for (p = head, i = *s - 'a'; *s && p->next[i]; p = p->next[i], s++, i = *s - 'a') {
        if (p->next[i]->end && wordBreakSub(s+1, head))
            return 1;
    }
    // String and word both finished
    return (*s == '\0' && p->end);
}

void addWord(struct letter* head, char* word)
{
    // printf("word=%s\n", word);
    if (*word == '\0') {
        head->end = 1;
    } else {
        int i = *word - 'a';
        if (!head->next[i])
            head->next[i] = newLetter();
        addWord(head->next[i], word+1);
    }
    return;
}

struct letter* newLetter(void)
{
    struct letter* new = malloc(sizeof(struct letter));
    new->end = 0;
    memset(new->next, 0, sizeof(new->next));
    return new;
}