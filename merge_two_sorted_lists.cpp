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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = new ListNode(0), *curr;
        
        for (curr = head; l1 != NULL && l2 != NULL; curr = curr->next)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
        }
        
        if (l1 == NULL)
        {
            curr->next = l2;
        }
        else
        {
            curr->next = l1;
        }
        
        return head->next;
    }
};
