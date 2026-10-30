class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stack = new ArrayDeque<>();

        int i = 0;
        for (int num : pushed) {
            stack.push(num);

            while (!stack.isEmpty() && popped[i] == stack.peek()) {
                stack.pop();
                i++;
            }
        }

        return i == popped.length;
    }
}