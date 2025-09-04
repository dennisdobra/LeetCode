class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        // deque because we also need to eremove from the right
        deque<int> queue;

        for (int i = 0; i < nums.size(); i++) {
            while (!queue.empty() && nums[i] > nums[queue.back()]) {
                // keep the queue in decreasing order
                queue.pop_back();
            }

            queue.push_back(i);

            // the maximum element is too far to stay in the queue
            if (queue.front() + k == i) {
                queue.pop_front();
            }

            if (i >= k - 1) {
                ans.push_back(nums[queue.front()]);
            }
        }

        return ans;
    }
};