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
    ListNode* swapPairs(ListNode* head) {
        // edge case: list has 0 or 1 nodes
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // save a pointer to what we will return
        ListNode* result = head->next;

        // save a pointer to connect the pairs
        ListNode* prev = nullptr;

        while (head != nullptr && head->next != nullptr) {
            // connect to next pair
            if (prev != nullptr) {
                prev->next = head->next;
            }

            prev = head;

            // save a pointer to next pair
            ListNode* nextNode = head->next->next;

            // swap the current pair
            head->next->next = head;

            // treat the case where the list has odd number of nodes
            head->next = nextNode;

            // move to the next pair
            head = nextNode;
        }

        return result;
    }
};