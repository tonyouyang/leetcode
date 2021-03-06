#include <iostream>
using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution
{
public:
    TreeLinkNode *getLeftMostChild(TreeLinkNode *root)
    {
        if (root == NULL) return NULL;
        TreeLinkNode *ret = root;

        while (true)
        {
            if (ret->left != NULL)
            {
                ret = ret->left;
                return ret;
            }
            else if (ret->right != NULL)
            {
                ret = ret->right;
                return ret;
            }
            else if (ret->next != NULL)
            {
                ret = ret->next;
            }
            else
            {
                break;
            }
        }

        return NULL;
    }

    void connect(TreeLinkNode *root)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;

        connect(root->left);
        connect(root->right);
        for (TreeLinkNode *l = root->left, *r = root->right; l != NULL && r != NULL; )
        {
            TreeLinkNode *lcopy = l, *rcopy = r;
            l = getLeftMostChild(l);
            r = getLeftMostChild(r);
            if (lcopy != NULL) while (lcopy->next != NULL) lcopy = lcopy->next;
            lcopy->next = rcopy;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeLinkNode *a = new TreeLinkNode(3);
    TreeLinkNode *b = new TreeLinkNode(9);
    TreeLinkNode *c = new TreeLinkNode(20);
    TreeLinkNode *d = new TreeLinkNode(15);
    TreeLinkNode *e = new TreeLinkNode(17);

    a->left = b; a->right = c;
    c->left = d; c->right = e;

    solution.connect(a);

    return 0;
}
