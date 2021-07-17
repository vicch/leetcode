// Problem:
// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.
// - push(x):  Push element x onto stack.
// - pop():    Removes the element on top of the stack.
// - top():    Get the top element.
// - getMin(): Retrieve the minimum element in the stack.
// 
// Solution:
// - Use an array and index to implement the main stack.
// - Use another array and index to implement another stack containing the
//   indices to minimum values.

typedef struct {
    int* nums;
    int ntop;
    int* mins;
    int mtop;
} MinStack;

MinStack* minStackCreate(int maxSize) {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->nums = malloc(sizeof(int) * maxSize);
    obj->ntop = -1;
    obj->mins = malloc(sizeof(int) * maxSize);
    obj->mtop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    obj->nums[++(obj->ntop)] = x;
    if (obj->mtop == -1 || x < obj->nums[obj->mins[obj->mtop]])
        obj->mins[++(obj->mtop)] = obj->ntop;
}

void minStackPop(MinStack* obj) {
    if (obj->mins[obj->mtop] == obj->ntop)
        obj->mtop--;
    obj->ntop--;
}

int minStackTop(MinStack* obj) {
    return obj->nums[obj->ntop];
}

int minStackGetMin(MinStack* obj) {
    return obj->nums[obj->mins[obj->mtop]];
}

void minStackFree(MinStack* obj) {
    free(obj->nums);
    free(obj->mins);
    free(obj);
}