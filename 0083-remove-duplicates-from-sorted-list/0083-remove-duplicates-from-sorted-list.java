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
    public ListNode deleteDuplicates(ListNode head) {
        Set<Integer> seen = new HashSet<>();
        
        ListNode curr = head;
        ListNode prev = null;
        while (curr != null) {
            if (seen.contains(curr.val)) {
                // skip the current element
                prev.next = curr.next;

                curr = curr.next;
                continue;
            }
            
            seen.add(curr.val);
            prev = curr;
            curr = curr.next;
        }
        
        return head;
    }
}