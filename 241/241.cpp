// Problem:
// Given a string of numbers and operators, return all possible results from
// computing all the different possible ways to group numbers and operators.
// The valid operators are +, - and *.
// 
// Example:
// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
//         (2*(3-(4*5))) = -34
//         ((2*3)-(4*5)) = -14
//         ((2*(3-4))*5) = -10
//         (2*((3-4)*5)) = -10
//         (((2*3)-4)*5) = 10
//         
// Solution:
// No matter how the numbers are grouped, every operation can be represented
// as: (f1,t1)<operator>(f2,t2), where f and t are number indice. For example,
// 2*(3-4) in "2*3-4*5" is (0,0)*(1,2). And each operand can be divided
// recursively until each operand is a single number. Use an array of vectors
// as DP storage, the key of the array is caculated by (f,t) and the vector
// contains all possible results of (f,t). Populate the array first with single
// numbers, and then with adjacent numbers (index diff is 1) and so forth. And
// return dp[(0, s-1)] in the end, where s is the number of integers in the
// string.
// For example, "2-1-1" will be calculated as:
// Step 1: (0,0) = 2, (1,1) = 1, (2,2) = 1
// Step 2: (0,1) = (0,0)-(1,1) = 1, (1,2) = (1,1)-(2,2) = 0
// Step 3: (0,2) = (0,0)-(1,2) = 2, (0,2) = (0,1)-(2,2) = 0
// Result: [2,0]

#include <iostream>
#include <vector>

using namespace std;

// Calculate index in DP array by f and t
#define INDEX(s, f, t) (((s) * 2 - (f) + 1) * (f) / 2 + ((t) - (f)))

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;  // Numbers
        vector<char> oprs; // Operators
        int v, s;

        // Parse numbers and operators
        v = 0;
        for (char c: input) {
            if (c >= '0' && c <= '9') {
                v *= 10;
                v += c - '0';
            } else {
                oprs.push_back(c); // Save operator
                nums.push_back(v); // Save number
                v = 0;
            }
        }

        nums.push_back(v); // Save last number
        s = nums.size();

        // Size of DP array = 1 + 2 + ... + s
        vector<int> dp[(s + 1) * s / 2];

        // Initialize with single numbers
        for (int i = 0; i < s; i++)
            dp[INDEX(s, i, i)].push_back(nums[i]);

        for (int i = 1; i < s; i++) // Index diff
            for (int j = 0; j < s - i; j++) // j = f1
                for (int k = j; k < i + j; k++) // k = t1
                    for (int m: dp[INDEX(s, j, k)])
                        for (int n: dp[INDEX(s, k + 1, i + j)]) // k + 1 = f2, i + j = t2
                            dp[INDEX(s, j, i + j)].push_back(calc(m, n, oprs[k]));

        return dp[INDEX(s, 0, s - 1)];
    }

    int calc(int a, int b, char opr) {
        switch (opr) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default:
                return 0;
        }
    }
};