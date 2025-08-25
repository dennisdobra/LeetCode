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
    int pairSum(ListNode* head) {
        int ans = INT_MIN;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowPrev = head;

        // find the middle of the list and count how far it is
        int count = 0;
        while (fast != nullptr && fast->next != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }

        // now slow is at the middle of the list =>
        // we need to reverse the second half of the list (starting with slow)
        ListNode* curr = slow;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // connect to the first half
        slowPrev->next = prev;

        ListNode* first = head;
        ListNode* second = head;

        // create a n / 2 gap between the two pointers
        for (int i = 0; i < count; i++) {
            second = second->next;
        }

        while (second != nullptr) {
            if (first->val + second->val > ans) {
                ans = first->val + second->val;
            }

            first = first->next;
            second = second->next;
        }

        return ans;
    }
};