#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// Get dimensions of the input
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		
		// Init the cell values to 0, add an extra row and column (the actual bottom row and
		// right-most column's values will be based on the extra row and column) to simplify the
		// calculations below.
		long mem[m + 1][n + 1] = {};
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= n; j++)
				mem[i][j] = 0;
		
		// Init base value in the extra row (or column, which is mem[m][n-1])
		mem[m - 1][n] = 1;
		
		for (int i = m - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--)
				// Check if cell is obstacle, mark as 0 if it is
				mem[i][j] = (obstacleGrid[i][j]) ? 0 : (mem[i + 1][j] + mem[i][j + 1]);
		
		return mem[0][0];
	}
};