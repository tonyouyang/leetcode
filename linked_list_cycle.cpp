#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        
        for (ListNode *slow = head, *fast = head->next; 
            fast != NULL && fast->next != NULL; 
            slow = slow->next, fast = fast->next->next)
        {
                if (slow == fast) return true;
        }
        
        return false;
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
    cout << solution.hasCycle(a) << endl;
    return 0;
}