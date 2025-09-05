class MyQueue {
public:
    std::stack<int> stack;
    std::stack<int> aux;

    MyQueue() {
        
    }
    
    void push(int x) {
        int val;

        // transfer everything from stack to aux
        while (!stack.empty()) {
            val = stack.top();

            aux.push(val);
            stack.pop();
        }

        // push the new element on top of stack
        stack.push(x);

        // pop and push every element from aux back to stack
        while (!aux.empty()) {
            val = aux.top();

            stack.push(val);
            aux.pop();
        }
    }
    
    int pop() {
        int val = stack.top();
        stack.pop();
        
        return val;
    }
    
    int peek() {
        return stack.top();
    }
    
    bool empty() {
        return stack.empty() ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */