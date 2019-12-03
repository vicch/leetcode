// Problem:
// Given a List of words, return the words that can be typed using letters of
// alphabet on only one row's of American keyboard like the image below.
// 
// Example:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
// 
// Solution:
// Map letters to row number. Iterate each character of a word and break when
// any character is on a different row than the first character.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char,int> letters;

public:
    Solution() {
        letters['a'] = 2, letters['A'] = 2;
        letters['b'] = 3, letters['B'] = 3;
        letters['c'] = 3, letters['C'] = 3;
        letters['d'] = 2, letters['D'] = 2;
        letters['e'] = 1, letters['E'] = 1;
        letters['f'] = 2, letters['F'] = 2;
        letters['g'] = 2, letters['G'] = 2;
        letters['h'] = 2, letters['H'] = 2;
        letters['i'] = 1, letters['I'] = 1;
        letters['j'] = 2, letters['J'] = 2;
        letters['k'] = 2, letters['K'] = 2;
        letters['l'] = 2, letters['L'] = 2;
        letters['m'] = 3, letters['M'] = 3;
        letters['n'] = 3, letters['N'] = 3;
        letters['o'] = 1, letters['O'] = 1;
        letters['p'] = 1, letters['P'] = 1;
        letters['q'] = 1, letters['Q'] = 1;
        letters['r'] = 1, letters['R'] = 1;
        letters['s'] = 2, letters['S'] = 2;
        letters['t'] = 1, letters['T'] = 1;
        letters['u'] = 1, letters['U'] = 1;
        letters['v'] = 3, letters['V'] = 3;
        letters['w'] = 1, letters['W'] = 1;
        letters['x'] = 3, letters['X'] = 3;
        letters['y'] = 1, letters['Y'] = 1;
        letters['z'] = 3, letters['Z'] = 3;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> answers;
        int row;
        bool pass;

        for (string word: words) {
            row = letters[word[0]];
            pass = false;

            for (char c: word)
                if (letters[c] != row) {
                    pass = true;
                    break;
                }

            if (!pass)
                answers.push_back(word);
        }

        return answers;
    }
};