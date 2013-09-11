// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *g(ListNode *&head, const int start, const int end)
    {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode *leftTree = g(head, start, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = leftTree;
        root->right = g(head, mid + 1, end);

        return root;
    }

    TreeNode *f(ListNode *head, int n)
    {
        return g(head, 0, n - 1);
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;

        for (ListNode *curr = head; curr != NULL; ++len)
        	curr = curr->next;

        return f(head, len);
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	ListNode *head = new ListNode(0);

	solution.sortedListToBST(head);

    return 0;
}
