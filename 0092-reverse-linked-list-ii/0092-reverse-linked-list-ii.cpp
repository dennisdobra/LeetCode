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
        if (left == right) return head;

        ListNode* prevLeft = nullptr;    // save the node at position left - 1
        ListNode* nextRight = nullptr;   // save the node at position right + 1

        ListNode* curr = head;
        for (int i = 1; i <= right; i++) {
            if (i == left - 1) {
                prevLeft = curr;
            } else if (i == right) {
                nextRight = curr->next;
            }

            curr = curr->next;
        }

        // save the first node to be sorted to connect it in the end
        ListNode* dummy = (prevLeft == nullptr ? head : prevLeft->next);

        // reverse nodes between prevLeft->next and right
        curr = dummy;
        ListNode* prev = nullptr;
        while (curr != nextRight) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // connect to the original list
        if (prevLeft != nullptr) {
            prevLeft->next = prev;
        } else {
            dummy->next = nextRight;
            return prev;
        }
        
        dummy->next = nextRight;
        return head;
    }
};