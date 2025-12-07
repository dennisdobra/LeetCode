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
        unordered_set<int> seen;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            if (seen.contains(curr->val)) {
                // delete the node curr
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
            
            seen.insert(curr->val);

            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};