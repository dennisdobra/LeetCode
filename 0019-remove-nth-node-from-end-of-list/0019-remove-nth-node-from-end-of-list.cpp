/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // create a gap of n node between 2 pointers
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        ListNode* slowPrev = nullptr;
        while (fast != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // the node which should be deleted is slow
        if (slowPrev == nullptr) {
            return slow->next;
        }

        slowPrev->next = slowPrev->next->next;

        return head;
    }
};