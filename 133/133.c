#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEIGHBORS_MAX_SIZE 100

struct UndirectedGraphNode {
    int label;
    struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
    int neighborsCount;
};

struct UndirectedGraphNode* cloneGraph(struct UndirectedGraphNode* graph);
struct UndirectedGraphNode* cloneSub(struct UndirectedGraphNode* graph, struct UndirectedGraphNode** nodes);

int main()
{
    struct UndirectedGraphNode* graph1 = malloc(sizeof(struct UndirectedGraphNode));
    graph1->label = 999;
    graph1->neighborsCount = 0;
    struct UndirectedGraphNode* clone1 = cloneGraph(graph1);

    return 0;
}

/**
 * Need a hashmap to store node label/address pairs
 */
struct UndirectedGraphNode* cloneGraph(struct UndirectedGraphNode* graph)
{
    if (!graph) return NULL;

    // Support node lables from -500 to 999
    struct UndirectedGraphNode** nodes = malloc(sizeof(struct UndirectedGraphNode*) * 1500);
    memset(nodes, 0, sizeof(nodes));
    nodes += 500;

    struct UndirectedGraphNode* clone = cloneSub(graph, nodes);

    nodes -= 500;
    free(nodes);

    return clone;
}

struct UndirectedGraphNode* cloneSub(struct UndirectedGraphNode* graph, struct UndirectedGraphNode** nodes)
{
    // Node already exists
    if (nodes[graph->label]) return nodes[graph->label];

    struct UndirectedGraphNode* node = malloc(sizeof(struct UndirectedGraphNode));
    node->label = graph->label;
    node->neighborsCount = graph->neighborsCount;

    // Add node
    nodes[node->label] = node;

    int i;
    for (i = 0; i < graph->neighborsCount; i++) {
        if (nodes[graph->neighbors[i]->label])
            node->neighbors[i] = nodes[graph->neighbors[i]->label];
        else
            node->neighbors[i] = cloneSub(graph->neighbors[i], nodes);
    }

    return node;
}