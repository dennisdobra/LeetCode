class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        // index of next closest smaller element
        vector<int> nextSmaller(nums.size(), nums.size());

        stack<int> stack;

        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[i] < nums[stack.top()]) {
                // found an element smaller than the one at the top of the stack
                nextSmaller[stack.top()] = i;
                stack.pop();
            }

            // push the index of teh current element on the stack
            stack.push(i);
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nextSmaller[i] - i;
        }

        return count;
    }
};