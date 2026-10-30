class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> minimum = new ArrayDeque<>();
        Deque<Integer> maximum = new ArrayDeque<>();

        int left = 0;
        int ans = 0;
        for (int right = 0; right < nums.length; right++) {
            while (!minimum.isEmpty() && nums[right] < minimum.peekLast()) {
                minimum.pollLast();
            }

            while (!maximum.isEmpty() && nums[right] > maximum.peekLast()) {
                maximum.pollLast();
            }

            minimum.offerLast(nums[right]);
            maximum.offerLast(nums[right]);

            // make sure the window is still valid
            while (maximum.peekFirst() - minimum.peekFirst() > limit) {
                if (nums[left] == maximum.peekFirst()) {
                    maximum.pollFirst();
                }
                
                else if (nums[left] == minimum.peekFirst()) {
                    minimum.pollFirst();
                }

                left++;
            }

            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}