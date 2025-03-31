class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix.back());
        }

        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                // check the sum of the subarray starting at index i and ending at index j
                if (prefix[j] - prefix[i] + nums[i] == k) {
                    answer++;
                }
            }
        }

        return answer;
    }
};