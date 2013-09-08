// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
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
    // threshold_depth < 0 indicates NO threshold depth
    int f(TreeNode *root, int threshold_depth)
    {
        if (root->left == NULL && root->right == NULL) return 1;
        if (threshold_depth == 1) return threshold_depth; // pruning

        int td = threshold_depth - 1, ld, rd, d;
        if (root->left != NULL)
        {
            ld = f(root->left, td);
            if (td < 0 || td > ld) td = ld; // update threshold depth before traversing right sub-tree
        }
        if (root->right != NULL)
        {
            rd = f(root->right, td);
            if (td < 0 || td > rd) td = rd;
        }

        return td + 1;
    }

    int minDepth(TreeNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        return f(root, -1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *a0 = new TreeNode(0), *a1 = new TreeNode(1), *a2 = new TreeNode(2);
    TreeNode *b0 = new TreeNode(0), *b1 = new TreeNode(1), *b2 = new TreeNode(2);
    TreeNode *c0 = new TreeNode(3), *c1 = new TreeNode(9), *c2 = new TreeNode(20), *c3 = new TreeNode(15), *c4 = new TreeNode(7);

    a0->right = a1;
    a1->right = a2;

    b0->left = b1;
    b0->right = b2;

    c0->left = c1;
    c0->right = c2;
    c2->left = c3;
    c2->right = c4;

    cout << solution.minDepth(NULL) << endl; // 0
    cout << solution.minDepth(a0) << endl; // 3
    cout << solution.minDepth(b0) << endl; // 2
    cout << solution.minDepth(c0) << endl; // 2

    return 0;
}
