/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        // edge cases
        if (head == null || head.next == null) {
            return head;
        }

        // save a pointer to what we will return
        ListNode result = head.next;

        // save a pointer to connect the pair
        ListNode prev = null;

        while (head != null && head.next != null) {
            // nodes of the current pair
            ListNode first = head;
            ListNode second = head.next;

            // connect the current pair to the previous one
            if (prev != null) {
                prev.next = second;
            }

            // update prev pointer
            prev = first;

            // save a pointer to the next pair
            ListNode next = second.next;

            // swap the current pair
            second.next = first;
            first.next = next;

            // move on to the next pair
            head = next;
        }

        return result;
    }
}