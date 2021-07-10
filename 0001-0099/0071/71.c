#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path);
char* getNextLevel(char** level, char* path);
char* goLower(char* tail, char* level);
char* goUpper(char* head, char* tail);

int main()
{
    printf("%s\n", simplifyPath("/"));
    printf("%s\n", simplifyPath("/home/"));
    printf("%s\n", simplifyPath("/a/./b/../../c/"));
    printf("%s\n", simplifyPath("/../"));
    printf("%s\n", simplifyPath("/home//foo/"));

    return 0;
}

char* simplifyPath(char* path)
{
    char* head = malloc(sizeof(char) * strlen(path));
    char* tail = head;
    char* level;

    *tail++ = '/';

    while (*path != '\0') {
        path = getNextLevel(&level, path);
        if (strcmp(level, "/.") == 0 || strcmp(level, "/") == 0)
            continue;
        else if (strcmp(level, "/..") == 0)
            tail = goUpper(head, tail);
        else
            tail = goLower(tail, level);
        free(level);
    }

    // Ignore leading multiple "/"
    while (*(head+1) == '/') head++;

    return head;
}

char* getNextLevel(char** level, char* path)
{
    *level = malloc(sizeof(char) * 200);
    int l = 0;

    // Always get first character
    (*level)[l++] = *path++;

    // Ignore multiple "/"
    for (; *path == '/'; path++);

    for (; *path != '/' && *path != '\0'; path++)
        (*level)[l++] = *path;

    (*level)[l] = '\0';

    return path;
}

char* goLower(char* tail, char* level)
{
    while ((*tail++ = *level++) != '\0');
    return tail - 1;
}

char* goUpper(char* head, char* tail)
{
    for (; *tail != '/' && tail != head; tail--);

    // Do not go upper at root
    if (tail == head) {
        *head = '/';
        tail++;
    }

    *tail = '\0';
    return tail;
}