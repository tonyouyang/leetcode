// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

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
    // flatten and return the tail of linked list
    TreeNode *f(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL) return root;

        TreeNode *ltail = NULL, *rtail = NULL;

        if (root->right != NULL) rtail = f(root->right);
        if (root->left != NULL)
        {
            ltail = f(root->left);
            if (root->right != NULL) ltail->right = root->right; // (left list) -> (right list)
            root->right = root->left; // r -> (left list)
        }

        root->left = NULL;
        return rtail == NULL ? ltail : rtail;
    }

    void flatten(TreeNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        f(root);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *a0 = new TreeNode(0), *a1 = new TreeNode(1), *a2 = new TreeNode(2);
    TreeNode *b0 = new TreeNode(0), *b1 = new TreeNode(1), *b2 = new TreeNode(2);
    TreeNode *c0 = new TreeNode(0), *c1 = new TreeNode(1), *c2 = new TreeNode(2);

    a0->left = a1;
    a0->right = a2;

    b0->left = b1;
    b1->left = b2;

    c0->right = c1;
    c1->right = c2;

    solution.flatten(a0);
    solution.flatten(b0);
    solution.flatten(c0);

    return 0;
}
