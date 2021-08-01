class Solution {
public:
	int uniquePaths(int m, int n) {
		// Init the cells as 0s
		int mem[m][n] = {0};
		
		// Init the bottom row and right-most column as 1s
		for (int i = 0; i < m; i++)
			mem[i][n - 1] = 1;
		for (int j = 0; j < n; j++)
			mem[m - 1][j] = 1;
		
		// Caculater the remaining cells, from bottom right to top left
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				mem[i][j] = mem[i + 1][j] + mem[i][j + 1];
			}
		}
		
		return mem[0][0];
	}
};
