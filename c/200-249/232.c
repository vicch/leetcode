#include <stdio.h>
#include <stdlib.h>

typedef int bool;

typedef struct {
    int* head;
    int  size;
    int* push; // Pointer to push element
    int* pop;  // Pointer to pop element
} Queue;

void queueCreate(Queue *queue, int maxSize);
void queuePush(Queue *queue, int element);
void queuePop(Queue *queue);
int queuePeek(Queue *queue);
bool queueEmpty(Queue *queue);
void queueDestroy(Queue *queue);

int main()
{
    Queue* q = malloc(sizeof(Queue));

    queueCreate(q, 5);

    // printf("%d\n", queueEmpty(q));

    queuePush(q, 1);
    // queuePush(q, 2);
    // queuePush(q, 3);
    // printf("%d\n", queueEmpty(q));

    printf("%d\n", queuePeek(q));
    queuePop(q);
    // printf("%d\n", queuePeek(q));
    // queuePop(q);
    // printf("%d\n", queuePeek(q));
    // queuePop(q);
    printf("%d\n", queueEmpty(q));

    queueDestroy(q);

    return 0;
}

/* Create a queue */
void queueCreate(Queue *queue, int maxSize)
{
    queue->head = malloc(sizeof(int) * maxSize);
    queue->size = maxSize;
    queue->push = queue->head;
    queue->pop  = NULL;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element)
{
    // Full
    if (queue->push == queue->pop)
        return;

    *(queue->push) = element;

    if (queue->pop == NULL)
        queue->pop = queue->push;

    queue->push++;
    if (queue->push > queue->head + queue->size - 1)
        queue->push = queue->head;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue)
{
    // Empty
    if (queue->pop == NULL)
        return;

    queue->pop++;
    if (queue->pop > queue->head + queue->size - 1)
        queue->pop = queue->head;
    
    // Empty
    if (queue->pop == queue->push)
        queue->pop = NULL;
}

/* Get the front element */
int queuePeek(Queue *queue)
{
    if (queue->pop == NULL)
        return 0;
    else
        return *(queue->pop);
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue)
{
    return (queue->pop == NULL);
}

/* Destroy the queue */
void queueDestroy(Queue *queue)
{
    free(queue->head);
}