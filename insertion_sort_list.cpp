#include <iostream>
using namespace std;


// zero-based array insertion sort
// for (int i = 1; i < a.size(); ++i)
// {
//     int x = a[i];
//     for (int j = i; j > 0 && a[j - 1] > x; j--) a[j] = a[j - 1];
//     a[j] = x;
// }

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *sorted = NULL;

        while (head)
        {
            ListNode *curr = head;
            head = head->next;

            if (sorted == NULL || curr->val < sorted->val)
            {
                curr->next = sorted;
                sorted = curr;
            }
            else
            {
                for (ListNode *pos = sorted; pos; pos = pos->next)
                {
                    if (pos->next == NULL || pos->next->val > curr->val)
                    {
                        curr->next = pos->next;
                        pos->next = curr;
                        break;
                    }
                }
            }
        }

        return sorted;
    }

    // faster version by using pointer to ListNode pointer
    ListNode *insertionSortList2(ListNode *head)
    {
        if (!head || !head->next) return head;

        ListNode *sorted = NULL;

        while (head)
        {
            ListNode *curr = head;
            ListNode **ppos = &sorted;
            head = head->next;

            while (!(*ppos == NULL || curr->val < (*ppos)->val)) ppos = &((*ppos)->next);
            curr->next = *ppos;
            *ppos = curr; 
        }

        return sorted;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}