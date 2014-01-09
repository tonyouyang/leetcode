#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        
        ListNode *slow = head->next, *fast = head->next->next;
        
        while (fast != NULL && fast->next != NULL)
        {
            if (slow == fast)
            {
                if (slow == head) return head;
                
                ListNode *p = slow, *q = head;
                while (p != q)
                {
                    p = p->next;
                    q = q->next;
                }

                return p;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(0);
    ListNode *d = new ListNode(-4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    cout << solution.detectCycle(a)->val << endl;
    return 0;
}