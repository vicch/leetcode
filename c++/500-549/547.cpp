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
// Iterate the students and BFS visit each student and his friends. Friend
// circle increments by 1 for each unvisited student.

#include <queue>

class Solution {
    public:
        int findCircleNum(vector<vector<int>>& M) {
            if (!M.size())
                return 0;

            int i, j, count, visit;
            queue<int> tovisit;

            int size = M.size();
            int visited[size] = {0};

            for (count = i = 0; i < size; i++) {
                if (visited[i])
                    continue;

                count++;

                tovisit.push(i);
                while (!tovisit.empty()) {
                    visit = tovisit.front();
                    tovisit.pop();
                    for (j = 0; j < size; j++)
                        if (j != visit && visited[j] == 0 && M[visit][j] == 1)
                            tovisit.push(j);
                    visited[visit] = 1;
                }
            }

            return count;
        }
};