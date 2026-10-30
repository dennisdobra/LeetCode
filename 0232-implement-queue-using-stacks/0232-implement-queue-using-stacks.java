class MyQueue {
    // push all elements in the stack
    // when we want the first elem from the queue push all of them to the second stack
    // push them back to first stack

    Deque<Integer> stack = new ArrayDeque<>();
    Deque<Integer> helper = new ArrayDeque<>();

    public MyQueue() {
        
    }
    
    public void push(int x) {
        stack.push(x);
    }
    
    public int pop() {
        while (stack.size() > 1) {
            int elem = stack.pop();
            helper.push(elem);
        }

        int first = stack.pop();

        while (!helper.isEmpty()) {
            int elem = helper.pop();
            stack.push(elem);
        }

        return first;
    }
    
    public int peek() {
        int first = -1;

        while (!stack.isEmpty()) {
            first = stack.peek();

            int elem = stack.pop();
            helper.push(elem);
        }

        while (!helper.isEmpty()) {
            int elem = helper.pop();
            stack.push(elem);
        }

        return first;
    }
    
    public boolean empty() {
        return stack.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */