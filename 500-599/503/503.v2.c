// Problem:
// Given a circular array, print the Next Greater Number for every element. The
// Next Greater Number of a number is the first greater number to its
// traversing-order next in the array. If it doesn't exist, output -1.
//
// Example:
// Input: [4, 1, 2, 5]
// Output: [5, 2, 5, -1]
//
// Solution:
// Using stack to stores indices of the appropriate elements from nums array.
// The top index refers to the Next Greater Element found so far. Traversing
// the nums array from right to left. For each number, pop the stack until an
// index is found that nums[stack[top]] > nums[i], then push i to stack.

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int* nums;
    int top;
};

void printArray(int* seq, int count);
void printStack(struct stack* s);

int* nextGreaterElements(int* nums, int numsSize, int* returnSize);

struct stack* create(int depth);
void destroy(struct stack* s);
void push(struct stack* s, int v);
int pop(struct stack* s);
int empty(struct stack* s);

int main()
{
    int s1[] = {4, 1, 2, 5};
    int rs1;
    printArray(nextGreaterElements(s1, 4, &rs1), 4);

    int s2[] = {5, 4, 3, 2, 1};
    int rs2;
    printArray(nextGreaterElements(s2, 5, &rs2), 5);

    int s3[] = {1, 3, 2};
    int rs3;
    printArray(nextGreaterElements(s3, 3, &rs3), 3);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

void printStack(struct stack* s)
{
    int i;
    for (i = s->top; i >= 0; i--)
        printf(i == 0 ? "%d\n" : "%d,", s->nums[i]);
    return;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    int i, j;

    *returnSize = numsSize;
    int* res = malloc(sizeof(int) * numsSize);

    // Stack may contain twice all indices
    struct stack* s = create(numsSize * 2);

    // Init stack by pushing all indexes in reverse order
    for (i = numsSize - 1; i >= 0; i--)
        push(s, i);

    // Iterate array in reverse order
    for (i = numsSize - 1; i >= 0; i--) {
        
        // Pop index until greater number is found, or stack is empty
        for (j = pop(s); !empty(s) && nums[j] <= nums[i]; j = pop(s));

        if (nums[j] <= nums[i])
            res[i] = -1;
        else {
            res[i] = nums[j];
            push(s, j);
        }

        // Push current index as new greater number
        push(s, i);
    }

    destroy(s);

    return res;
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

int empty(struct stack* s)
{
    return s->top == -1;
}