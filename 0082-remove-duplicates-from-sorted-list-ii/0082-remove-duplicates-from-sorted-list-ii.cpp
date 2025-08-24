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
    ListNode* deleteDuplicates(ListNode* head) {
        // sentinel node
        ListNode* sentinel = new ListNode(0, head);

        // the node before the sublist to delete
        ListNode* prev = sentinel;

        ListNode* curr = head;
        while (curr != nullptr) {
            // check if it is a beginning of duplicates
            if (curr->next != nullptr && curr->val == curr->next->val) {
                // move till the end of duplicates
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // skip all duplicates
                prev->next = curr->next;
            } else {
                // we can move prev
                prev = prev->next;
            }

            curr = curr->next;
        }

        return sentinel->next;
    }
};