#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeSortedList(ListNode *p, ListNode *q)
    {
        ListNode *head, *tail;

        if (p->val < q->val) {
            head = p;
            p = p->next;
        } else {
            head = q;
            q = q->next;
        }
        tail = head;

        while (p != NULL and q != NULL)
        {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }

        for ( ; p; p = p->next) {tail->next = p; tail = tail->next;}
        for ( ; q; q = q->next) {tail->next = q; tail = tail->next;}

        return head;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        int n = 0;

        for (ListNode *p = head; p; p = p->next) n++;
        ListNode *half = head, *prev = head;
        n >>= 1;
        
        for ( ; n > 0; n--)
        {
            half = half->next;
            if (n == 1) prev->next = NULL;
            prev = half;
        }

        ListNode *p = sortList(head), *q = sortList(half);

        return mergeSortedList(p, q);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    ListNode *a0 = new ListNode(1), *a1 = new ListNode(2), *a2 = new ListNode(3), *a3 = new ListNode(4), *a4 = new ListNode(5), *a5 = new ListNode(6), *a6 = new ListNode(7);
    a0->next = a1; a1->next = a2; a2->next = a3; a3->next = a4; a4->next = a5; a5->next = a6;
    
    ListNode *p = solution.sortList(a0);
    for ( ; p; p = p->next) cout << p->val << " "; cout << endl;

    return 0;
}