class Solution {
    public int validSubarrays(int[] nums) {
        // for every element find the next smaller element

        // monotonically increasing stack
        Deque<Integer> monotonic = new ArrayDeque<>();

        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            while (!monotonic.isEmpty() && nums[i] < nums[monotonic.peek()]) {
                ans += i - monotonic.peek();
                monotonic.pop();
            }

            monotonic.push(i);
        }

        // for the remaining elements in the stack there is no next smaller element
        // so all subarray starting with them till the end are valid
        while (!monotonic.isEmpty()) {
            ans += nums.length - monotonic.peek();
            monotonic.pop();
        }

        return ans;
    }
}