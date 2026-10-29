class RecentCounter {
    int recentRequests;
    Queue<Integer> queue;

    public RecentCounter() {
        recentRequests = 0;
        queue = new ArrayDeque<>();
    }
    
    public int ping(int t) {
        queue.offer(t);

        while (queue.peek() < t - 3000) {
            queue.poll();
        }

        return queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */