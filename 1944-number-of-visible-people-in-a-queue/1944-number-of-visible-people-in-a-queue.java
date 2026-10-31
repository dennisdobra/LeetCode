class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int[] ans = new int[heights.length];

        // monotonically increasing stack
        Deque<Integer> monotonic = new ArrayDeque<>();

        // iterate from last person in queue to the first person in queue
        for (int i = heights.length - 1; i >= 0; i--) {
            int count = 0;

            // while the person in front is smaller it means the current person can see it
            while (!monotonic.isEmpty() && heights[i] > monotonic.peek()) {
                count++;
                monotonic.pop();
            }

            // if the stack is not empty it means there is a person in front
            // past which the current one can't see
            if (!monotonic.isEmpty()) {
                count++;
            }

            monotonic.push(heights[i]);
            ans[i] = count;
        }

        return ans;
    }
}
