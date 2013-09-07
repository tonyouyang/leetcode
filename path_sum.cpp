// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool hasPathSum(TreeNode *root, int sum)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return false;

        bool flag = false;
        if (root->left == NULL && root->right == NULL) return sum == root->val;
        if (root->left != NULL) flag = flag || hasPathSum(root->left, sum - root->val);
        if (!flag && root->right != NULL) flag = flag || hasPathSum(root->right, sum - root->val);

        return flag;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
