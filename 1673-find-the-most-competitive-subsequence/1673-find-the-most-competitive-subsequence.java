class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        // we want a subsequence of size k => we can erase n - k elements
        int canErase = nums.length - k;

        // monotonically increasing stack
        Deque<Integer> monotonic = new ArrayDeque<>();

        for (int num : nums) {
            while (!monotonic.isEmpty() && num < monotonic.peek() && canErase > 0) {
                monotonic.pop();
                canErase--;
            }

            if (monotonic.size() < k) {
                monotonic.push(num);
            } else {
                // this case is only for elements that are larger than the top of the stack
                // because if the current elem num is smaller than the top of the stack and
                // canErase > 0 => automatically monotonic.size() < k
                canErase--;
            }
        }

        int[] ans = new int[monotonic.size()];
        for (int i = monotonic.size() - 1; i >= 0; i--) {
            ans[i] = monotonic.pop();
        } 

        return ans;
    }
}