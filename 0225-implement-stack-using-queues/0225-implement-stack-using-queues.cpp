class MyStack {
public:
    queue<int> myQueue;
    queue<int> aux;

    MyStack() {}
    
    void push(int x) {
        while (!myQueue.empty()) {
            int val = myQueue.front();
            aux.push(val);
            myQueue.pop();
        }

        myQueue.push(x);

        while (!aux.empty()) {
            int val = aux.front();
            myQueue.push(val);
            aux.pop();
        }
    }
    
    int pop() {
        int val = myQueue.front();
        myQueue.pop();
        return val;
    }
    
    int top() {
        if (!myQueue.empty()) return myQueue.front();

        return -1;
    }
    
    bool empty() {
        return myQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */