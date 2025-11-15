class MinStack {
public:
    stack<pair<int,int>> stack;
    int minVal;

    MinStack() {}
    
    void push(int val) {
        if (stack.empty()) {
            minVal = val;
            stack.push({val, minVal});
        } else {
            if (val < minVal) minVal = val;

            stack.push({val, minVal});
        }
    }
    
    void pop() {
        stack.pop();
        if (stack.empty()) {
            minVal = INT_MAX;
        } else {
            minVal = stack.top().second;
        }
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */