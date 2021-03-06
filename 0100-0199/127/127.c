// Problem:
// Given two words, and a dictionary's word list, find the length of shortest
// transformation sequence from beginWord to endWord, such that:
// - Only one letter can be changed at a time.
// - Each transformed word (not the begin word) must exist in the word list.
// 
// Note:
// - Return 0 if there is no such transformation sequence.
// - All words have the same length.
// - All words contain only lowercase alphabetic characters.
// - Assume no duplicates in the word list.
// - Assume beginWord and endWord are non-empty and are not the same.
// 
// Example:
// Input: beginWord = "hit"
//        endWord = "cog"
//        wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5 ("hit" -> "hot" -> "dot" -> "dog" -> "cog")
// 
// Solution:
// Consider each word as a node. If one word can be transformed to another,
// their nodes are connected by an edge. The problem becomes finding the
// shortest path from one node to another in an undirected graph. Start from
// the ending node, BFS mark each node's distance to it. Then find the nodes
// that can be transformed from the beginning word and get the their shortest
// distance.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize);

int main()
{
    char* wl1[6];
    wl1[0] = "hot";
    wl1[1] = "dot";
    wl1[2] = "dog";
    wl1[3] = "lot";
    wl1[4] = "log";
    wl1[5] = "cog";
    printf("%d\n", ladderLength("hit", "cog", wl1, 6));

    return 0;
}

/********** Solution **********/

struct Queue {
    int* nums;
    int size;
    int head;
    int tail;
};

struct Queue* create(int size);
void push(struct Queue* queue, int num);
int pop(struct Queue* queue);
int empty(struct Queue* queue);
void destroy(struct Queue* queue);

int isConnected(char* a, char* b);
int markConnection(int** map, char** words, int size, char* end);
void markLength(int** map, int* len, int size, int endIndex);

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize)
{
    if (wordListSize == 0)
        return 0;

    int endIndex, shortest, i, j;

    // Word connections
    int* map[wordListSize];
    for (i = 0; i < wordListSize; i++) {
        map[i] = malloc(sizeof(int) * wordListSize);
        memset(map[i], 0, sizeof(int) * wordListSize);
    }

    // Each word's shortest length to end word
    int len[wordListSize];
    memset(len, 0, sizeof(len));

    // Mark word connections
    endIndex = markConnection(map, wordList, wordListSize, endWord);

    // If end word doesn't exist in word list
    if (endIndex == -1)
        return 0;

    // Mark shortest length (BFS using queue)
    markLength(map, len, wordListSize, endIndex);

    // Find shortest length
    for (shortest = -1, i = 0; i < wordListSize; i++)
        if (isConnected(beginWord, wordList[i]) && len[i] != 0 && (shortest == -1 || len[i] < shortest))
            shortest = len[i];

    for (i = 0; i < wordListSize; i++)
        free(map[i]);

    // Plus 1 for the begin word
    return shortest + 1;
}

int isConnected(char* a, char* b)
{
    int diff;

    for (diff = 0; *a != '\0' && *b != '\0'; a++, b++)
        if (*a != *b)
            diff++;

    return (*a == *b) ? (diff == 1) : 0;
}

int markConnection(int** map, char** words, int size, char* end)
{
    int index, i, j;

    for (i = 0, index = -1; i < size; i++) {
        // Look for end word
        if (index == -1 && strcmp(end, words[i]) == 0)
            index = i;
        for (j = i + 1; j < size; j++)
            if (isConnected(words[i], words[j]))
                map[i][j] = map[j][i] = 1;
    }

    return index;
}

void markLength(int** map, int* len, int size, int endIndex)
{
    int i, j;
    struct Queue* queue = create(size);

    // Init with end word
    len[endIndex] = 1;
    push(queue, endIndex);

    while (!empty(queue)) {
        i = pop(queue);
        for (j = 0; j < size; j++)
            if (map[i][j] == 1 && (len[j] == 0 || len[j] > len[i] + 1)) {
                len[j] = len[i] + 1;
                push(queue, j);
            }
    }

    destroy(queue);

    return;
}

struct Queue* create(int size)
{
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->nums = malloc(sizeof(int) * size);
    queue->size = size;
    queue->head = queue->tail = 0;
    return queue;
}

void push(struct Queue* queue, int num)
{
    queue->nums[(queue->tail)++] = num;
    if (queue->tail == queue->size)
        queue->tail = 0;
    return;
}

int pop(struct Queue* queue)
{
    int num = queue->nums[(queue->head)++];
    if (queue->head == queue->size)
        queue->head = 0;
    return num;
}

int empty(struct Queue* queue)
{
    return queue->head == queue->tail;
}

void destroy(struct Queue* queue)
{
    free(queue->nums);
    free(queue);
    return;
}