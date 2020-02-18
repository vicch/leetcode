// Problem:
// There is a list of sorted integers from 1 to n. Starting from left to right,
// remove the first number and every other number afterward until reach the end
// of the list. Repeat the previous step again, but this time from right to
// left, remove the right most number and every other number from the remaining
// numbers. Keep repeating the steps again, alternating left to right and right
// to left, until a single number remains. Find the last number that remains
// starting with a list of length n.
// 
// Example:
// Input: 9
// Output: 6
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6
// 
// Solution:
// The operation is recursive, for example, [1, 2, 3, 4, 5] becomes [2, 4] after
// one run, which can be considered as [1, 2] multiplied by 2, and the next run
// will be backwards. Use two functions recursively calling each other, and
// return when the value becomes 1.

class Solution {
public:
    int lastRemaining(int n) {
        return forward(n);
    }

    int forward(int n) {
        if (n == 1) return 1;
        return 2 * backward(n / 2);
    }

    int backward(int n) {
        if (n == 1) return 1;
        return 2 * forward(n / 2) - (n & 1 ? 0 : 1);
    }
};