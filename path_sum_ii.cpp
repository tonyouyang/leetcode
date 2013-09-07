// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int> > paths;

    void tryPathSum(TreeNode *root, int sum, vector<int> &path)
    {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL)
        {
            if (sum == root->val)
            {
                vector<int> p(path);
                p.push_back(sum);
                paths.push_back(p);
            }
        }
        else
        {
            path.push_back(root->val);
            if (root->left != NULL)
            {
                tryPathSum(root->left, sum - root->val, path);
            }
            if (root->right != NULL)
            {
                tryPathSum(root->right, sum - root->val, path);
            }
            path.pop_back();
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> p;

        paths.clear(); // important!
        tryPathSum(root, sum, p);
        return paths;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *root = new TreeNode(1);
    vector<vector<int> > paths = solution.pathSum(root, 0);
    cout << paths.size() << endl;
    return 0;
}
