#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;

        int n = 0;
        for (ListNode* curr = head; curr != NULL; curr = curr->next, n++);
        int m = n >> 1;

        ListNode *ahead = head, *bhead = head, *t;
        for (int i = 0; i < m; i++, bhead = bhead->next);
        if (n & 1) bhead = bhead->next;

        ListNode *rhead = bhead, *rtail = rhead, *urhead = rtail->next;
        while (urhead)
        {
            rtail->next = urhead->next;
            urhead->next = rhead;
            rhead = urhead;
            urhead = rtail->next;
        }
        bhead = rhead;

        while (ahead != NULL && bhead != NULL)
        {
            t = bhead->next;
            bhead->next = ahead->next;
            ahead->next = bhead;
            ahead = bhead->next;
            bhead = t;
        }
        if (ahead) ahead->next = NULL;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *a0 = new ListNode(1), *a1 = new ListNode(2), *a2 = new ListNode(3), *a3 = new ListNode(4), *a4 = new ListNode(5), *a5 = new ListNode(6), *a6 = new ListNode(7);
    a0->next = a1; a1->next = a2; a2->next = a3; a3->next = a4; a4->next = a5; a5->next = a6;
    solution.reorderList(a0);
    for (ListNode* p = a0; p != NULL; p = p->next) cout << p->val;
    cout << endl;
    return 0;
}