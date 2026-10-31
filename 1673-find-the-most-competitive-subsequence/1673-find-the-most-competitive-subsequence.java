class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        // monotonically increasing stack
        Deque<Integer> monotonic = new ArrayDeque<>();

        // we want a subsequence of size k => we can erase n - k elements
        int canErase = nums.length - k;

        for (int num : nums) {
            while (!monotonic.isEmpty() && num < monotonic.peek() && canErase > 0) {
                monotonic.pop();         
                canErase--;       
            }

            monotonic.push(num);
        }

        while (monotonic.size() > k) {
            monotonic.pop();
        }

        int[] ans = new int[monotonic.size()];
        for (int i = monotonic.size() - 1; i >= 0; i--) {
            ans[i] = monotonic.peek();
            monotonic.pop();
        }

        return ans;
    }
}