class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> deque = new ArrayDeque<>();
        int[] ans = new int[nums.length - k + 1];

        for (int i = 0; i < nums.length; i++) {
            // maintain monotonic decreasing.
            // all elements in the deque smaller than the current one
            // have no chance of being the maximum, so get rid of them
            while (!deque.isEmpty() && nums[i] > nums[deque.peekLast()]) {
                deque.pollLast();
            }

            deque.offerLast(i);

            // queue[0] is the index of the maximum element.
            // if queue[0] + k == i, then it is outside the window
            if (deque.peekFirst() + k == i) {
                deque.pollFirst();
            }

            if (i >= k - 1) {
                ans[i - k + 1] = nums[deque.peekFirst()];
            }
        }

        return ans;
    }
}