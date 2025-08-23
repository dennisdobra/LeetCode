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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* origin = head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowPrev = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // lista are un singur element
        if (slow == origin) {
            if (slow->next != nullptr) {
                return slow->next;
            }
            return nullptr;
        }

        removeNode(slowPrev);

        return origin;
    }

    void removeNode(ListNode* prevNode) {
        if (prevNode->next != nullptr) {
            prevNode->next = prevNode->next->next;
        }
    }
};