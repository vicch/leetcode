// Problem:
// Design a data structure that supports the following two operations:
// void addWord(word)
// bool search(word)
// search() can search a literal word or a regular expression string containing
// only letters a-z or ".". A "."" means it can represent any one letter. Assume
// that all words are consist of lowercase letters
// 
// Example:
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// 
// Solution:
// Define a trie where every node has an array of pointers to all possible next
// letters. Each node has a marker indicating if a words ends on this letter.
// When a "." is met, iterate all existing next letters.

#include <iostream>
#include <cstring>

using namespace std;

struct Letter {
    Letter* next[26];
    bool end;
    Letter() {
        memset(next, 0, sizeof(Letter*) * 26);
        end = false;
    }
};

class WordDictionary {
    Letter* init;

public:
    WordDictionary() {
        init = new Letter;
    }
    
    void addWord(string word) {
        Letter* l = init;

        for (char c: word) {
            // Add next letter
            if (!l->next[c - 'a'])
                l->next[c - 'a'] = new Letter;
            l = l->next[c - 'a'];
        }

        // Mark end of word
        l->end = true;

        return;
    }
    
    bool search(string word) {
        return searchSub(word.c_str(), init);
    }

    bool searchSub(const char* word, Letter* root) {
        // Word should end here
        if (*word == '\0')
            return root->end;

        if (*word == '.') {
            // Iterate available next letters
            for (int i = 0; i < 26; i++)
                if (root->next[i] && searchSub(word + 1, root->next[i]))
                    return true;
            return false;
        }

        // Check next letter
        root = root->next[*word - 'a'];
        return !root ? false : searchSub(word + 1, root);
    }
};