// Problem:
// There are n bulbs that are initially off. First turn on all the bulbs. Then,
// turn off every second bulb. On the third round, toggle every third bulb
// (turning on if it's off or turning off if it's on). For the ith round,
// toggle every i bulb. For the nth round, only toggle the last bulb. Find how
// many bulbs are on after n rounds.
// 
// Solution:
// If n has odd number of factors, it's on after n rounds. Only square numbers
// have odd number of factors, therefore the answer is sqrt(n).

#include <iostream>
#include <math>

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};