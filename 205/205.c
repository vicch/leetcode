#include <stdio.h>

typedef int bool;

int main()
{
    printf("%s, %s, %d\n", "egg", "add", isIsomorphic("egg", "add"));
    printf("%s, %s, %d\n", "foo", "bar", isIsomorphic("foo", "bar"));
    printf("%s, %s, %d\n", "paper", "title", isIsomorphic("paper", "title"));
    printf("%s, %s, %d\n", "ab", "aa", isIsomorphic("ab", "aa"));
    printf("%s, %s, %d\n", "a", "a", isIsomorphic("a", "a"));

    return 0;
}

int check(char* s, char* t)
{
    char map[256];

    int i;
    for (i = 0; i < 256; i++)
        map[i] = 0;

    for (; *s != '\0'; s++, t++) {
        if (map[*s] == 0) {
            map[*s] = *t;
        } else {
            if (map[*s] != *t)
                return 0;
        }
    }

    return 1;
}

bool isIsomorphic(char* s, char* t)
{
    return (check(s, t) && check(t, s));
}