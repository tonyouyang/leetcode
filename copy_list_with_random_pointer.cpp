/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) return NULL;
        
        unordered_map<RandomListNode *, RandomListNode *> m;
        
        for (RandomListNode *curr = head; curr != NULL; curr = curr->next) m[curr] = new RandomListNode(curr->label);
        for (RandomListNode *curr = head; curr != NULL; curr = curr->next)
        {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
        }
        
        return m[head];
    }
};
