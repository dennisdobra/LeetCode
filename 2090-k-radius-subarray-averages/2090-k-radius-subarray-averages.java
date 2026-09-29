class Solution {
    public int[] getAverages(int[] nums, int k) {
        int[] kRadiusAvg = new int[nums.length];
        Arrays.fill(kRadiusAvg, -1);

        if (nums.length <= 2 * k) return kRadiusAvg;

        long[] prefixSum = new long[nums.length];
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        for (int i = k; i < nums.length - k; i++) {
            long sum = prefixSum[i + k] - prefixSum[i - k] + nums[i - k];
            int avg = (int)(sum / (2 * k + 1));

            kRadiusAvg[i] = avg;
        }

        return kRadiusAvg;
    }
}