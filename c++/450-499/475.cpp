// Problem:
// Given positions of houses and heaters on a horizontal line, find out minimum
// radius of heaters so that all houses could be covered by those heaters.
// - Numbers of houses and heaters are non-negative and will not exceed 25000.
// - Positions of houses and heaters are non-negative and will not exceed 10^9.
// - As long as a house is in the heaters' warm radius range, it can be warmed.
// 
// Example:
// Input: [1,2,3,4],[1,4]
// Output: 1
// 
// Solution:
// Calculate the distance from a house to its left and right heater, the less
// one is the minimum radius needed for this house. Then find the largest
// minimum radius of all houses.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int rad, mrad;
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        mrad = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {
            // Let j be the heater on the right side of the house
            // If the house is after the rightmost heater, j is the last heater
            while (houses[i] > heaters[j] && j < heaters.size() - 1)
                j++;
            
            // If the house is before the first heater or after the last heater
            if ((j == 0 && houses[i] <= heaters[j]) || (j == heaters.size() - 1 && houses[i] >= heaters[j]))
                rad = abs(houses[i] - heaters[j]);
            // If the house is between 2 heaters
            else
                rad = min(houses[i] - heaters[j - 1], heaters[j] - houses[i]);
            
            if (mrad < rad)
                mrad = rad;
        }
        
        return mrad;
    }
};