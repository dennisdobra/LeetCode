class MovingAverage {
    Queue<Integer> queue;
    int size;
    double sum;

    public MovingAverage(int size) {
        queue = new ArrayDeque<>();
        this.size = size;
        sum = 0;
    }
    
    public double next(int val) {
        queue.offer(val);
        sum += val;

        if (queue.size() > size) {
            sum -= queue.peek();
            queue.poll();
        }
        
        return (double)(sum / Math.min(size, queue.size()));
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */