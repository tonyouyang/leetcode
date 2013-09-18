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

        ListNode *h = head, *ck, *c;
        int n;

        for (n = 1, c = head; c->next != NULL && n <= k; c = c->next, ++n);
        if (k >= n) k %= n;
        if (k == 0) return head;

        for (ck = head, c = head; c->next != NULL; c = c->next)
        {
            if (k == 0)
                ck = ck->next;
            else
                k--;
        }

        if (k <= 0)
        {
            h = ck->next;
            ck->next = c->next;
            c->next = head;
        }

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
