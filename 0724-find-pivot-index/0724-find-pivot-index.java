class Solution {
    public int pivotIndex(int[] nums) {
        int[] prefix = new int[nums.length];

        prefix[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < nums.length; i++) {
            int leftSum = i == 0 ? 0 : prefix[i - 1];
            int rightSum = i == nums.length - 1 ? 0 : prefix[nums.length - 1] - prefix[i];

            if (leftSum == rightSum) return i;
        }

        return -1;
    }
}