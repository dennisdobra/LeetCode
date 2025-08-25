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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        /* compute size of each group */
        int group = 1;

        // group idx -> group size
        unordered_map<int,int> groupSizes;

        ListNode* dummy = head;
        while (dummy != nullptr) {
            int currSize = 0;
            for (int i = 0; i < group && dummy != nullptr; i++) {
                dummy = dummy->next;
                currSize++;
            }

            groupSizes[group] = currSize;
            group++;
        }

        // for (auto& pair : groupSizes) {
        //     cout << "group " << pair.first << " -> " << pair.second << " elements" << endl;
        // }



        group = 1;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* prevGroup = nullptr;

        while (curr != nullptr) {
            if (groupSizes[group] % 2 != 0) {
                // skip this group
                for (int i = 0; i < group && curr != nullptr; i++) {
                    prev = curr;
                    prevGroup = curr;
                    curr = curr->next;
                }
            } else {
                // reverse this group
                ListNode* first = curr;

                ListNode* before = nullptr;
                for (int i = 0; i < group && curr != nullptr; i++) {
                    ListNode* nextNode = curr->next;

                    curr->next = before;
                    before = curr;
                    curr = nextNode;
                }

                // connect to previous group
                prevGroup->next = before;

                // connect to next group
                first->next = curr;

                // update the pointer to prevGroup
                prevGroup = first;
            }

            group++;
        }

        return head;
    }
};