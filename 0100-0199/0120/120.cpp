#include <vector>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		// Init a vector with the size of the last row, this will be enough to
		// fit all temp results, because each row needs one less slot than the
		// row below it.
		vector<int> layer = triangle[triangle.size() - 1];

		// Start from the second bottom row
		for (int i = triangle.size() - 2; i >= 0; i--) {
			// Iterate from left to right
			for (int j = 0; j <= i; j++) {
				// Calculate the minimum sum for each number, and overwrite it
				// in the temp result array. This is ok because layer[j] is the
				// left adjacent number of the upper row, it won't be used again
				// in the remaining iterations.
				layer[j] += triangle[i][j] + min(layer[j], layer[j+1]);
			}
		}

		// First slot stores the minimum sum of the top row
		return layer[0];
	}
};
