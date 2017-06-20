// Problem:
// Given m arrays, and each array is sorted in ascending order. Pick up two
// integers from two different arrays (each array picks one) and calculate the
// distance. We define the distance between two integers a and b to be their
// absolute difference |a-b|. Find the maximum distance.
// 
// Example:
// Input: [[1,2,3], [4,5], [1,2,3]]
// Output: 4
// 
// Solution:
// If without the requirement that the 2 numbers must be from 2 different
// arrays, then simply find the smallest first element and largest last element
// across all arrays and get their difference. With this requirement, it needs
// to keep track of the smallest 2 (min1 and min2) and largest 2 (max1 and
// max2) elements and their arrays' indice. In the end, if min1 and max1 are
// from the same array, return max1 - min2 or max2 - min1, whichever is larger.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int s = arrays.size();
        int min1 = 10000, min2 = 10000;
        int max1 = -10000, max2 = -10000;
        int mini1, mini2, maxi1, maxi2;
        
        for (int i = 0; i < s; i++) {
            // New smallest found
            if (arrays[i].front() < min1) {
                min2 = min1;
                mini2 = mini1;
                min1 = arrays[i].front();
                mini1 = i;
            // New second smallest found
            } else if (arrays[i].front() < min2) {
                min2 = arrays[i].front();
                mini2 = i;
            }
            
            // New largest found
            if (arrays[i].back() > max1) {
                max2 = max1;
                maxi2 = maxi1;
                max1 = arrays[i].back();
                maxi1 = i;
            // New second largest found
            } else if (arrays[i].back() > max2) {
                max2 = arrays[i].back();
                maxi2 = i;
            }
        }
        
        return mini1 != maxi1 ? max1 - min1 : max(max1 - min2, max2 - min1);
    }
};