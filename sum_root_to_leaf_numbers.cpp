// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int sum(TreeNode *r, int s)
    {
        int t  = r->val + s * 10;

        if (r->left == NULL && r->right == NULL) return t;
        return (r->left == NULL ? 0 : sum(r->left, t)) + (r->right == NULL ? 0 : sum(r->right, t));
    }

    int sumNumbers(TreeNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        return sum(root, 0);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
