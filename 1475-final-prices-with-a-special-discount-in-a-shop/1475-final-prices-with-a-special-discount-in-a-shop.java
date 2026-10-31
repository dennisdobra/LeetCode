class Solution {
    public int[] finalPrices(int[] prices) {
        Deque<Integer> monotonic = new ArrayDeque<>();

        int[] ans = new int[prices.length];
        for (int i = 0; i < prices.length; i++) {
            while (!monotonic.isEmpty() && prices[i] <= prices[monotonic.peek()]) {
                ans[monotonic.peek()] = prices[monotonic.peek()] - prices[i];
                monotonic.pop();
            }

            monotonic.push(i);
        }

        while (!monotonic.isEmpty()) {
            ans[monotonic.peek()] = prices[monotonic.pop()];
        }

        return ans;
    }
}