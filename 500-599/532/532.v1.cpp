// Problem:
// Given an array of integers and an integer k, find the number of unique k-
// diff pairs in the array. A k-diff pair is defined as an integer pair (i, j),
// where i and j are numbers in the array and their absolute difference is k.
// 
// Example:
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2 ((1, 3) and (3, 5))
// 
// Solution:
// Use 2 maps to mark number n when n + k or n - k already exists, therefore
// when n appears, a k-diff pair is found. If k == 0, only one map is used.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 0)
            return 0;
        
        int count;
        unordered_map<int,int> c1; // n + k exist, look for n
        unordered_map<int,int> c2; // n - k exist, look for n
        
        count = 0;
        for (int n: nums) {
            switch (c1[n]) {
                // n + k exist
                case 1:
                    count++;
                    c1[n] = 2;
                    break;
                // Aleardy counted
                case 2:
                    break;
                default:
                    if (k > 0) {
                        // Look for n + k
                        if (!c2[n + k])
                            c2[n + k] = 1;
                    } else {
                        // Look for n, when k == 0
                        c1[n] = 1;
                    }
                    break;
            }
            
            // When k == 0, only use map c1
            if (k == 0)
                continue;
                
            switch (c2[n]) {
                case 1:
                    count++;
                    c2[n] = 2;
                case 2:
                    break;
                default:
                    if (!c1[n - k])
                        c1[n - k] = 1;
                    break;
            }
        }
        
        return count;
    }
};