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
// 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int h, w;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        h = matrix.size();
        w = matrix[0].size();

        vector<vector<int>> answer (h, vector<int> (w, -1));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == 0)
                    answer[i][j] = 0;
                else
                    visitCell(matrix, answer, i, j);
            }
        }

        return answer;
    }

    int visitCell(vector<vector<int>>& matrix, vector<vector<int>>& answer, int x, int y) {
        // Already visited or being visited
        if (answer[x][y] != -1) {
            // Do nothing

        // Cell is 0
        } else if (matrix[x][y] == 0) {
            answer[x][y] = 0;

        // Calculate cell distance
        } else {
            answer[x][y] = -2;

            int dist;
            int distmin = 10000;
            bool revisit = false;

            for (int i = 0; i < 4; i++) {
                dist = getAdjacent(matrix, answer, x, y, i);

                // Shortest distance found
                if (dist == 0) {
                    distmin = 0;
                    break;

                // Coming from this direction, need to revisit,
                // distance on this direction is ignored
                } else if (dist == -2) {
                    revisit = true;

                } else {
                    distmin = min(distmin, dist);
                }
            }

            // Mark as unvisited, return a uncertain distance
            if (revisit) {
                answer[x][y] = -1;
                return distmin + 1;
            }

            answer[x][y] = distmin + 1;
        }

        return answer[x][y];
    }

    int getAdjacent(vector<vector<int>>& matrix, vector<vector<int>>& answer, int x, int y, int d) {
        switch (d) {
            case 0:
                return (y == 0) ? 10000 : visitCell(matrix, answer, x, y - 1);
            case 1:
                return (x == 0) ? 10000 : visitCell(matrix, answer, x - 1, y);
            case 2:
                return (y == w - 1) ? 10000 : visitCell(matrix, answer, x, y + 1);
            case 3:
                return (x == h - 1) ? 10000 : visitCell(matrix, answer, x + 1, y);
        }
    }
};