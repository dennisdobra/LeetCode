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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = nullptr;
        ListNode* curr;

        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* head1 = list1;
        ListNode* head2 = list2;
        if (head1->val < head2->val) {
            newHead = head1;
            head1 = head1->next;
        } else {
            newHead = head2;
            head2 = head2->next;
        }
        curr = newHead;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        if (head1 != nullptr) {
            curr->next = head1;
        } else {
            curr->next = head2;
        }

        return newHead;
    }
};