// Problem:
// Suppose we abstract a file system by string in the following manner, string
// "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
// represents:
// 
// dir
//     subdir1
//         file1.ext
//         subsubdir1
//     subdir2
//         subsubdir2
//             file2.ext
//             
// We are interested in finding the longest (number of characters) absolute
// path to a file within our file system. For example, in the second example
// above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and
// its length is 32 (not including the double quotes). Given a string
// representing the file system in the above format, return the length of the
// longest absolute path to file in the abstracted file system. If there is no
// file in the system, return 0.
// - The name of a file contains at least a "." and an extension.
// - The name of a directory or sub-directory will not contain a ".".
// 
// Solution:
// Directory hierarchy can be considered as tree, which leads to a recursive
// approach. The longest path since current dir = length of current dir name +
// the longest of each sub-dir's longest path. Need to check the number of tabs
// at the beginning of each line to know when going down lower level starts and 
// going back to current level.

#include <stdio.h>

int lengthLongestPath(char* input);

int main()
{
    printf("%d\n", lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
    printf("%d\n", lengthLongestPath("dir\n    file.txt"));

    return 0;
}

/********** Solution **********/

char* lengthLongestPathSub(char* str, int dep, int* len);

int lengthLongestPath(char* input)
{
    int len, maxlen;

    maxlen = 0;

    // There could be several root files or directories
    while (input) {
        input = lengthLongestPathSub(input, 0, &len);
        if (maxlen < len)
            maxlen = len;
    }
    

    return maxlen;
}

char* lengthLongestPathSub(char* str, int dep, int* len)
{
    *len = 0;

    if (*str == '\0')
        return 0;

    int isfile, subdep, sublen, sublenmax;

    // Get length of current root
    for (isfile = 0; *str != '\n' && *str != '\0'; str++, (*len)++)
        if (*str == '.')
            isfile = 1;
    
    // Move to the start of next line
    if (*str == '\n')
        str++;

    if (isfile)
        return str;

    sublenmax = 0;

    while (*str) {
        // Check depth of current line
        for (subdep = 0; *str == '\t'; str++, subdep++);

        // Recursive if current line is lower level
        if (subdep == dep + 1) {
            str = lengthLongestPathSub(str, subdep, &sublen);
            if (sublen > sublenmax)
                sublenmax = sublen;

        // Break if current line is back to upper level
        } else {
            // Return to start of tabs
            str -= subdep;
            break;
        }
    }

    // If no file exists under this directory
    if (sublenmax == 0)
        *len = 0;
    else
        // Plus 1 for directory delimeter
        *len += sublenmax + 1;

    return str;
}