class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minSum = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum < minSum) {
                minSum = sum;
            }
        }
        
        return max(1, 1 - minSum);
    }
};