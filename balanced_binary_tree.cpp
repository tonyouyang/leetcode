// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true; // IMPORTANT! return TRUE by definition!

        if (root->left == NULL && root->right == NULL)
        {
            root->val = 1;
            return true;
        }

        bool lb = true, rb = true;
        int ld = 0, rd = 0;

        if (root->left != NULL)
        {
            lb = isBalanced(root->left);
            ld = root->left->val;
        }
        if (root->right != NULL && lb)
        {
            rb = isBalanced(root->right);
            rd = root->right->val;
        }
        root->val = max(ld, rd) + 1;

        return lb && rb && abs(ld - rd) <= 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *a0 = new TreeNode(0), *a1 = new TreeNode(1), *a2 = new TreeNode(2);

    a0->right = a1;
    a1->right = a2;

    cout << solution.isBalanced(a0) << endl;

    return 0;
}
