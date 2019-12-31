#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> ret;
		
		// Deal with edge cases
		if (n < 3) {
			for (int i = 0; i < n; i++) {
				ret.push_back(i);
			}
			return ret;
		}

		vector<vector<int>> adj(n);    // Adjacency lists
		vector<int> leaves;            // Current leaf nodes
		int edgeCounts[n] = {0};       // Count of remaining edges of each node
		int edgeRemain = edges.size(); // Count of total remaining edges
		
		for (auto e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
			edgeCounts[e[0]] += 1;
			edgeCounts[e[1]] += 1;
		}
		
		while (edgeRemain > 1) {

			// Look for leaf nodes
			for (int i = 0; i < n; i++) {
				if (edgeCounts[i] == 1) {
					leaves.push_back(i);
				}
			}
			
			// Remove each leaf node from the graph
			for (int i : leaves) {
				edgeCounts[i] = 0;

				// Remove the leaf node from adjacency list of its adjacent nodes
				for (int j : adj[i]) {
					if (edgeCounts[j] > 1) {
						edgeCounts[j] -= 1;
						edgeRemain -= 1;
					// If the adjacent node has only 1 edge left, it means we have reached the
					// end
					} else if (edgeCounts[j] == 1) {
						break;
					}
				}
			}
			
			// Reset the leaf nodes
			leaves.clear();
		}
		
		// Look for the remaining nodes in the graph
		for (int i = 0; i < n; i++) {
			if (edgeCounts[i] == 1) {
				ret.push_back(i);
			}
		}
		
		return ret;
	}
};