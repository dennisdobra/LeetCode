class Solution {
    public long subArrayRanges(int[] nums) {
        // for every possible subarray we have to add to the final answer the difference
        // between the largest value and the smallest value in that subarray. The idea is
        // to iterate twice all the elements. In the first iteration, for each element,
        // check for how many subarrays the current element is the largest and add the
        // product to the total

        // monotonic stack
        Deque<Integer> monotonic = new ArrayDeque<>();

        long total = 0;

        // first iteration
        for (int i = 0; i <= nums.length; i++) {
            while (!monotonic.isEmpty() && (i == nums.length || nums[i] > nums[monotonic.peek()])) {
                // we found a larger number than the one at the top of the stack so
                // we have to calculate the contribution for the previous largest
                int mid = monotonic.pop();

                int leftBoundary = !monotonic.isEmpty() ? monotonic.peek() : -1;
                int rightBoundary = i;

                long count = (mid - leftBoundary) * (rightBoundary - mid);
                total += nums[mid] * count;
            }

            if (i < nums.length) {
                monotonic.push(i);
            }
        }

        // second iteration
        for (int i = 0; i <= nums.length; i++) {
            while (!monotonic.isEmpty() && (i == nums.length || nums[i] < nums[monotonic.peek()])) {
                // we found a smaller element than the one at the top of the stack so
                // we have to calculate the contribution for the previous smallest
                int mid = monotonic.pop();

                int leftBoundary = !monotonic.isEmpty() ? monotonic.peek() : -1;
                int rightBoundary = i;

                long count = (mid - leftBoundary) * (rightBoundary - mid);
                total -= nums[mid] * count;
            }

            if (i < nums.length) {
                monotonic.push(i);
            }
        }

        return total;
    }
}