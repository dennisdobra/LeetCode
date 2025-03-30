class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr = 0;
        double ans = 0;

        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }

        curr = curr / k;
        ans = curr;

        for (int i = k; i < nums.size(); i++) {
            curr *= k;
            curr += nums[i] - nums[i - k];
            curr /= k;

            ans = max(ans, curr);
        }

        return ans;
    }
};