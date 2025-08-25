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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel = new ListNode(0, head);

        ListNode* curr = head;
        ListNode* prev = sentinel;

        while (curr != nullptr) {
            if (curr->val == val) {
                // delete curr
                prev->next = curr->next;
            } else {
                prev = curr;
            }

            curr = curr->next;
        }

        return sentinel->next;
    }
};