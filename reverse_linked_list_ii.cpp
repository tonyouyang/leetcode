// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ? m ? n ? length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m == n) return head;

        ListNode *origin_head = head, *before_reversed_tail = NULL;

        // skip list from head to (m - 1)-th element
        for (int i = 1; i < m; ++i)
        {
        	before_reversed_tail = head;
            head = head->next;
        }

        ListNode *reversed_head = head;
        ListNode *reversed_tail = reversed_head;
        ListNode *to_reverse_head = reversed_tail->next;
        for (int reversed_length = 1; m + reversed_length - 1 < n; ++reversed_length)
        {
            reversed_tail->next = to_reverse_head->next;
            to_reverse_head->next = reversed_head;
            reversed_head = to_reverse_head;
            to_reverse_head = reversed_tail->next;
        }

        if (before_reversed_tail != NULL) before_reversed_tail->next = reversed_head;

        return m > 1 ? origin_head : reversed_head;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *a0 = new ListNode(1), *b0 = new ListNode(2), *c0 = new ListNode(3), *d0 = new ListNode(4), *e0 = new ListNode(5);
    ListNode *a1 = new ListNode(1), *b1 = new ListNode(2), *c1 = new ListNode(3), *d1 = new ListNode(4), *e1 = new ListNode(5);
    ListNode *a2 = new ListNode(1), *b2 = new ListNode(2), *c2 = new ListNode(3), *d2 = new ListNode(4), *e2 = new ListNode(5);
    ListNode *a3 = new ListNode(1), *b3 = new ListNode(2), *c3 = new ListNode(3), *d3 = new ListNode(4), *e3 = new ListNode(5);
    ListNode *a4 = new ListNode(1);

    a0->next = b0; b0->next = c0; c0->next = d0; d0->next = e0;
    a1->next = b1; b1->next = c1; c1->next = d1; d1->next = e1;
    a2->next = b2; b2->next = c2; c2->next = d2; d2->next = e2;
    a3->next = b3; b3->next = c3; c3->next = d3; d3->next = e3;

    for (ListNode *r0 = solution.reverseBetween(a0, 1, 3); r0 != NULL; r0 = r0->next) cout << r0->val << " "; cout << endl; // 3 2 1 4 5
    for (ListNode *r1 = solution.reverseBetween(a1, 3, 5); r1 != NULL; r1 = r1->next) cout << r1->val << " "; cout << endl; // 1 2 5 4 3
    for (ListNode *r2 = solution.reverseBetween(a2, 1, 5); r2 != NULL; r2 = r2->next) cout << r2->val << " "; cout << endl; // 5 4 3 2 1
    for (ListNode *r3 = solution.reverseBetween(a3, 2, 4); r3 != NULL; r3 = r3->next) cout << r3->val << " "; cout << endl; // 1 4 3 2 5
    for (ListNode *r4 = solution.reverseBetween(a4, 1, 1); r4 != NULL; r4 = r4->next) cout << r4->val << " "; cout << endl; // 1

    return 0;
}
