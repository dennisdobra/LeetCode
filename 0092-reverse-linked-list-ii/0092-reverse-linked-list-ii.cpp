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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // save a pointer to the head for the result
        ListNode* result = head;

        // set a pointer to the node at position left and one at left - 1
        int count = 1;
        ListNode* leftBound = head;
        ListNode* prevLeft = nullptr;
        while (count < left) {
            prevLeft = leftBound;
            leftBound = leftBound->next;

            count++;
        }

        // prevLeft = the node before the one at position left
        // leftBound = the node at position left


        // reverse from left to right
        ListNode* prevNode = nullptr;
        ListNode* curr = leftBound;

        while (count <= right) {
            ListNode* nextNode = curr->next;

            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;

            count++;
        }

        // connect to the left side
        if (prevLeft != nullptr) {
            // maybe left is the first node
            prevLeft->next = prevNode;
        } else {
            result = prevNode;
        }

        // connect to the right side (to the next node or to nullptr)
        leftBound->next = curr;

        return result;
    }
};