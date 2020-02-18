// Problem:
// Given a matrix represented by a two-dimensional array, and two positive
// integers r and c representing the row number and column number of a reshaped
// matrix. The reshaped matrix need to be filled with all the elements of the
// original matrix in the same row-traversing order as they were. If the given
// parameters are illegal, output the original matrix.
// 
// Example:
// Input: [[1, 2], [3, 4], [5, 6]], r = 2, c = 3
// Output: [[1, 2, 3], [4, 5, 6]]

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty())
            return nums;

        int m = nums.size();
        int n = nums[0].size();

        if (m * n != r * c)
            return nums;

        int i, j, k;
        vector<vector<int>> res(r, vector<int>(c));

        for (i = k = 0; i < m; i++)
            for (j = 0; j < n; j++, k++)
                res[k / c][k % c] = nums[i][j];

        return res;
    }
};