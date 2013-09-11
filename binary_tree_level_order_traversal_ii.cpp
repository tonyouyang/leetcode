// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree {3,9,20,#,#,15,7},

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:

// [
//   [15,7]
//   [9,20],
//   [3],
// ]

#include <vector>
#include <iostream>
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
    void f(TreeNode *root, const int d, vector<vector<int> > &v)
    {
        if (v.size() < d + 1)
        {
            vector<int> nv(1, root->val);
            v.insert(v.begin(), nv);
        }
        else
        {
            v[v.size() - d - 1].push_back(root->val);
        }

        if (root->left != NULL) f(root->left, d + 1, v);
        if (root->right != NULL) f(root->right, d + 1, v);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;

        if (root == NULL) return v;
        f(root, 0, v);
        return v;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *t0 = new TreeNode(0), *t1 = new TreeNode(1), *t2 = new TreeNode(2);

    t0->left = t1;
    t0->right = t2;

    vector<vector<int> > v = solution.levelOrderBottom(t0);
    for (int i = 0, p = v.size(); i < p; ++i)
    {
        for (int j = 0, q = v[i].size(); j < q;  ++j) cout << v[i][j] << " ";
        cout << endl;
    }

    return 0;
}
