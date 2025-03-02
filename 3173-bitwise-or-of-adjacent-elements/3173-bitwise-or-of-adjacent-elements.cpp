class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        vector<int> answer(nums.size() - 1);

        for (int i = 0; i < nums.size() - 1; i++) {
            answer[i] = nums[i] | nums[i + 1];
        }

        return answer;
    }
};