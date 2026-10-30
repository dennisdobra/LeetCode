class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int n = pushed.length;

        Deque<Integer> stack = new ArrayDeque<>();

        int j = 0;
        for (int i = 0; i < n; i++) {
            stack.push(pushed[i]);

            while (!stack.isEmpty() && popped[j] == stack.peek()) {
                stack.pop();
                j++;
            }
        }

        while (!stack.isEmpty()) {
            if (stack.peek() != popped[j]) {
                return false;
            }

            stack.pop();
            j++;
        }

        return true;
    }
}
