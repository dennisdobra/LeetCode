// class MinStack_ {
//     Deque<int[]> stack;

//     public MinStack_() {
//         stack = new ArrayDeque<>();
//     }
    
//     public void push(int value) {
//         if (stack.isEmpty() || !stack.isEmpty() && value < stack.peek()[1]) {
//             stack.push(new int[]{value, value});
//         } else {
//             stack.push(new int[]{value, stack.peek()[1]});
//         }
//     }
    
//     public void pop() {
//         stack.pop();
//     }
    
//     public int top() {
//         return stack.peek()[0];
//     }
    
//     public int getMin() {
//         return stack.peek()[1];
//     }
// }

class MinStack {
    Deque<Integer> stack;
    Deque<Integer> minStack;

    public MinStack() {
        stack = new ArrayDeque<>();
        minStack = new ArrayDeque<>();
    }
    
    public void push(int value) {
        stack.push(value);

        // if the current value is a new low record it in minStack
        if (minStack.isEmpty() || value <= minStack.peek()) {
            minStack.push(value);
        }
    }
    
    public void pop() {
        if (stack.peek().equals(minStack.peek())) {
            minStack.pop();
        }

        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */