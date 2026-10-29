
// Time Complexity: O(1) * O(N) = O(N), N = nr of calls of next method
// Space Complexity: O(size), the queue can hold at most size elements
class MovingAverage {
    Queue<Integer> queue = new ArrayDeque<>();
    double sum = 0;
    int size;

    public MovingAverage(int size) {
        this.size = size;
    }
    
    public double next(int val) {
        queue.offer(val);
        sum += val;

        if (queue.size() > size) {
            sum -= queue.peek();
            queue.poll();
        }
        
        return sum / queue.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */