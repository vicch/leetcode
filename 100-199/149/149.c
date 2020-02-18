#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Line {
    float n;
    float m;
    int points;
};

struct Point* makePoints(int (*coords)[2], int pointsSize);

int maxPoints(struct Point* points, int pointsSize);
struct Line* makeLine(struct Point a, struct Point b);
int isPointOnLine(struct Point point, struct Line* line);

int main()
{
    // int coords1[3][2] = {
    //     {0, 1}, {1, 3}, {0, 2}
    // };
    // struct Point* points1 = makePoints(coords1, 3);
    // int max1 = maxPoints(points1, 3);
    // printf("%d\n", max1);

    // int coords2[5][2] = {
    //     {0, 2}, {0, 2}, {0, 2}, {0, 2}, {0, 2}
    // };
    // struct Point* points2 = makePoints(coords2, 5);
    // int max2 = maxPoints(points2, 5);
    // printf("%d\n", max2);

    // int coords3[4][2] = {
    //     {3, 1}, {12, 3}, {3, 1}, {-6, -1}
    // };
    // struct Point* points3 = makePoints(coords3, 4);
    // int max3 = maxPoints(points3, 4);
    // printf("%d\n", max3);

    // int coords4[50][2] = {
    //     {-54, -297}, {-36, -222}, {3, -2}, {30, 53}, {-5, 1}, {-36, -222}, {0, 2}, {1, 3}, {6, -47}, {0, 4}, {2, 3}, {5, 0}, {48, 128}, {24, 28}, {0, -5}, {48, 128}, {-12, -122}, {-54, -297}, {-42, -247}, {-5, 0}, {2, 4}, {0, 0}, {54, 153}, {-30, -197}, {4, 5}, {4, 3}, {-42, -247}, {6, -47}, {-60, -322}, {-4, -2}, {-18, -147}, {6, -47}, {60, 178}, {30, 53}, {-5, 3}, {-42, -247}, {2, -2}, {12, -22}, {24, 28}, {0, -72}, {3, -4}, {-60, -322}, {48, 128}, {0, -72}, {-5, 3}, {5, 5}, {-24, -172}, {-48, -272}, {36, 78}, {-3, 3}
    // };
    // struct Point* points4 = makePoints(coords4, 50);
    // int max4 = maxPoints(points4, 50);
    // printf("%d\n", max4);
    
    // int coords5[132][2] = {
    //     {40, -23}, {9, 138}, {429, 115}, {50, -17}, {-3, 80}, {-10, 33}, {5, -21}, {-3, 80}, {-6, -65}, {-18, 26}, {-6, -65}, {5, 72}, {0, 77}, {-9, 86}, {10, -2}, {-8, 85}, {21, 130}, {18, -6}, {-18, 26}, {-1, -15}, {10, -2}, {8, 69}, {-4, 63}, {0, 3}, {-4, 40}, {-7, 84}, {-8, 7}, {30, 154}, {16, -5}, {6, 90}, {18, -6}, {5, 77}, {-4, 77}, {7, -13}, {-1, -45}, {16, -5}, {-9, 86}, {-16, 11}, {-7, 84}, {1, 76}, {3, 77}, {10, 67}, {1, -37}, {-10, -81}, {4, -11}, {-20, 13}, {-10, 77}, {6, -17}, {-27, 2}, {-10, -81}, {10, -1}, {-9, 1}, {-8, 43}, {2, 2}, {2, -21}, {3, 82}, {8, -1}, {10, -1}, {-9, 1}, {-12, 42}, {16, -5}, {-5, -61}, {20, -7}, {9, -35}, {10, 6}, {12, 106}, {5, -21}, {-5, 82}, {6, 71}, {-15, 34}, {-10, 87}, {-14, -12}, {12, 106}, {-5, 82}, {-46, -45}, {-4, 63}, {16, -5}, {4, 1}, {-3, -53}, {0, -17}, {9, 98}, {-18, 26}, {-9, 86}, {2, 77}, {-2, -49}, {1, 76}, {-3, -38}, {-8, 7}, {-17, -37}, {5, 72}, {10, -37}, {-4, -57}, {-3, -53}, {3, 74}, {-3, -11}, {-8, 7}, {1, 88}, {-12, 42}, {1, -37}, {2, 77}, {-6, 77}, {5, 72}, {-4, -57}, {-18, -33}, {-12, 42}, {-9, 86}, {2, 77}, {-8, 77}, {-3, 77}, {9, -42}, {16, 41}, {-29, -37}, {0, -41}, {-21, 18}, {-27, -34}, {0, 77}, {3, 74}, {-7, -69}, {-21, 18}, {27, 146}, {-20, 13}, {21, 130}, {-6, -65}, {14, -4}, {0, 3}, {9, -5}, {6, -29}, {-2, 73}, {-1, -15}, {1, 76}, {-4, 77}, {6, -29}
    // };
    // struct Point* points5 = makePoints(coords5, 132);
    // int max5 = maxPoints(points5, 132);
    // printf("%d\n", max5);

    int coords6[3][2] = {
        {8, -15}, {9, -8}, {10, -1},
    };
    struct Point* points6 = makePoints(coords6, 3);
    int max6 = maxPoints(points6, 3);
    printf("%d\n", max6);

    return 0;
}

struct Point* makePoints(int (*coords)[2], int pointsSize)
{
    struct Point* points = malloc(sizeof(struct Point) * pointsSize);

    int i;
    for (i = 0; i < pointsSize; i++) {
        points[i].x = coords[i][0];
        points[i].y = coords[i][1];
    }

    return points;
}

int maxPoints(struct Point* points, int pointsSize)
{
    if (pointsSize < 1) return 0;
    if (pointsSize < 3) return pointsSize;

    int i, j, k;

    // If first 2 points are the same
    if (points[0].x == points[1].x && points[0].y == points[1].y) {
        // Look for a different point starting from the 3rd
        for (i = 2; i < pointsSize; i++) {
            if (points[i].x != points[1].x || points[i].y != points[1].y) {
                // Switch the different point with the 2nd
                int tmp;
                tmp = points[i].x, points[i].x = points[1].x, points[1].x = tmp;
                tmp = points[i].y, points[i].y = points[1].y, points[1].y = tmp;
                break;
            }
        }
        // If all points are the same, return the total number of points
        if (i == pointsSize)
            return pointsSize;
    }

    struct Line** lines = malloc(sizeof(struct Line*) * (pointsSize * (pointsSize - 1) / 2));
    int linesSize = 0;
    int maxPoints = 2;
    int isOnLine;

    for (i = 1; i < pointsSize; i++) {
        isOnLine = 0;

        // Check if point is on existing lines
        for (j = 0; j < linesSize; j++) {
            if (isPointOnLine(points[i], lines[j])) {
                isOnLine = 1;
                // printf(
                //     "point [%d](%d, %d) is on line [%d](%f, %f)\n",
                //     i, points[i].x, points[i].y,
                //     j, lines[j]->n, lines[j]->m
                // );

                lines[j]->points += 1;
                printf(
                    "line [%d](%f, %f) has %d points\n",
                    j, lines[j]->n, lines[j]->m, lines[j]->points
                );

                if (lines[j]->points > maxPoints)
                    maxPoints = lines[j]->points;

            } else {
                // printf(
                //     "point [%d](%d, %d) is not on line [%d](%f, %f)\n",
                //     i, points[i].x, points[i].y,
                //     j, lines[j]->n, lines[j]->m
                // );
            }
        }

        if (isOnLine)
            continue;

        // Add new lines
        if (pointsSize - i + 1 > maxPoints) {
            for (k = 0; k < i; k++) {
                lines[linesSize++] = makeLine(points[k], points[i]);
                // printf(
                //     "add line [%d](%f, %f) with point [%d](%d, %d) and [%d](%d, %d)\n",
                //     linesSize-1, lines[linesSize-1]->n, lines[linesSize-1]->m,
                //     k, points[k].x, points[k].y,
                //     i, points[i].x, points[i].y
                // );
            }
        }
    }

    return maxPoints;
}

struct Line* makeLine(struct Point a, struct Point b)
{
    struct Line* line = malloc(sizeof(struct Line));
    line->points = 2;

    // Vertical line
    if (a.x == b.x) {
        line->n = INFINITY;
        line->m = a.x;

    // Non-vertical line
    } else {
        line->n = (b.y - a.y) * 1.0 / (b.x - a.x);
        line->m = a.y - line->n * a.x;
    }

    return line;
}

int isPointOnLine(struct Point point, struct Line* line)
{
    // Vertical line
    if (line->n == INFINITY)
        return (point.x == line->m);

    // Non-vertical line
    else {
        float tmp = point.x * line->n + line->m;
        // Round up float value
        tmp = (tmp > 0) ? tmp + 0.5 : tmp - 0.5;
        return (int)tmp == point.y;
    }
}