class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg = INT_MIN;

        double firstSum = computeSum(nums, 0, k);
        double curr_avg = firstSum / k;
        if (curr_avg > max_avg) max_avg = curr_avg;

        for (int i = k; i < nums.size(); i++) {
            firstSum += nums[i];
            firstSum -= nums[i - k];

            curr_avg = firstSum / k;
            if (curr_avg > max_avg) max_avg = curr_avg;
        }

        return max_avg;
    }

    double computeSum(vector<int> arr, int left, int right) {
        double sum = 0;
        for (int i = left; i < right; i++) {
            sum += arr[i];
        }

        return sum;
    }
};