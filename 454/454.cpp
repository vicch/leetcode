// Problem:
// Given four lists A, B, C, D of integer values, compute how many tuples
// (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero. All
// lists have same length of N where 0 ≤ N ≤ 500. All integers are in the range
// of -2^28 to 2^28 - 1 and the result is guaranteed to be at most 2^31 - 1.
// 
// Example:
// Input: A = [1, 2], B = [-2, -1], C = [-1, 2], D = [ 0, 2]
// Output: 2 ((0, 0, 0, 1), (1, 1, 0, 0))
// 
// Solution:
// First calculate the sums of any 2 numbers in A and B, use a map to store the
// sum and counts. Then calculate the sums of any 2 numbers in C and D and look
// for the counts of -sum in the map. Add up the counts to get the answer.
// 
// Lesson:
// Use <unordered_map> for better performance.

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d)
    {
        int size, count, i, j;
        unordered_map<int, int> sum;

        size = a.size();
        count = 0;

        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                sum[a[i] + b[j]]++;

        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                count += sum[-(c[i] + d[j])];

        return count;
    }
};