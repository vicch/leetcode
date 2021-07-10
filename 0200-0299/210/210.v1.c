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

struct course {
    int value;
    struct course* next;
    struct course* prev;
};

void printArray(int* seq, int count);

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize);
struct course* initCourses(int size);

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
    char matrix[numCourses][numCourses];
    // Numbers of each course's prerequisites that are not taken yet
    int prereq[numCourses];
    // Use linked list to keep track of courses not take yet
    struct course *courses, *course1, *course2;
    int i, x, y, clear;

    *returnSize = 0;
    int* result = malloc(sizeof(int) * numCourses);

    // Init all prerequisites as 0
    memset(matrix, 0, sizeof(matrix));
    memset(prereq, 0, sizeof(prereq));

    // Init all courses to take
    courses = initCourses(numCourses);

    // Mark prerequisites
    for (i = 0; i < prerequisitesRowSize; i++) {
        x = prerequisites[i][0];
        y = prerequisites[i][1];
        matrix[x][y] = 1;
        prereq[x] += 1;
    }

    // While there is course not taken yet
    while (courses) {
        // Iterate all courses not taken yet
        for (clear = 0, course1 = courses; course1 != NULL;) {
            // printf("course1=%d\n", course1->value);
            // Can take this course
            if (prereq[course1->value] == 0) {
                // printf("course %d clear\n", course1->value);
                clear = 1;
                // Take course
                result[(*returnSize)++] = course1->value;
                // Clear other courses
                for (course2 = courses; course2 != NULL; course2 = course2->next) {
                    // printf("course2=%d\n", course2->value);
                    if (matrix[course2->value][course1->value] == 1) {
                        matrix[course2->value][course1->value] = 0;
                        prereq[course2->value] -= 1;
                    }
                }
                // Remove course from linked list
                if (!course1->prev && !course1->next) {
                    courses = NULL;
                } else if (!course1->prev) {
                    courses = course1->next;
                    course1->next->prev = NULL;
                } else if (!course1->next) {
                    course1->prev->next = NULL;
                } else {
                    course1->prev->next = course1->next;
                    course1->next->prev = course1->prev;
                }
            }
            course1 = course1->next;
        }

        // No course can be taken
        if (!clear) {
            *returnSize = 0;
            free(result);
            return NULL;
        }
    }
    
    if (courses)
        free(courses);

    return result;
}

struct course* initCourses(int size)
{
    struct course* head = malloc(sizeof(struct course) * size);
    struct course* curr = head;
    int i;

    for (i = 0; i < size; i++, curr++) {
        curr->value = i;
        curr->next  = (i < size - 1) ? curr + 1 : NULL;
        curr->prev  = (i > 0) ? curr - 1 : NULL;
    }

    return head;
}