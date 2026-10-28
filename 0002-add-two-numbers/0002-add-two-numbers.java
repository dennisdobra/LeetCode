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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(-1);
        ListNode head = result;

        int carry = 0;
        while (l1 != null || l2 != null) {
            int val1 = l1 == null ? 0 : l1.val;
            int val2 = l2 == null ? 0 : l2.val;

            int sum = val1 + val2 + carry;

            carry = sum / 10;
            sum = sum % 10;

            ListNode node = new ListNode(sum);

            result.next = node;
            result = result.next;

            l1 = l1 == null ? l1 : l1.next;
            l2 = l2 == null ? l2 : l2.next;
        }

        // we can have 9 + 1 => without considering this carry we will
        // have the result [0] instead of [0, 1] because both lists
        // are now null and the loop ends
        if (carry != 0) {
            result.next = new ListNode(carry);
        }

        return head.next;
    }
}