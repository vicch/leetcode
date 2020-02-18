// Problem:
// One way to serialize a binary tree is to use pre-order traversal. When
// encounter a non-null node, record the node's value. If it is a null node,
// record using a sentinel value such as #. For example:
//       9
//     /   \
//    3     2
//   / \   / \
//  4   1 #   6
// / \ / \   / \
// # # # #   # #
// can be serialized to "9,3,4,#,#,1,#,#,2,#,6,#,#". Given a string of comma
// separated values, verify whether it is a correct preorder traversal
// serialization of a binary tree. Find an algorithm without reconstructing the
// tree. Assume that the input format is always valid, for example it could
// never contain two consecutive commas.
// 
// Example:
// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
// 
// Solution:
// Each non-null node in the tree allows for 2 null child nodes, so by keeping
// track of the number of null nodes available at any time, the tree can be
// validated.

class Solution {
public:
    bool isValidSerialization(string s) {
        int size, state, sharp, i;

        // Number of null node starts as 1
        // State == 1 means it's reading a number, could be more than 1 digit
        for (size = s.size(), state = i = 0, sharp = 1; i < size - 1; i++) {
            if (s[i] == ',')
                state = 0;
            else if (s[i] == '#')
                sharp--;
            else if (state == 0) 
                state = 1, sharp++;

            // If null nodes become unavailable before the end of string, it's
            // invalid
            if (sharp <= 0)
                return false;
        }

        // The last node must be null and there must be exactly 1 null node
        // available
        return sharp == 1 && s[i] == '#';
    }
};