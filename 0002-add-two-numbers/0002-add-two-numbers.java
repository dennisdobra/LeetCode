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
        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carry;

            ListNode node = new ListNode(sum % 10);
            result.next = node;
            result = result.next;

            carry = sum / 10;
            
            l1 = l1.next;
            l2 = l2.next;
        }

        if (l1 == null) {
            while (l2 != null) {
                l2.val = l2.val + carry;
                carry = l2.val / 10;
                l2.val = l2.val % 10;
                result.next = l2;
                result = result.next;
                l2 = l2.next;
            }

            if (carry != 0) {
                ListNode node = new ListNode(carry);
                result.next = node;
            }
        } else {
            while (l1 != null) {
                l1.val = l1.val + carry;
                carry = l1.val / 10;
                l1.val = l1.val % 10;
                result.next = l1;
                result = result.next;
                l1 = l1.next;
            }

            if (carry != 0) {
                ListNode node = new ListNode(carry);
                result.next = node;
            }
        }

        return head.next;
    }
}