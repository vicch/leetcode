#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    int size;
    int head;
    int tail;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
int myCircularQueueNextTail(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

int main()
{
    MyCircularQueue* queue = myCircularQueueCreate(6);

    printf("enQueue(6) = %d\n", myCircularQueueEnQueue(queue, 6));
    printf("rear()     = %d\n", myCircularQueueRear(queue));
    printf("rear()     = %d\n", myCircularQueueRear(queue));
    printf("deQueue()  = %d\n", myCircularQueueDeQueue(queue));
    printf("enQueue(5) = %d\n", myCircularQueueEnQueue(queue, 5));
    printf("rear()     = %d\n", myCircularQueueRear(queue));
    printf("deQueue()  = %d\n", myCircularQueueDeQueue(queue));
    printf("rear()     = %d\n", myCircularQueueFront(queue));
    printf("deQueue()  = %d\n", myCircularQueueDeQueue(queue));
    printf("deQueue()  = %d\n", myCircularQueueDeQueue(queue));
    printf("deQueue()  = %d\n", myCircularQueueDeQueue(queue));

    myCircularQueueFree(queue);

    return 0;
}

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue->array = malloc(sizeof(int) * k);
    queue->size = k;
    // Off-limit values indicate the queue is empty
    queue->head = -1;
    queue->tail = -1;
    return queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj))
        return false;

    // If currently empty, init head as 0
    if (myCircularQueueIsEmpty(obj))
        obj->head = 0;

    obj->tail = myCircularQueueNextTail(obj);
    obj->array[obj->tail] = value;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return false;
    
    // Reset both pointers to -1 if queue is empty after dequeue
    if (obj->head == obj->tail)
        obj->head = obj->tail = -1;
    // Move head pointer towards the end, circling back to start if past the end
    else
        obj->head = (obj->head + 1) % obj->size;
    
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj)
{
    return myCircularQueueIsEmpty(obj) ? -1 : obj->array[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj)
{
    return myCircularQueueIsEmpty(obj) ? -1 : obj->array[obj->tail];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return (obj->head == -1);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    // If queue is empty, it's not full, no need to check pointers in that case
    return !myCircularQueueIsEmpty(obj) && (myCircularQueueNextTail(obj) == obj->head);
}

/** Get tail index of next avail cell, circling back to start if past the end. **/
int myCircularQueueNextTail(MyCircularQueue* obj)
{
    return (obj->tail + 1) % obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->array);
    free(obj);
}