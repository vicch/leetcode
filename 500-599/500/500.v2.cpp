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
#include <cctype>

using namespace std;

#define LETTER(c) (tolower(c) - 'a')

class Solution {
    int letters[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> answers;
        int row;
        bool pass;

        for (string word: words) {
            row = letters[LETTER(word[0])];
            pass = false;

            for (char c: word)
                if (letters[LETTER(c)] != row) {
                    pass = true;
                    break;
                }

            if (!pass)
                answers.push_back(word);
        }

        return answers;
    }
};