// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
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
    vector<TreeNode *> generateTrees(const int start, const int end)
    {
        vector<TreeNode *> ts;

        if (start > end)
        {
            ts.push_back(NULL);
        }
        else
        {
            for (int root_val = start; root_val <= end; ++root_val)
            {
                vector<TreeNode *> lts = generateTrees(start, root_val - 1);
                vector<TreeNode *> rts = generateTrees(root_val + 1, end);
                for (int i = 0, p = lts.size(); i < p; ++i)
                    for (int j = 0, q = rts.size(); j < q; ++j)
                    {
                        TreeNode *root = new TreeNode(root_val);
                        root->left = lts[i];
                        root->right = rts[j];
                        ts.push_back(root);
                    }
            }
        }

        return ts;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTrees(1, n);
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int n;

	cin >> n;
	cout << solution.generateTrees(n).size() << endl;
	
    return 0;
}
