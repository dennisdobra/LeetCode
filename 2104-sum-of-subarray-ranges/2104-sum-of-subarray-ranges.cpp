class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> stack;

        long long ans = 0;

        // for each number nums[i] find the number of subbarays for which it is the minimum
        for (int i = 0; i <= nums.size(); i++) {
            while (!stack.empty() && (i == nums.size() || nums[i] <= nums[stack.top()])) {
                int mid = stack.top();
                stack.pop();

                // compute the indices of the subarray where mid is the min element
                int leftBoundary = !stack.empty() ? stack.top() : -1;
                int rightBoundary = i;

                // count is the number of subarrays where mid is the smallest element
                int count = (mid - leftBoundary) * (rightBoundary - mid);

                ans -= count * (long long) nums[mid];
            }

            stack.push(i);
        }

        stack.pop();

        // for each number nums[i] find the number of subbarays for which it is the maximum
        for (int i = 0; i <= nums.size(); i++) {
            while (!stack.empty() && (i == nums.size() || nums[i] >= nums[stack.top()])) {
                int mid = stack.top();
                stack.pop();

                // compute the indices of the subarray where mid is the max element
                int leftBoundary = !stack.empty() ? stack.top() : -1;
                int rightBoundary = i;

                int count = (mid - leftBoundary) * (rightBoundary - mid);

                ans += count * (long long) nums[mid];
            }
            
            stack.push(i);
        }

        return ans;
    }
};