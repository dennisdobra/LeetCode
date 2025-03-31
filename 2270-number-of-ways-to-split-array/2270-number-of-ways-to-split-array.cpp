class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int answer = 0;

        vector<long> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix.back());
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (prefix[i] >= prefix[nums.size() - 1] - prefix[i]) {
                answer++;
            }
        }

        return answer;
    }
};