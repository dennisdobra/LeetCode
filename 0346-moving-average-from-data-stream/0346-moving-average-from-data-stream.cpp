class MovingAverage {
public:
    queue<int> queue;
    int window_size;

    int curr_size = 0;
    double sum = 0;

    MovingAverage(int size) {
        window_size = size;
    }
    
    double next(int val) {
        while (queue.size() >= window_size) {
            sum -= queue.front();
            queue.pop();
            curr_size--;
        }

        queue.push(val);
        sum += val;
        curr_size++;
        return sum / curr_size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */