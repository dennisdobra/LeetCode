class Solution {
    public int sumSubarrayMins(int[] arr) {
        // monotonically decreasing stack
        Deque<Integer> monotonic = new ArrayDeque<>();

        int MOD = 1000000007;
        int total = 0;

        for (int i = 0; i <= arr.length; i++) {
            // for every element arr[i], I have to multiply it by the number of subbarays
            // in which arr[i] is the minimum element and add it to the total
            while (!monotonic.isEmpty() && (i == arr.length || arr[i] <= arr[monotonic.peek()])) {
                // we found an element smaller than the one at the top of the stack =>
                // we have to compute the contribution for the one at the top of the stack
                int mid = monotonic.pop();

                int leftBoundary = !monotonic.isEmpty() ? monotonic.peek() : -1;
                int rightBoundary = i;

                long count = ((mid - leftBoundary) * (rightBoundary - mid)) % MOD;

                total += (arr[mid] * count) % MOD;
                total %= MOD;
            }

            monotonic.push(i);
        }

        return total;
    }
}