/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL) return p == q;
        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return isSymmetric(root, root);
    }
};
