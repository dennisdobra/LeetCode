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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // if (head->next->next == nullptr) {
        //     if (head->val != head->next->val) {
        //         return false;
        //     }

        //     return true;
        // }

        ListNode* slow = head;
        ListNode* fast = head;

        // find the middle
        ListNode* slowPrev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // check if list size if even or odd
        if (fast != nullptr) {
            slowPrev = slow;
            slow = slow->next;
        }

        // reverse the second half
        ListNode* prevNode = nullptr;
        while (slow != nullptr) {
            ListNode* nextNode = slow->next;

            slow->next = prevNode;
            prevNode = slow;
            slow = nextNode;
        }
        slowPrev->next = prevNode;

        cout << "reverse the second half: ";
        ListNode *it = head;
        while (it != nullptr) {
            cout << it->val << " ";
            it = it->next;
        }



        // check if it is palindrome
        ListNode* dummy = head;
        while (prevNode != nullptr) {
            if (dummy->val != prevNode->val) {
                return false;
            }

            dummy = dummy->next;
            prevNode = prevNode->next;
        }

        return true;
    }
};