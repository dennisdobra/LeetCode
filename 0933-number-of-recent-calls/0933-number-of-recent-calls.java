class RecentCounter {
    int recentRequests;
    Queue<Integer> queue;

    public RecentCounter() {
        queue = new ArrayDeque<>();
    }
    
    public int ping(int t) {
        while (!queue.isEmpty() && queue.peek() + 3000 < t) {
            queue.poll();
        }

        queue.offer(t);

        return queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */