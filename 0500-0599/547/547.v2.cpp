// Problem:
// There are N students in a class. Some of them are friends. Their friendship
// is transitive in nature. For example, if A is a direct friend of B, and B is
// a direct friend of C, then A is an indirect friend of C. A friend circle is
// a group of students who are direct or indirect friends. Given a N*N matrix,
// M representing the friend relationship between students in the class. If
// M[i][j] = 1, then the ith and jth students are direct friends with each
// other, otherwise not. Output the total number of friend circles.
// 
// Example:
// Input: [[1,1,0],
//         [1,1,0],
//         [0,0,1]]
// Output: 2
// 
// Solution:
// Iterate the students and DFS visit each student and his friends. Friend
// circle increments by 1 for each unvisited student.

#include <queue>

class Solution {
    public:
        void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
            visited[i] = 1;
            for (int j = 0; j < M.size(); j++)
                if (j != i && !visited[j] && M[i][j])
                    dfs(M, visited, j);
            return;
        }
        int findCircleNum(vector<vector<int>>& M) {
            int i, count;
            vector<bool> visited (M.size(), 0);

            for (count = i = 0; i < M.size(); i++)
                if (!visited[i]) {
                    count++;
                    dfs(M, visited, i);
                }

            return count;
        }
};