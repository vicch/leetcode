// Problem:
// There are a total of n courses to take. Some courses may have prerequisites.
// For example, to take course 0 you have to first take course 1, which is
// expressed as a pair: [0,1]. Given the total number of courses and a list of
// prerequisite pairs, return the ordering of courses to finish all courses.
// If it is impossible to finish all courses, return an empty array. If there
// are multiple correct orders, return one of them.
// 
// Example:
// Input:  4, [[3,1],[1,0],[3,2],[2,0]]
// Output: [0,1,2,3] or [0,2,1,3]
// 
// Solution:
// Use a n*n matrix to store all pairs, row index means "to learn course x",
// column index means "need to learn course y first". Keep track of all many
// columns are marked for each row. Start with course(s) whose row is empty
// (it has no prerequisites), and remove marks in their corresponding columns.
// Repeat until all courses are taken. If no empty row is found before all
// courses are taken, return empty array.
// 
// Example:
// Input: 5, [[1,4],[2,0],[2,1],[3,1],[4,0]]
// Matrix:
//   0 1 2 3 4        0 1 2 3 4        0 1 2 3 4        0 1 2 3 4
// 0                0 +--------      0 +-------+      0 +-+-----+
// 1         X      1 |       X      1 |       |      1 +-+-----+
// 2 X X        =>  2 | X        =>  2 | X     |  =>  2 | |     |
// 3   X            3 | X            3 | X     |      3 | |     |
// 4 X              4 |              4 +-------+      4 +-+-----+
// row 0 cleared    row 4 cleared    row 1 cleared    row 2 and 3 cleared

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* seq, int count);

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize);

int main()
{
    int c1[5][2] = {
        {1, 4},
        {2, 0},
        {2, 1},
        {3, 1},
        {4, 0}
    };
    int rs1;
    printArray(findOrder(5, (int**)c1, 5, 2, &rs1), rs1);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize)
{
    // Prerequisites
    char matrix[numCourses][numCourses];
    // Numbers of each course's untaken prerequisites
    int prereq[numCourses];
    // Each course's state: 0=untaken, 1=taken
    char courses[numCourses];
    
    int i, j, x, y, left, clear;

    *returnSize = 0;
    int* result = malloc(sizeof(int) * numCourses);

    // Init all prerequisites as 0
    memset(matrix, 0, sizeof(matrix));
    memset(prereq, 0, sizeof(prereq));

    // Init all courses as untaken
    memset(courses, 0, sizeof(courses));
    left = numCourses;

    // Mark prerequisites
    for (i = 0; i < prerequisitesRowSize; i++) {
        x = prerequisites[i][0];
        y = prerequisites[i][1];
        matrix[x][y] = 1;
        prereq[x] += 1;
    }

    // While there is course not taken yet
    while (left) {

        // Iterate all courses not taken yet
        for (clear = i = 0; i < numCourses; i++) {

            // Course not taken and can be taken
            if (!courses[i] && !prereq[i]) {
                clear = 1;

                // Take course
                result[(*returnSize)++] = i;
                courses[i] = 1;
                left -= 1;

                // Clear other courses's prerequisites
                for (j = 0; j < numCourses; j++) {
                    if (!courses[j] && matrix[j][i]) {
                        // matrix[j][i] = 0;
                        prereq[j] -= 1;
                    }
                }
            }
        }

        // No course can be taken
        if (!clear) {
            *returnSize = 0;
            free(result);
            return NULL;
        }
    }

    return result;
}