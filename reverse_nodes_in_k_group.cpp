/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        if (k <= 1) return head;
        
        ListNode *rhead = head, *rtail = head, *ret = NULL, *current, *scout, *prev_tail = NULL;
        int count;
        
        for (count = 1, scout = head, current = head->next; scout != NULL; )
        {
            if (count == k)
            {
                for ( ; count > 1; --count)
                {
                    rtail->next = current->next;
                    current->next = rhead;
                    rhead = current;
                    current = rtail->next;
                }
                if (ret == NULL) ret = rhead;
                if (prev_tail != NULL) prev_tail->next = rhead;
                prev_tail = rtail;
                scout = current;
                rhead = current;
                rtail = current;
                if (current != NULL) current = current->next;
            }
            else
            {
                scout = scout->next;
                count++;
            }
        }
        
        return ret == NULL ? head : ret;
    }
};
