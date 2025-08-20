class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> digit_sum;
        //sum_of_digits -> number

        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (digit_sum.contains(sum(nums[i]))) {
                ans = max(ans, nums[i] + digit_sum[sum(nums[i])]);

                digit_sum[sum(nums[i])] = max(nums[i], digit_sum[sum(nums[i])]);
            } else {
                 digit_sum[sum(nums[i])] = nums[i];
            }

           
        }

        return ans;
    }

    int sum(int n) {
        int sum = 0;

        while (n != 0) {
            sum += n % 10;
            n = n / 10;
        }

        return sum;
    }
};