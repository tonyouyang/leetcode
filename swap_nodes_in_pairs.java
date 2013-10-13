/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == null) return null;
        
        ListNode prev = new ListNode(0), guard = prev, left = head, right = head.next;
        prev.next = head;
        
        while (left != null && right != null) {
            prev.next = right;
            left.next = right.next;
            right.next = left;
            prev = left;
            left = left.next;
            right = left == null ? null : left.next;
        }
        
        return guard.next;
    }
}

// prev -> left -> right -> next