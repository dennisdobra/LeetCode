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
        // reverse the second half of the list
        // A -> B -> C -> D -> E -> F => A -> B -> C -> F -> E -> D

        ListNode* slow = head;
        ListNode* fast = head;

        int size = 0;
        ListNode* slowPrev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
            size += 2;
        }

        cout << size << endl;

        // reverse the list starting at slow
        ListNode* reverseHead = slow;
        ListNode* prev = nullptr;
        while (reverseHead != nullptr) {
            ListNode* nextNode = reverseHead->next;
            reverseHead->next = prev;
            prev = reverseHead;
            reverseHead = nextNode;
        }

        // connect the first half of the list to the second half
        slowPrev->next = prev;

        // create a n / 2 gap between nodes
        slow = head;
        fast = head;
        for (int i = 0; i < size / 2; i++) {
            fast = fast->next;
        }

        // check every pair and find max twin sum
        int maxTwinSum = 0;
        while (fast != nullptr) {
            if (slow->val + fast->val > maxTwinSum) {
                maxTwinSum = slow->val + fast->val;
            }

            slow = slow->next;
            fast = fast->next;
        }

        return maxTwinSum;
    }
};