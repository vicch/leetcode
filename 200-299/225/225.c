#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* head; // Pointer to bottom element
    int* top;  // Pointer to top element
    int size;  // Max size
} Stack;

typedef int bool;

void stackCreate(Stack *stack, int maxSize);
void stackPush(Stack *stack, int element);
void stackPop(Stack *stack);
int stackTop(Stack *stack);
bool stackEmpty(Stack *stack);
void stackDestroy(Stack *stack);

int main()
{
    Stack* s = malloc(sizeof(Stack));
    stackCreate(s, 10);

    printf("%d\n", s->size);
    printf("%d\n", stackEmpty(s));

    stackPush(s, 1);
    stackPush(s, 2);
    stackPush(s, 3);
    printf("%d\n", stackEmpty(s));

    printf("%d\n", stackTop(s));
    stackPop(s);
    printf("%d\n", stackTop(s));
    stackPop(s);
    printf("%d\n", stackTop(s));
    stackPop(s);

    printf("%d\n", stackEmpty(s));

    stackDestroy(s);

    return 0;
}

/* Create a stack */
void stackCreate(Stack *stack, int maxSize)
{
    stack->head = malloc(sizeof(int) * maxSize);
    stack->top  = stack->head - 1;
    stack->size = maxSize;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element)
{
    // Full
    if (stack->top - stack->head >= stack->size - 1)
        return;

    stack->top++;
    *(stack->top) = element;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack)
{
    if (stack->top < stack->head)
        return;

    stack->top--;
}

/* Get the top element */
int stackTop(Stack *stack)
{
    if (stack->top < stack->head)
        return 0;

    return *(stack->top);
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack)
{
    return (stack->top < stack->head);
}

/* Destroy the stack */
void stackDestroy(Stack *stack)
{
    free(stack->head);
}