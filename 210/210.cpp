#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> adj[numCourses];
		vector<int> degrees(numCourses, 0);
        vector<int> order;
        int i, j;
        
        for (auto it : prerequisites) {
			// Transform to adjacency list, each edge is from it[1] to it[0]
			adj[it[1]].push_back(it[0]);

			// Calculate indegrees
			degrees[it[0]] += 1;
		}
        
        // Loop through all nodes
		for (i = 0; i < numCourses; i++) {
            
			// Look for the first node that has 0 indegree
			for (j = 0; j < numCourses; j++) {
				if (degrees[j] == 0) {
					break;
				}
			}

			// If it passes the end, there is no node with 0 degree
			if (j == numCourses) {
				break;
			}
            
            order.push_back(j);

			// Set the indegree of this node to non-zero value so it's skipped in next loop
			degrees[j]--;

			// Decrement the indegrees of this node's adjacent nodes
			for (auto k : adj[j]) {
				degrees[k]--;
			}
		}
        
        if (order.size() != numCourses) {
            order.clear();
        }
        
        return order;
    }
};