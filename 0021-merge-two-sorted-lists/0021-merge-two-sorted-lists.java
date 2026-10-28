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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        ListNode dummy1 = list1;
        ListNode dummy2 = list2;
        ListNode head = null;
        ListNode res = null;

        while (dummy1 != null && dummy2 != null) {
            if (head == null) {
                if (dummy1.val < dummy2.val) {
                    head = dummy1;
                    dummy1 = dummy1.next;
                } else {
                    head = dummy2;
                    dummy2 = dummy2.next;
                }

                res = head;
                continue;
            }

            if (dummy1.val < dummy2.val) {
                head.next = dummy1;
                dummy1 = dummy1.next;
            } else {
                head.next = dummy2;
                dummy2 = dummy2.next;
            }

            head = head.next;
        }

        if (dummy1 != null) {
            head.next = dummy1;
        } else {
            head.next = dummy2;
        }

        return res;
    }
}