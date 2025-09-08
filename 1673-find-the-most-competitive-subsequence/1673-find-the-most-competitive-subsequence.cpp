class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> deque;

        // we can not drop more than nums.size() - k elements => the size of the result will be less than k
        int canDrop = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            while (!deque.empty() && nums[i] < deque.back() && canDrop > 0) {
                deque.pop_back();
                canDrop--;
            }

            deque.push_back(nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(deque.front());
            deque.pop_front();
        }
        return ans;
    }
};