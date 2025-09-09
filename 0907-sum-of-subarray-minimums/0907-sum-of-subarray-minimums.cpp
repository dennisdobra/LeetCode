class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stack;

        long sumOfMinimums = 0;
        int MOD = 1000000007;

        for (int i = 0; i <= arr.size(); i++) {
            // when i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining
            // elements in the stack should now be popped out.
            while (!stack.empty() && (i == arr.size() || arr[stack.top()] >= arr[i])) {
                 int mid = stack.top();
                 stack.pop();

                 // compute the indices for the subarray where mid is min element
                 int leftBoundary = !stack.empty() ? stack.top() : -1;
                 int rightBoundary = i;

                 // compute the contribution of mid
                 long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

                 sumOfMinimums += (arr[mid] * count) % MOD;
                 sumOfMinimums %= MOD;
            }

            stack.push(i);
        }

        return (int) sumOfMinimums;
    }
};