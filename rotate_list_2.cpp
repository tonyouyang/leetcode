// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;

        ListNode *h, *c;
        int len;

        for (len = 1, c = head; c->next != NULL; c = c->next, ++len);
        c->next = head;
        for (int i = 0, j = len - k % len; i < j; c = c->next, ++i);
        h = c->next;
        c->next = NULL;

        return h;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *a0 = new ListNode(1), *a1 = new ListNode(2);
    ListNode *b0 = new ListNode(1), *b1 = new ListNode(2), *b2 = new ListNode(3);

    a0->next = a1;
    b0->next = b1; b1->next = b2;

    for (ListNode *n = solution.rotateRight(NULL, 1); n != NULL; n = n->next) cout << n->val <<  " "; cout << endl;
    for (ListNode *n = solution.rotateRight(a0, 1); n != NULL; n = n->next) cout << n->val <<  " "; cout << endl;
    for (ListNode *n = solution.rotateRight(b0, 1); n != NULL; n = n->next) cout << n->val <<  " "; cout << endl;

    return 0;
}
// notice when k > length of list
