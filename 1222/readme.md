# Problem

On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates `queens` that represents the positions of the Black Queens, and a pair of coordinates `king` that represent the position of the White King, return the coordinates of all the queens (in any order) that can attack the King.

## Constraints

- `1 <= queens.length <= 63`
- `queens[0].length == 2`
- `0 <= queens[i][j] < 8`
- `king.length == 2`
- `0 <= king[0], king[1] < 8`
- At most one piece is allowed in a cell.

## Example 1

```
+---+---+---+---+---+---+---+---+
| K | Q |   |   | q |   |   |   |
+---+---+---+---+---+---+---+---+
| Q |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   | q |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | Q |   |   |   |   |
+---+---+---+---+---+---+---+---+
| q |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+

Queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]
King   = [0,0]
Return = [[0,1],[1,0],[3,3]]
```

## Example 2

```
+---+---+---+---+---+---+---+---+
| q |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   | q |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   | Q |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | K | Q | q |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   | Q | q |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+

Queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]]
King   = [3,3]
Return = [[2,2],[3,4],[4,4]]
```

## Example 3

```
+---+---+---+---+---+---+---+---+
| q | q |   | q | q | q | q | q |
+---+---+---+---+---+---+---+---+
| q | q | q |   | Q |   | Q | q |
+---+---+---+---+---+---+---+---+
|   | q | q | Q |   |   | q | q |
+---+---+---+---+---+---+---+---+
|   |   |   |   | K |   |   | Q |
+---+---+---+---+---+---+---+---+
| q |   | q | Q |   | Q | q |   |
+---+---+---+---+---+---+---+---+
| q | q | q |   | Q |   | q |   |
+---+---+---+---+---+---+---+---+
|   | q |   | q | q |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   | q |   | q |
+---+---+---+---+---+---+---+---+

Queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]]
King   = [3,4]
Return = [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
```

# Solution

## Solution 1

Convert `queens` coords into a matrix, whose values default to `0`, and change to `1` if there is a Queen in a cell.

Then start from the King's coord, follow the 8 directions and iterate the cells till the borders. Record the first Queen met in each direction.

## Solution 2

Iterate `queens` coords, check if the Queen is on 1 of the 8 directions of the King. If it is, check if their distance is by far the shortest on the direction. Maintain the shortest distances of all directions, and return the results in the end.