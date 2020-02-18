# Problem

Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a value `(int)` and a list `(List[Node])` of its neighbors.

## Example

![Example](example.png)

```
Input = {
	"$id":"1",
	"neighbors":[
		{
			"$id":"2",
			"neighbors":[
				{
					"$ref":"1"
				},
				{
					"$id":"3",
					"neighbors":[
						{
							"$ref":"2"
						},
						{
							"$id":"4",
							"neighbors":[
								{
									"$ref":"3"
								},
								{
									"$ref":"1"
								}
							],
							"val":4
						}
					],
					"val":3
				}
			],
			"val":2
		},
		{
			"$ref":"4"
		}
	],
	"val":1
}
```

## Note

- The number of nodes will be between 1 and 100.
- The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
- Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
- You must return the copy of the given node as a reference to the cloned graph.

# Solution

Maintain a lookup hash map from pointers to original nodes, to pointers to the corresponding cloned nodes. So that we can look up if a node has already been cloned, and can get its pointer.

The cloning is recursive. For each node:

1. Check if the node is already cloned, by look it up in the hash map.
2. If it's already cloned, skip step 3.
3. If it's not cloned, make a new copy of it, add it to the hash map, and iterate the neighbors of the original node, recursively clone each neighbor node and add it as neighbor to the cloned node.
4. Return pointer to the cloned node.