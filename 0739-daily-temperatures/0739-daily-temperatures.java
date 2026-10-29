class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> monotonic = new ArrayDeque<>();

        int[] ans = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; i++) {
            // see for which days the current one is the next warmer
            while (!monotonic.isEmpty() && temperatures[i] > temperatures[monotonic.peek()]) {
                ans[monotonic.peek()] = i - monotonic.peek();
                monotonic.pop();
            }

            monotonic.push(i);
        }

        return ans;
    }
}