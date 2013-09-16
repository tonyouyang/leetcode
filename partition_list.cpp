// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

#include <vector>
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
    ListNode *partition(ListNode *head, int x)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return head;

        ListNode *partitioned_head = head;

        for (ListNode *lt_x_tail = NULL, *gt_x_tail = NULL; head != NULL; head = head->next)
        {
            if (head->val < x)
            {
                if (gt_x_tail == NULL)
                {
                    lt_x_tail = head;
                }
                else
                {
                    gt_x_tail->next = head->next;

                    if (lt_x_tail != NULL)
                    {
                        head->next = lt_x_tail->next;
                        lt_x_tail->next = head;
                        lt_x_tail = head;
                    }
                    else
                    {
                        head->next = partitioned_head;
                        lt_x_tail = head;
                        partitioned_head = head;
                    }

                    head = gt_x_tail;
                }
            }
            else
            {
                gt_x_tail = head;
            }
        }

        return partitioned_head;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
