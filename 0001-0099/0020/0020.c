#include <stdio.h>
#include <stdlib.h>

int isValid(char* s);

int main()
{
    printf("%s:%d\n", "{[()]}", isValid("{[()]}"));
    printf("%s:%d\n", "{[()]", isValid("{[()]"));
    printf("%s:%d\n", "[[[[[[{]]]]]]", isValid("[[[[[[{]]]]]]"));

    return 0;
}

struct stack {
    char str[1000];
    int tail;
};

void stackPush(struct stack* st, char c);
char stackPull(struct stack* st);
int match(char c1, char c2);

int isValid(char* s)
{
    int i;
    struct stack *st = malloc(sizeof(struct stack));

    st->tail = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stackPush(st, s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (!match(stackPull(st), s[i])) {
                return 0;
            }
        }
    }

    return (st->tail == 0);
}

void stackPush(struct stack* st, char c)
{
    st->str[st->tail] = c;
    st->tail += 1;
}

char stackPull(struct stack* st)
{
    st->tail -= 1;
    return st->str[st->tail];
}

int match(char c1, char c2)
{
    return (
        (c1 == '(' && c2 == ')') ||
        (c1 == '[' && c2 == ']') ||
        (c1 == '{' && c2 == '}')
    );
}