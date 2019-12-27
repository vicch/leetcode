#include <vector>
#include <unordered_map>

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
private:
	// Mapping from pointer of original node, to pointer of corresponding cloned node
	unordered_map<Node*, Node*> cloned;

public:
	Node* cloneGraph(Node* node) {
		// Look up node in hash map, return if already cloned
		if (cloned[node]) {
			return cloned[node];
		}
		
		// Make a new node
		vector<Node*> neighbors;
		Node* clone = new Node(node->val, neighbors);

		// Add node to the hash map
		cloned[node] = clone;
		
		// Recursively clone the original node's neighbors
		for (vector<Node*>::iterator iter = node->neighbors.begin(); iter != node->neighbors.end(); iter++) {
			clone->neighbors.push_back(cloneGraph(*iter));
		}
		
		return clone;
	}
};