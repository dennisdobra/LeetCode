class Solution {
    public int minStartValue(int[] nums) {
        // compute prefixSum and find the minimum value
        int total = 0;
        int min = Integer.MAX_VALUE;

        for (int num : nums) {
            total += num;

            if (total < min) {
                min = total;
            }
        }

        return Math.max(1, 1 - min);
    }
}