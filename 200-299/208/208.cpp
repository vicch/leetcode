// Problem:
// Implement a trie with insert(), search(), and startsWith() methods. Assume
// that all inputs are consist of lowercase letters a-z.
// 
// Solution:
// Each letter is represented by a node, each node has 26 next nodes.
// 
// Lesson:
// Struct members need explicit initialization to avoid trash value. Write
// struct as a class and initialize members in contructor.

#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
    bool end;
    Node* next[26];

    Node() {
        end = false;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* ptr = root;

        for (char c: word) {
            // Create next node if not exist
            if (ptr->next[c - 'a'] == NULL)
                ptr->next[c - 'a'] = new Node();

            ptr = ptr->next[c - 'a'];
        }

        // Mark end of word
        ptr->end = true;

        return;
    }
    
    bool search(string word) {
        Node* ptr = root;

        for (char c: word) {
            if (ptr == NULL)
                return false;
            ptr = ptr->next[c - 'a'];
        }

        return ptr != NULL && ptr->end == true;
    }
    
    bool startsWith(string prefix) {
        Node* ptr = root;

        for (char c: prefix) {
            if (ptr == NULL)
                return false;
            ptr = ptr->next[c - 'a'];
        }

        return ptr != NULL;
    }
};