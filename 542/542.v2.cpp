// Problem:
// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
// each cell. The distance between two adjacent cells is 1.
// 
// Example:
// Input: 0 0 0
//        0 1 0
//        1 1 1
// Output: 0 0 0
//         0 1 0
//         1 2 1
// 
// Solution:
// Iterate matrix in 2 passes, look for shortest distance among 4 neighbors.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();

        vector<vector<int>> dp (h, vector<int> (w, INT_MAX));

        // 2 passes: forward and backward
        for (int pass = 0; pass < 2; pass++) {
            for (int i = pass ? h-1 : 0; pass ? i >= 0 : i < h; pass ? i-- : i++) {
                for (int j = pass ? w-1 : 0; pass ? j >= 0 : j < w; pass ? j-- : j++) {

                    if (matrix[i][j] == 0) {
                        dp[i][j] = 0;

                    } else {
                        // Look up
                        if (i && dp[i-1][j] != INT_MAX && dp[i][j] > dp[i-1][j] + 1) {
                            dp[i][j] = dp[i-1][j] + 1;
                            // Shortest found
                            if (dp[i][j] == 1)
                                continue;
                        }
                        
                        // Look left
                        if (j && dp[i][j-1] != INT_MAX && dp[i][j] > dp[i][j-1] + 1) {
                            dp[i][j] = dp[i][j-1] + 1;
                            // Shortest found
                            if (dp[i][j] == 1)
                                continue;
                        }

                        // Look down
                        if (i < h-1 && dp[i+1][j] != INT_MAX && dp[i][j] > dp[i+1][j] + 1) {
                            dp[i][j] = dp[i+1][j] + 1;
                            // Shortest found
                            if (dp[i][j] == 1)
                                continue;
                        }

                        // Look right
                        if (j < w-1 && dp[i][j+1] != INT_MAX && dp[i][j] > dp[i][j+1] + 1) {
                            dp[i][j] = dp[i][j+1] + 1;
                            // Shortest found
                            if (dp[i][j] == 1)
                                continue;
                        }
                    }
                }
            }
        }

        return dp;
    }
};