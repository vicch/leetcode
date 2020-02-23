#include <vector>

using namespace std;

class Solution {
private:
	// Memo data, mem[i][j] contains the number of paths from cell (i,j) to the end cell
	vector<vector<int>> mem;
	
	// Returns the number of paths from cell (i,j) to cell (m-1,n-1)
	int backtrack(int i, int j, int m, int n) {

		// If this is the bottom row or right-most column, there is only 1 path
		if (i == m - 1 || j == n - 1)
			return 1;
		
		// If out of bound
		if (i >= m || j >= n)
			return 0;
		
		// Check memo data, calculate and store it if not calculated yet
		if (mem[i+1][j] == -1)
			mem[i+1][j] = backtrack(i+1, j, m, n);
		if (mem[i][j+1] == -1)
			mem[i][j+1] = backtrack(i, j+1, m, n);
		
		// Number of paths from this cell equals to the sum of paths from the cell below and on
		// its right side
		return mem[i+1][j] + mem[i][j+1];
	}

public:
	int uniquePaths(int m, int n) {
		// Init memo data with impossible value -1
		mem = vector<vector<int>> (m, vector<int> (n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mem[i][j] = -1;
			}
		}
		
		return backtrack(0, 0, m, n);
	}
};
