// class MyQueue {
//     Deque<Integer> stack = new ArrayDeque<>();
//     Deque<Integer> helper = new ArrayDeque<>();

//     public MyQueue() {
        
//     }
    
//     public void push(int x) {
//         stack.push(x);
//     }
    
//     // Time Complexity: O(N)
//     public int pop() {
//         while (stack.size() > 1) {
//             int elem = stack.pop();
//             helper.push(elem);
//         }

//         int first = stack.pop();

//         while (!helper.isEmpty()) {
//             int elem = helper.pop();
//             stack.push(elem);
//         }

//         return first;
//     }
    
//     // Time Complexity: O(N)
//     public int peek() {
//         int first = -1;

//         while (!stack.isEmpty()) {
//             first = stack.peek();

//             int elem = stack.pop();
//             helper.push(elem);
//         }

//         while (!helper.isEmpty()) {
//             int elem = helper.pop();
//             stack.push(elem);
//         }

//         return first;
//     }
    
//     public boolean empty() {
//         return stack.isEmpty();
//     }
// }

class MyQueue {
    Deque<Integer> stack1 = new ArrayDeque<>();
    Deque<Integer> stack2 = new ArrayDeque<>();
    int first;

    public MyQueue() {
        
    }
    
    public void push(int x) {
        if (stack1.isEmpty()) {
            first = x;
        }

        stack1.push(x);
    }
    
    public int pop() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        return stack2.pop();
    }
    
    public int peek() {
        if (!stack2.isEmpty()) {
            return stack2.peek();
        }

        return first;
    }
    
    public boolean empty() {
        return stack1.isEmpty() && stack2.isEmpty();
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