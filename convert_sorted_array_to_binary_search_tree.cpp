// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode *f(vector<int> &num, const int start, const int end)
    {
    	if (start > end) return NULL;

    	int mid = start + (end - start) / 2;
    	TreeNode *root = new TreeNode(num[mid]);
    	root->left = f(num, start, mid - 1);
    	root->right = f(num, mid + 1, end);

    	return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return f(num, 0, num.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int a[] = {1, 2, 3, 4, 5};
	vector<int> v(a, a + 5);

	// cout << v.size() << endl;
	solution.sortedArrayToBST(v);

    return 0;
}
