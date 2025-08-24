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
    ListNode* deleteMiddle(ListNode* head) {
        // list has 0 or 1 elements
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowPrev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the middle now
        slowPrev->next = slowPrev->next->next;

        return dummy;
    }
};