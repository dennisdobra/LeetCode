class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // find the longest subarray with unique elements

        unordered_set<int> unique;

        int score = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (unique.contains(nums[right])) {
                unique.erase(nums[left]);
                left++;
            }

            unique.insert(nums[right]);

            // here we have a valid subarray (only unique values);
            int curr_sum = 0;
            for (int num : unique) {
                curr_sum += num;
            }

            score = max(score, curr_sum);

        }

        return score;
    }
};