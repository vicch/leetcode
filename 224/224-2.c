// Problem:
// Implement a basic calculator to evaluate a simple expression string. The
// expression string may contain open ( and closing parentheses ), the plus +
// or minus sign -, non-negative integers and empty spaces. Assume that the
// given expression is always valid.
// 
// Example:
// "(1+(4+5+2)-3)+(6+8)" = 23
// 
// Solution:
// Keep a global total and a stack of signs, one for each open scope. The
// outmost sign is +1:
// - Each number consumes a sign
// - Each + or - inserts a sign
// - Each ( duplicates the sign on top (to be consumed by first number in scope)
// - Each ) pops a sign

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int* nums;
    int top;
};

int calculate(char* s);

struct stack* create(int depth);
void destroy(struct stack* s);
void push(struct stack* s, int v);
int pop(struct stack* s);
int top(struct stack* s);
int empty(struct stack* s);

int main()
{
    printf("%d\n", calculate(" 2-1 + 2 "));
    printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)"));
    printf("%d\n", calculate("10"));
    printf("%d\n", calculate("11 + (12 - 13) + 14"));
    printf("%d\n", calculate("1-(5)"));
    printf("%d\n", calculate("3-(5+1)"));
    printf("%d\n", calculate("2-(5-6)"));
    printf("%d\n", calculate("1 - (2 - (3 - 4)) - (5 - 6)"));
    printf("%d\n", calculate("1 + (3 - (4 + 10 - (2 + 0) - (3 + 4) - (4 - 5))) - (2 - 3)"));

    return 0;
}

int calculate(char* s)
{
    int num, total = 0;
    struct stack* signs = create(100000);

    // Init by inserting 2 positive signs
    push(signs, 1);
    push(signs, 1);

    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') {
            num = 0;
            while (*s >= '0' && *s <= '9')
                num = num * 10 + (*s++ - '0');
            total += num * pop(signs);
            s--; // To cancel out the s++ at the end of while body
        } else if (*s == ')')
            pop(signs);
        else if (*s != ' ') // +, -, (
            push(signs, top(signs) * (*s == '-' ? -1 : 1));
        s++;
    }

    destroy(signs);

    return total;
}

struct stack* create(int depth)
{
    struct stack* s = malloc(sizeof(struct stack));
    s->nums = malloc(sizeof(int) * depth);
    s->top = -1;
    return s;
}

void destroy(struct stack* s)
{
    free(s->nums);
    free(s);
    return;
}

void push(struct stack* s, int v)
{
    s->nums[++(s->top)] = v;
}

int pop(struct stack* s)
{
    return s->nums[s->top--];
}

int top(struct stack* s)
{
    return s->nums[s->top];
}

int empty(struct stack* s)
{
    return s->top == -1;
}