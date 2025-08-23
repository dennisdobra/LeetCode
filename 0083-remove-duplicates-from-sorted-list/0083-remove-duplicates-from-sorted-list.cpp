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
        ListNode* origin = head;

        unordered_set<int> seen;

        ListNode* curr = head;
        ListNode* currPrev = head;
        while (curr != nullptr) {
            if (seen.contains(curr->val)) {
                currPrev->next = curr->next;
            } else {
                seen.insert(curr->val);
                currPrev = curr;
            }
            
            curr = curr->next;
        }

        return origin;
    }
};