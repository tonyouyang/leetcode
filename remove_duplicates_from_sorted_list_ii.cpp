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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        
        ListNode *i = new ListNode(0), *ret = head;
        i->next = head;
        
        for (ListNode *k = i->next; i->next != NULL; )
        {
            int count = 0;
            while (k->next !=NULL)
            {
                if (k->next->val == i->next->val)
                {
                    ListNode *t = k->next;
                    k->next = k->next->next;
                    delete t;
                    count++;
                }
                else
                {
                    k = k->next;
                }
            }
            if (count > 0)
            {
                if (i->next == ret) ret = i->next->next;
                ListNode *t = i->next;
                i->next = i->next->next;
                delete t;
            }
            else
            {
                i = i->next;
            }
            k = i->next;
        }
        
        return ret;
    }
};
