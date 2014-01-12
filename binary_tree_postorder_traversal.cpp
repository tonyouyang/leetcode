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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
        if (!root) return postorder;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *prev = NULL;
        
        while (!s.empty())
        {
            TreeNode *curr = s.top();
            if (!prev || prev->left == curr || prev->right == curr)
            {
                if (curr->left) s.push(curr->left);
                else if (curr->right) s.push(curr->right);
            }
            else if (curr->left == prev)
            {
                if (curr->right) s.push(curr->right);
            }
            else
            {
                postorder.push_back(curr->val);
                s.pop();
            }
            prev = curr;
        }
        
        return postorder;
    }

    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> preorder;
        if (!root) return preorder;
        
        stack<TreeNode*> to_traverse;
        to_traverse.push(root);
        
        while (!to_traverse.empty()) 
        {
            TreeNode *node = to_traverse.top();
            to_traverse.pop();
            preorder.push_back(node->val);
            if (node->left) to_traverse.push(node->left);
            if (node->right) to_traverse.push(node->right);
        }
        
        reverse(preorder.begin(), preorder.end());
        
        return preorder;
    }
};