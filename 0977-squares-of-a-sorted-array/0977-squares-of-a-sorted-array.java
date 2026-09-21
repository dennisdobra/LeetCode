class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] ans = new int[nums.length];
        int index = 0;
        
        // 2 pointers: one for the last negative and one for the first positive
        int pos = -1;
        int neg = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= 0) {
                pos = i;
                neg = i - 1;
                break;
            }
        }

        // edge case: all negative
        if (pos == -1) {
            neg = nums.length - 1;
            pos = nums.length;
        }

        // increase pos and decrease neg
        while (neg >= 0 && pos < nums.length) {
            if (Math.abs(nums[neg]) < nums[pos]) {
                ans[index++] = nums[neg] * nums[neg];
                neg--;
            } else {
                ans[index++] = nums[pos] * nums[pos];
                pos++;
            }
        }

        while (neg >= 0) {
            ans[index++] = nums[neg] * nums[neg];
            neg--;
        }

        while (pos < nums.length) {
            ans[index++] = nums[pos] * nums[pos];
            pos++;
        }

        return ans;
    }
}