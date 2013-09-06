// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include <iostream>
#include <stdio.h>
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
    // int listToNum(ListNode *list)
    // {
    //     int r = 0, d = 1;

    //     while (list != NULL)
    //     {
    //         r += (list->val) * d;
    //         d *= 10;
    //         list = list->next;
    //     }

    //     return r;
    // }

    // ListNode *numToList(int x)
    // {
    //     if (!x)
    //     {
    //         return new struct ListNode(x);
    //     }
    //     else
    //     {
    //         ListNode *head = NULL, *curr = NULL;

    //         while (x)
    //         {
    //             if (curr != NULL)
    //             {
    //                 curr->next = new struct ListNode(x % 10);
    //                 curr = curr->next;
    //             }
    //             else
    //             {
    //                 curr = new struct ListNode(x % 10);
    //                 head = curr;
    //             }
    //             x /= 10;
    //         }

    //         curr = NULL;

    //         return head;
    //     }
    // }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL, *curr = NULL;
        int m = 0, n;

        while (l1 != NULL || l2 != NULL || m > 0)
        {
            n = m;
            if (l1 != NULL)
            {
                n += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                n += l2->val;
                l2 = l2->next;
            }
            m = n / 10;
            n %= 10;

            if (curr != NULL)
            {
                curr->next = new struct ListNode(n);
                curr = curr->next;
            }
            else
            {
                curr = new struct ListNode(n);
                head = curr;
            }
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{
    // Solution solution;
    // int n1, n2;

    // cin >> n1 >> n2;
    // ListNode *l1 = solution.numToList(n1);
    // ListNode *l2 = solution.numToList(n2);
    // cout << solution.listToNum(solution.addTwoNumbers(l1, l2)) << endl;

    return 0;
}
