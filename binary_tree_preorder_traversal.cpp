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
    // recursive
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        
        if (root)
        {
            preorder.push_back(root->val);
            vector<int> l = preorderTraversal(root->left);
            preorder.insert(preorder.end(), l.begin(), l.end());
            vector<int> r = preorderTraversal(root->right);
            preorder.insert(preorder.end(), r.begin(), r.end());
        }
        
        return preorder;
    }

    // iterative
    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> preorder;
        if (!root) return preorder;
        
        stack<TreeNode*> to_traverse;
        to_traverse.push(root);
        
        while (!to_traverse.empty()) 
        {
            TreeNode *node = to_traverse.top();
            to_traverse.pop();
            preorder.push_back(node->val);
            if (node->right) to_traverse.push(node->right);
            if (node->left) to_traverse.push(node->left);
        }
        
        return preorder;
    }
};