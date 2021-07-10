// Problem:
// Design an algorithm to serialize and deserialize a binary search tree.
// There is no restriction on how the serialization/deserialization algorithm
// should work. Just ensure that a binary search tree can be serialized to a
// string and this string can be deserialized to the original tree structure.
// The encoded string should be as compact as possible.
// 
// Solution:
// Represent the tree in-order as a[b][c], where b and c are child nodes and
// represented as a[b][c] recursively. Running a char pointer as recursively
// rebuilding the tree.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/********** Solution **********/

class Codec {
public:

    string serialize(TreeNode* root) {
        return serializesub(root);
    }

    string serializesub(TreeNode* root) {
        string str = "";

        if (root) {
            str += to_string(root->val);
            if (root->left || root->right) {
                str += "[" + serializesub(root->left) + "]";
                str += "[" + serializesub(root->right) + "]";
            }
        }

        // cout << str << endl;

        return str;
    }

    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        char* start = &(data[0]);
        return deserializesub(&start);
    }

    TreeNode* deserializesub(char** str) {
        // cout << *str << endl;

        if (**str == '\0')
            return NULL;

        if (**str == '[')
            *str += 1;

        if (**str == ']') {
            *str += 1;
            return NULL;
        }

        TreeNode* root = new TreeNode(str2int(str));

        if (**str == ']') {
            *str += 1;
            return root;
        }

        root->left  = deserializesub(str);
        root->right = deserializesub(str);
        
        while (**str == ']')
            *str += 1;

        return root;
    }

    int str2int(char** str) {
        int i = 0;
        while (**str >= '0' && **str <= '9') {
            i *= 10;
            i += **str - '0';
            *str += 1;
        }
        return i;
    }
};